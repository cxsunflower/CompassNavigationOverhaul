module.exports = function registerTests(h) {
  const {assert,fs,vm,MovieClip,TextField,QuestItem,context,pending,completed,failed,test,create,near,bottom,originalOrnamentFixture,assertDetailInsideOrnament,setup,shrinkable} = h;

test('original ornament bounds contain all generated content and survive reflow',()=>{
  for(const type of [1,6]) {
    const q=new QuestItem();originalOrnamentFixture(q);
    const description='I have been attacked by a group of people claiming to work for someone named Miraak. '.repeat(6);
    const objectives=[{text:'Travel to Solstheim',completed:false},{text:'Read Cultists Orders',completed:true}];
    q.SetQuestInfo(type,'A long miscellaneous quest title',description,true,objectives,0);
    const originalWidth=q.DescriptionTextField._width;
    const originalHeight=q.DescriptionTextField._height;
    assert.ok(q.detailBounds.outerRight-q.detailBounds.outerLeft>490);
    assert.ok(originalWidth<q.detailBounds.outerRight-q.detailBounds.outerLeft);
    assertDetailInsideOrnament(q);
    q.ReflowWidth(1.6);
    near(q.DescriptionTextField._width,originalWidth);
    near(q.DescriptionTextField._height,originalHeight);
    q.ReflowWidth(0.75);assertDetailInsideOrnament(q);
    q.ReflowWidth(1);assertDetailInsideOrnament(q);
    near(q.DescriptionTextField._width,originalWidth);
    q.SetQuestInfo(type,'Updated',description+' More details.',true,objectives,0);
    assertDetailInsideOrnament(q);
  }
});

test('unbreakable text and long translated divider remain inside local mask',()=>{
  MovieClip.linkages=new Set(['QuestObjectivesDivider','QuestObjectivePending']);
  const q=new QuestItem();originalOrnamentFixture(q);
  q.objectivesLabel='VERY LONG OBJECTIVES TRANSLATION THAT CANNOT FIT AT THE ORIGINAL SIZE';
  const description='M'.repeat(500),objective='N'.repeat(300);
  q.SetQuestInfo(1,'Title',description,true,[{text:objective}],0);
  assert.equal(q.DescriptionTextField.text,description);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.text,objective);
  assert.ok(q.DescriptionTextField.textWidth>q.DescriptionTextField._width);
  assert.equal(q.DescriptionTextField.wordWrap,true);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.wordWrap,true);
  assertDetailInsideOrnament(q);
  const baseSize=q.objectivesLabelSize;
  q.ReflowWidth(0.5);assertDetailInsideOrnament(q);
  assert.ok(q.ObjectivesHeader.Label.format.size<baseSize);
  q.ReflowWidth(1);assertDetailInsideOrnament(q);
  q.ReflowWidth(0.1);assertDetailInsideOrnament(q);
  assert.ok(q.DescriptionTextField._width>=48);
  q.ReflowWidth(Infinity);assertDetailInsideOrnament(q);
  q.ReflowWidth(1);assertDetailInsideOrnament(q);
  assert.equal(q.DescriptionTextField.text,description);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.text,objective);
  MovieClip.linkages=new Set();
});

test('local content mask leaves title artwork untouched under parent transforms',()=>{
  const root=new MovieClip(),parent=root.createEmptyMovieClip('Target');
  const q=new QuestItem();originalOrnamentFixture(q);parent.add('quest',q);
  q.SetQuestInfo(1,'Title','Description '.repeat(30),true,[pending,completed],0);
  parent._x=80;parent._y=50;parent._xscale=125;parent._yscale=80;parent._rotation=17;
  q._xscale=65;q._yscale=65;
  assert.equal(q.TitleBracket._parent,q.Title);
  assert.equal(q.TitleEndPiece._parent,q.Title);
  assert.equal(q.TitleTextField._parent,q.Title);
  assert.equal(q.DetailBody.mask,q.DetailContentMask);
  assertDetailInsideOrnament(q);
  q.ReflowWidth(0.75);assertDetailInsideOrnament(q);
  const mask=q.DetailContentMask.getBounds(q.DetailBox);
  const point={x:mask.xMin,y:mask.yMin};q.DetailBox.localToGlobal(point);q.DetailBox.globalToLocal(point);
  near(point.x,mask.xMin);near(point.y,mask.yMin);
});

test('original Header and Body share the animated Box transform and alpha',()=>{
  const root=new MovieClip(),target=root.createEmptyMovieClip('Target');
  const q=new QuestItem();originalOrnamentFixture(q);target.add('quest',q);
  q.SetQuestInfo(6,'Miscellaneous','A journal description',true,[pending],0);
  const header=q.Title,box=q.DetailBox,body=q.DetailBody;
  assert.equal(header,box.Header);
  assert.equal(q.TitleTextField._visible,true);
  const originalText=q.TitleTextField.text;
  const originalFrame=q.TitleEndPiece._currentframe;
  const headerPoint={x:q.TitleBracket._x,y:q.TitleBracket._y};
  const bodyPoint={x:body._x,y:body._y};
  header.localToGlobal(headerPoint);box.localToGlobal(bodyPoint);
  for(const [x,alpha] of [[5.1,25],[25.55,50],[46,100],[33.2,70]]){
    box._x=x;box._alpha=alpha;
    const h={x:q.TitleBracket._x,y:q.TitleBracket._y};
    const b={x:body._x,y:body._y};
    header.localToGlobal(h);box.localToGlobal(b);
    near(h.x-headerPoint.x,x);near(b.x-bodyPoint.x,x);
    near(h.y-headerPoint.y,0);near(b.y-bodyPoint.y,0);
    assert.equal(header._alpha,100);
    assert.equal(body._alpha,100);
    assert.equal(box._alpha,alpha);
    near(q.GetRenderedBottom(),q.GetContentBounds(undefined).yMax+4);
    assert.equal(q.TitleEndPiece._currentframe,originalFrame);
    assert.equal(q.TitleTextField.text,originalText);
  }
  q.ReflowWidth(0.75);
  assertDetailInsideOrnament(q);
  assert.equal(q.TitleEndPiece._currentframe,originalFrame);
  assert.equal(q.TitleTextField.text,originalText);
  q.SetSide('Stormcloaks');
  assert.equal(q.TitleEndPiece.SideArt._currentframe,1);
});

test('Chinese fields use the configured Normal font even with an empty title format',()=>{
  const q=new QuestItem();
  q.TitleTextField.format={font:'MissingFont',bold:true,italic:true};
  q.SetQuestInfo(1,'任务名','任务详情',true,[{text:'未完成目标',completed:false,failed:false}],0);
  assert.equal(q.ObjectivesHeader.Label.text,'$OBJECTIVES');
  for (const f of [q.DescriptionTextField,q.ObjectivesHeader.Label,q.ObjectiveItemList[0].TextFieldInstance]) {
    assert.equal(f.format.font,'$EverywhereMediumFont');
    assert.equal(f.format.bold,false);
    assert.equal(f.format.italic,false);
    assert.ok(Number.isFinite(f.format.size) && f.format.size>0);
  }
});

test('Chinese and English divider labels resize the gap and keep equal wings',()=>{
  const widths=[];
  for (const text of ['目标','OBJECTIVES','VERY LONG OBJECTIVES TRANSLATION']) {
    const q=new QuestItem();q.objectivesLabel=text;q.SetQuestInfo(1,'Title','Details',true,[pending],0);
    const header=q.ObjectivesHeader,label=header.Label,art=header.Art;
    const width=q.DescriptionTextField._width;
    near(label._x+label._width/2,width/2);
    assert.ok(label.textWidth<=label._width);
    near(art.Left.drawn[1].x,art.Right.drawn[1].x);
    assert.ok(art.Left.drawn[1].x<=label._x-5.9);
    assert.ok(art.Right._x>=label._x+label._width+5.9);
    widths.push(label._width);
  }
  assert.ok(widths[1]>widths[0]);
});

test('details and all three objective states coexist',()=>{
  const q=create('Journal description',[pending,completed,failed]);
  assert.equal(q.DescriptionTextField.text,'Journal description');
  assert.equal(q.ObjectiveItemList.length,3);
  assert.equal(q.ObjectivesHeader.Label.text,'$OBJECTIVES');
  assert.ok(q.ObjectivesHeader._y>=q.DescriptionTextField._y+q.DescriptionTextField._height+6);
  for(let i=0;i<3;i++) assert.equal(q.ObjectiveItemList[i].TextFieldInstance.text,[pending,completed,failed][i].text);
  assert.equal(q.ObjectiveItemList[0].StateIcon.fill,undefined);
  assert.equal(q.ObjectiveItemList[1].StateIcon.fill,0xffffff);
  assert.equal(q.ObjectiveItemList[2].StateIcon._alpha,50);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.textColor,0xffffff);
  assert.equal(q.ObjectiveItemList[1].TextFieldInstance.textColor,0xbbbbbb);
  assert.equal(q.ObjectiveItemList[2].TextFieldInstance.textColor,0xbbbbbb);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.filters[0].args[2],3);
  assert.equal(q.TitleBracket.filters.length,0);
  assert.equal(q.TitleEndPiece.filters.length,0);
  assert.equal(q.ObjectiveItemList[0].StateIcon._width,18);
  assert.equal(q.ObjectiveItemList[0].StateIcon._height,27);
  assert.deepEqual(Array.from(q.ObjectiveItemList[0].StateIcon.filters[0].args),[0,1,4,4,4,2,false,false]);
});

test('active objectives stay first, completed history reverses, failed order stays stable',()=>{
  const active2={text:'Active 2',completed:false,failed:false};
  const done2={text:'Done 2',completed:true,failed:false};
  const q=create('Details',[completed,failed,pending,done2,active2]);
  assert.deepEqual(Array.from(q.ObjectiveItemList,r=>r.TextFieldInstance.text),[pending.text,active2.text,done2.text,completed.text,failed.text]);
  q.SetQuestInfo(1,'Title','Details',true,[completed,{...pending,completed:true},active2],0);
  assert.deepEqual(Array.from(q.ObjectiveItemList,r=>r.TextFieldInstance.text),[active2.text,pending.text,completed.text]);
  assert.equal(q.ObjectivesHeader.Art.filters.length,0);
});

test('missing description and legacy string objectives',()=>{
  const q=create('', ['First objective','Second objective'],6);
  assert.equal(q.DescriptionTextField._visible,false);
  assert.equal(q.TitleTextField._visible,true);
  assert.equal(q.TitleTextField.text,'TEST QUEST');
  assert.equal(q.ObjectiveItemList.length,2);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.text,'First objective');
  assert.ok(q.DetailBody._y+q.ObjectivesHeader._y>=q.naturalLayout.bottom+4);
});

test('empty input, invalid rows and repeat updates leave no stale clips',()=>{
  const q=create('Description',[]);
  assert.equal(q.ObjectivesHeader,undefined); assert.equal(q.ObjectiveContainer,undefined);
  q.SetQuestInfo(1,'Test','Description',true,[null,undefined,{text:''},{text:null},pending],0);
  assert.equal(q.ObjectiveItemList.length,1);
  const old=q.ObjectiveContainer;
  q.SetQuestInfo(1,'Test','New description',true,[completed],0);
  assert.equal(old.removed,true); assert.equal(q.ObjectiveItemList.length,1);
  assert.equal(q.ObjectiveItemList[0].TextFieldInstance.text,completed.text);
  q.SetQuestInfo(1,'Test','',true,[],0);
  assert.equal(q.ObjectiveItemList.length,0);
  assert.equal(q.ObjectivesHeader,undefined); assert.equal(q.ObjectiveContainer,undefined);
});

test('long wrapped details and objectives retain measured heights and order',()=>{
  const q=create('A long journal paragraph '.repeat(24),[pending,{text:'A long objective '.repeat(20),completed:false},completed]);
  assert.ok(q.DescriptionTextField._height>120,'description must not be silently truncated');
  assert.ok(q.ObjectiveItemList[1].contentHeight>18,'wrapped objective needs multiple lines');
  let y=q.ObjectivesHeader._y+q.ObjectivesHeader.contentHeight+5;
  for(const row of q.ObjectiveItemList){near(row._y,y);y+=row.contentHeight+5;}
  near(q.DetailBody.layoutHeight,y-5);
  near(q.contentRect.yMax,q.DetailBody._y+q.DetailBody.layoutHeight);
  assert.ok(q.ObjectivesHeader._y>=q.DescriptionTextField._y+q.DescriptionTextField._height+6);
});

test('short completed rows reserve diamond and outline before whole-row clipping',()=>{
  const q=create('Description',[{text:'Done',completed:true}]);
  const row=q.ObjectiveItemList[0];
  row.TextFieldInstance.format.size=8;
  q.ReflowWidth(1.6);
  const icon=row.StateIcon, text=row.TextFieldInstance;
  assert.ok(icon._y>=4);
  assert.ok(icon._y+icon._height+4<=row.contentHeight);
  assert.ok(text._y>=4 && text._y+text._height+4<=row.contentHeight);
  const cut={x:0,y:icon._y+icon._height+3};row.localToGlobal(cut);
  q.ApplyHeightLimit(cut.y);
  assert.equal(row._visible,false,'hide the whole row when its outline cannot fit');
  q.ApplyHeightLimit(bottom(row)+4);assert.equal(row._visible,true);
  q.ReflowWidth(1);assert.ok(icon._y+icon._height+4<=row.contentHeight);
});

test('real AS2 text fields need no MovieClip geometry methods',()=>{
  const q=create('Description',[{text:'Long completed objective '.repeat(20),completed:true}]);
  const fields=[q.DescriptionTextField,q.ObjectivesHeader.Label,...q.ObjectiveItemList.map(r=>r.TextFieldInstance)];
  for(const f of fields) {
    const w=f._width,h=f._height;
    Object.defineProperties(f,{_width:{value:w,writable:true},_height:{value:h,writable:true}});
    f.getBounds=()=>{throw Error('AS2 TextField has no getBounds');};
    f.localToGlobal=()=>{throw Error('AS2 TextField has no localToGlobal');};
  }
  const bottom=q.GetRenderedBottom();assert.ok(Number.isFinite(bottom));
  q.ApplyHeightLimit(bottom-10);assert.equal(q.ObjectiveItemList[0]._visible,false);
  q.ApplyHeightLimit(bottom+10);assert.equal(q.ObjectiveItemList[0]._visible,true);
  assert.ok(!q.GetRowClipState(new MovieClip()).includes('undefined'));
});

test('height limit hides complete rows and never reveals a later row',()=>{
  const q=create('Description',[pending,completed,failed]);
  q.ApplyHeightLimit(100000);
  assert.ok(q.ObjectiveItemList.every(r=>r._visible));
  const cut=bottom(q.ObjectiveItemList[1])-1;
  q.ApplyHeightLimit(cut);
  assert.deepEqual(q.ObjectiveItemList.map(r=>r._visible),[true,false,false]);
  assert.equal(q.ObjectivesHeader._visible,true);
  q.ApplyHeightLimit(bottom(q.ObjectivesHeader)+1);
  assert.equal(q.ObjectivesHeader._visible,false);
  assert.ok(q.ObjectiveItemList.every(r=>!r._visible));
  q.ApplyHeightLimit(100000);
  assert.ok(q.ObjectiveItemList.every(r=>r._visible));
  q.ApplyHeightLimit(bottom(q.DescriptionTextField)-1);
  assert.equal(q.DescriptionTextField._visible,false);
});

test('content bounds transform all four corners under nested rotation and scaling',()=>{
  const root=new MovieClip(); root._x=100;root._y=40;root._xscale=125;root._yscale=80;
  const q=create('Description',[pending,completed]);root.add('quest',q);
  q._x=23;q._y=-17;q._rotation=23;q._xscale=70;q._yscale=90;
  const r=q.contentRect;
  const points=[[r.xMin,r.yMin],[r.xMax,r.yMin],[r.xMin,r.yMax],[r.xMax,r.yMax]].map(([x,y])=>{
    const p={x,y};q.DetailBox.localToGlobal(p);root.globalToLocal(p);return p;
  });
  const b=q.GetContentBounds(root);
  near(b.xMin,Math.min(...points.map(p=>p.x)));near(b.xMax,Math.max(...points.map(p=>p.x)));
  near(b.yMin,Math.min(...points.map(p=>p.y)));near(b.yMax,Math.max(...points.map(p=>p.y)));
});

test('linked artwork takes precedence over fallback geometry',()=>{
  MovieClip.linkages=new Set(['QuestObjectivesDivider','QuestObjectiveCompleted','QuestObjectivePending']);
  const q=create('Description',[pending,completed]);
  assert.equal(q.ObjectivesHeader.Art.Left.Art.linkage,'QuestObjectivesDivider');
  assert.equal(q.ObjectivesHeader.Art.Right.Art.linkage,'QuestObjectivesDivider');
  assert.ok(q.ObjectivesHeader.Art.Left.Art.mask);
  assert.equal(q.ObjectiveItemList[0].StateIcon.linkage,'QuestObjectivePending');
  assert.equal(q.ObjectiveItemList[1].StateIcon.linkage,'QuestObjectiveCompleted');
  assert.equal(q.ObjectiveItemList[0].StateIcon._width,18);
  assert.equal(q.ObjectiveItemList[0].StateIcon._height,27);
  assert.deepEqual(Array.from(q.ObjectiveItemList[0].StateIcon.filters[0].args),[0,1,4,4,4,2,false,false]);
  MovieClip.linkages=new Set();
});

test('completed reversal is deterministic, does not mutate input, and leaves other groups stable',()=>{
  const rows=[
    {text:'Oldest done',completed:true}, {text:'Failed 1',failed:true},
    {text:'Active 1'}, {text:'Middle done',completed:true},
    {text:'Failed 2',failed:true}, {text:'Newest done',completed:true}, {text:'Active 2'}
  ];
  const before=JSON.stringify(rows);
  const q=create('',rows);
  const expected=['Active 1','Active 2','Newest done','Middle done','Oldest done','Failed 1','Failed 2'];
  assert.deepEqual(Array.from(q.ObjectiveItemList,r=>r.TextFieldInstance.text),expected);
  q.SetQuestInfo(1,'Title','Changed description',true,rows,0);
  assert.deepEqual(Array.from(q.ObjectiveItemList,r=>r.TextFieldInstance.text),expected);
  assert.equal(JSON.stringify(rows),before);
  assert.equal(create('',[]).ObjectiveItemList.length,0);
  assert.equal(create('',[completed]).ObjectiveItemList[0].TextFieldInstance.text,completed.text);
});

test('content width never exceeds the fixed ornament and can reflow narrower',()=>{
  const q=create('Long description '.repeat(35),[{text:'Long objective '.repeat(20)}]);
  const original=q.DescriptionTextField.text, h=q.DescriptionTextField._height;
  const width=q.DescriptionTextField._width, row=q.ObjectiveItemList[0];
  q.ReflowWidth(1.6);
  near(q.DescriptionTextField._width,width);
  near(q.DescriptionTextField._height,h);
  q.ReflowWidth(0.75);
  near(q.DescriptionTextField._width,width*0.75);
  assert.ok(q.DescriptionTextField._height>h);
  assert.equal(q.DescriptionTextField.text,original);
  assert.equal(q.DescriptionTextField._xscale,100);
  assert.equal(row.TextFieldInstance._xscale,100);
  near(row.StateIcon._width,18);near(row.StateIcon._height,27);
  near(q.ObjectivesHeader.Label._x+q.ObjectivesHeader.Label._width/2,width*0.75/2);
  assertDetailInsideOrnament(q);
  q.ReflowWidth(1);near(q.DescriptionTextField._width,width);near(q.DescriptionTextField._height,h);
  assertDetailInsideOrnament(q);
});

test('one Box owns the complete vertical layout and restores its natural width',()=>{
  const q=new QuestItem();originalOrnamentFixture(q);
  const rows=[pending,completed,failed];
  q.SetQuestInfo(1,'Title','Description '.repeat(22),true,rows,0);
  const box=q.DetailBox,body=q.DetailBody,naturalWidth=body.layoutWidth;
  const description=q.DescriptionTextField;
  const header=q.ObjectivesHeader;
  const expected=()=>{
    near(description._x,0);near(description._y,0);
    near(description._width,body.layoutWidth);
    near(header._y,description._height+6);
    let y=header._y+header.contentHeight+5;
    for(const row of q.ObjectiveItemList){
      near(row._x,0);near(row._y,y);
      near(row.TextFieldInstance._width,body.layoutWidth-26);
      y+=row.contentHeight+5;
    }
    near(body.layoutHeight,y-5);
    assertDetailInsideOrnament(q);
  };
  expected();
  const originalHeight=body.layoutHeight;
  q.ReflowWidth(0.75);expected();
  assert.ok(body.layoutHeight>originalHeight);
  q.ReflowWidth(1);expected();near(body.layoutWidth,naturalWidth);near(body.layoutHeight,originalHeight);
  assert.equal(box._rect.xMax,0);
  assert.equal(box._rect.yMax,0);
});

test('empty sections do not reserve phantom Box height or retain old rows',()=>{
  const q=create('',[]);
  near(q.DetailBody.layoutHeight,0);
  near(q.DetailBox.layoutHeight,q.Title.layoutHeight+4);
  assert.equal(q.ObjectivesHeader,undefined);
  q.SetQuestInfo(1,'Title','',true,[pending],0);
  near(q.ObjectivesHeader._y,0);
  assert.ok(q.DetailBox.layoutHeight>0);
  const old=q.ObjectiveContainer;
  q.SetQuestInfo(1,'Title','A short description',true,[],0);
  assert.equal(old.removed,true);
  near(q.DetailBody.layoutHeight,q.DescriptionTextField._height);
  assert.equal(q.ObjectivesHeader,undefined);
  assertDetailInsideOrnament(q);
});

test('height fitting uses logical Box bounds, not oversized imported art',()=>{
  MovieClip.linkages=new Set(['QuestObjectivesDivider','QuestObjectivePending']);
  const root=new MovieClip(),parent=root.createEmptyMovieClip('Target');
  const q=new QuestItem();originalOrnamentFixture(q);parent.add('quest',q);
  q.SetQuestInfo(1,'Title','Description '.repeat(12),true,[pending,completed],0);
  parent._x=80;parent._y=50;parent._rotation=17;parent._xscale=125;parent._yscale=80;
  q._xscale=65;q._yscale=65;
  const logical=q.GetDetailBoxBounds(undefined);
  const raw=q.DetailBody.getBounds(q.DetailBox);
  assert.ok(raw.xMax>q.DetailBody._x+q.DetailBody.layoutWidth,'imported source has unmasked offscreen geometry');
  near(q.GetRenderedBottom(),logical.yMax+4);
  const full=q.GetRenderedBottom();
  q.ApplyHeightLimit(full);
  assert.ok(q.ObjectiveItemList.every(r=>r._visible));
  const last=q.ObjectiveItemList[q.ObjectiveItemList.length-1];
  const rowBounds=q.TransformBounds(last,{xMin:0,yMin:0,xMax:q.DetailBody.layoutWidth,yMax:last.contentHeight},undefined);
  q.ApplyHeightLimit(rowBounds.yMax+3);
  assert.equal(last._visible,false);
  q.ApplyHeightLimit(full);
  assert.ok(q.ObjectiveItemList.every(r=>r._visible));
  assertDetailInsideOrnament(q);
  MovieClip.linkages=new Set();
});

test('independent skin maps failed state and preserves fixed icon slots',()=>{
  MovieClip.linkages=new Set(['QuestObjectivesDivider','QuestObjectivePending','QuestObjectiveCompleted','QuestObjectiveFailed']);
  const q=create('Journal details',[pending,completed,failed]);
  for(const [i,name] of ['QuestObjectivePending','QuestObjectiveCompleted','QuestObjectiveFailed'].entries()) {
    const icon=q.ObjectiveItemList[i].StateIcon;
    assert.equal(icon.linkage,name);near(icon._width,18);near(icon._height,27);
    assert.equal(icon._alpha,100);
    assert.deepEqual(Array.from(icon.filters[0].args),[0,1,4,4,4,2,false,false]);
  }
  const header=q.ObjectivesHeader;
  near(header.Art.Right.Art._x,-308.5*header.Art.Right.Mask._width/172.75);
  near(header.Art.Left.Art._yscale,100*16/14.85);
  MovieClip.linkages=new Set();
});

test('linked divider reflow sizes visible crops inside the fixed ornament',()=>{
  MovieClip.linkages=new Set(['QuestObjectivesDivider']);
  const q=create('Details',[pending]);q.ReflowWidth(0.75);
  const header=q.ObjectivesHeader, left=header.Art.Left, right=header.Art.Right;
  const wing=header.Label._x-6;
  near(left._xscale,100);near(right._xscale,100);
  near(left.Art._xscale,100*wing/172.75);near(right.Art._xscale,100*wing/172.75);
  near(left.Mask._width,wing);near(right.Mask._width,wing);
  near(right._x,header.Label._x+header.Label._width+6);
  assertDetailInsideOrnament(q);
  MovieClip.linkages=new Set();
});
};
