module.exports = function registerTests(h) {
  const {assert,fs,vm,MovieClip,TextField,QuestItem,context,timeline,pending,completed,failed,test,create,near,bottom,originalOrnamentFixture,assertDetailInsideOrnament,setup,shrinkable} = h;

test('automatic shrink stops at 90 and never enlarges a smaller manual request',()=>{
    for(const request of [25,70,90,100,110]) {
      const {list}=setup('Huge text '.repeat(10000),760);
      list.TEXT_SCALE=request;list.FitLayout();
      assert.equal(list.effectiveScale,Math.min(90,request));
      assert.equal(list.fitOverflow,true);
      assert.equal(list.TEXT_SCALE,request);
    }
  });

test('viewport mask follows content bounds under transformed parent',()=>{
    const {list}=setup('Description');
    list._parent._x=30;list._parent._yscale=130;
    list.UpdateViewportMask();assert.equal(list.mask,list.viewportMask);
    const b=list.viewportMask.getBounds(list._root);
    const content=list.entries[0].GetContentBounds(list._root);
    near(b.xMin,Math.max(12,content.xMin-4));near(b.yMin,Math.max(12,content.yMin-4));
    near(b.xMax,Math.min(1012,content.xMax+4));near(b.yMax,Math.min(1012,content.yMax+4));
  });

test('retired quest clips are removed immediately, not left outside the fitted set',()=>{
    const {list,q}=setup('Old objective');list.SyncQuests([]);
    assert.equal(q._visible,false);assert.equal(q.removed,true);assert.equal(list.entries.length,0);
  });

test('overflow reserves a visible omission line and restores it when content fits',()=>{
    const {list,q}=setup('Description');
    list.FitLayout();
    const limit=q.GetRenderedBottom()-8;
    const reduced=list.PrepareOverflowLabel(limit);
    assert.ok(reduced<=limit);
    assert.equal(list.overflowLabel.symbol,'. . .');
    assert.equal(list.overflowLabel._visible,true);
    q.ApplyHeightLimit(reduced);
    assert.ok(q.ObjectiveItemList.some(r=>!r._visible));
    const label=list.overflowLabel.getBounds(list._root);
    assert.ok(label.yMax<=limit);
    assert.equal(list.PrepareOverflowLabel(100000),100000);
    assert.equal(list.overflowLabel._visible,false);
  });

test('current viewport limit keeps omission inside the stage without a retired guard band',()=>{
    const {list,q}=setup('Description',940);
    q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
    list.FitLayout();
    near(list.GetViewportBottom(),1024);
    assert.equal(list.FitsViewport({xMin:100,xMax:500,yMin:760,yMax:970}),true);
    assert.equal(list.FitsViewport({xMin:100,xMax:500,yMin:760,yMax:1025}),false);
    const limit=list.GetViewportBottom();
    const cut=list.PrepareOverflowLabel(limit);
    if(list.overflowLabel._visible) {
      assert.ok(cut<=limit);
      assert.ok(list.overflowLabel.getBounds(list._root).yMax<=list.GetViewportBottom());
    } else {
      assert.equal(cut,limit);
      assert.equal(list.omissionReason,'preserve last readable objective');
      assert.ok(q.ObjectiveItemList.some(row=>row._visible));
    }
  });

test('root-space fitting does not convert global Y through an unrelated X',()=>{
    const {list,q}=setup('Description '.repeat(8),400);
    list._root._x=300;list._root._y=-40;list._root._xscale=125;list._root._yscale=80;list._root._rotation=17;
    const actual=list.LayoutCandidate(100,1);
    const logical=q.GetContentBounds(list._root);
    near(actual.yMax,Math.max(logical.yMax,q.GetRenderedBottomInSpace(list._root)));
    const oldPoint={x:0,y:q.GetRenderedBottom()};list._root.globalToLocal(oldPoint);
    assert.ok(Math.abs(oldPoint.y-q.GetRenderedBottomInSpace(list._root))>1);
    const limit=q.GetRenderedBottomInSpace(list._root)+1;
    near(list.PrepareOverflowLabel(limit),limit);
    assert.equal(list.overflowLabel._visible,false);
    assert.ok(q.ObjectiveItemList.every(r=>r._visible));
  });

test('empty Body gutter cannot invent omitted content or an ellipsis',()=>{
    const {list,q}=setup('',400);
    q.SetQuestInfo(1,'Title','',true,[],0);
    list.FitLayout();
    const limit=q.GetHeaderBottomInSpace(list._root)+1;
    assert.ok(q.GetRenderedBottomInSpace(list._root)>limit);
    near(list.PrepareOverflowLabel(limit),limit);
    assert.equal(list.overflowLabel._visible,false);
    assert.equal(q.HasOmittedContent(),false);
  });

test('omission label follows the last complete visible row rather than floating at the safe edge',()=>{
    const {list,q}=setup('Description',400);
    q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
    list.FitLayout();
    const limit=q.GetRenderedBottomInSpace(list._root)-10;
    const reduced=list.PrepareOverflowLabel(limit);
    assert.ok(reduced<=limit);
    assert.ok(q.HasOmittedContent());
    const label=list.overflowLabel.getBounds(list._root);
    const omitted=q.ObjectiveItemList.find(r=>!r._visible),p={x:0,y:0};
    omitted.localToGlobal(p);list._root.globalToLocal(p);near(label.yMin,p.y);
    assert.ok(label.yMax<=limit);
    list.PrepareOverflowLabel(100000);
    assert.equal(list.overflowLabel._visible,false);
    assert.ok(q.ObjectiveItemList.every(r=>r._visible));
  });

test('an ellipsis cannot evict an otherwise readable description',()=>{
    const {list,q}=setup('Description '.repeat(20),100);
    list.FitLayout();
    const descriptionBottom=q.DisplayBounds(q.DescriptionTextField,list._root).yMax+4;
    const limit=descriptionBottom+8;
    near(list.PrepareOverflowLabel(limit),limit);
    assert.equal(q.DescriptionTextField._visible,true);
    assert.equal(list.overflowLabel._visible,false);
    assert.ok(['preserve readable description','no room for omission label'].includes(list.omissionReason));
    assert.ok(q.ObjectiveItemList.some(r=>!r._visible));
  });

test('cached overflow retries after content geometry changes without a signature change',()=>{
    const {list,q}=setup('Huge text '.repeat(200),750);
    list.FitLayout();assert.equal(list.fitOverflow,true);
    const runs=list.fitRuns;
    q.SetQuestInfo(1,'Title','Short',true,[pending],0);
    q.dataSignature='v1';
    list.FitLayout();
    assert.ok(list.fitRuns>runs);
    assert.equal(list.fitOverflow,false);
    assert.equal(list.effectiveScale,110);
  });

test('on-demand layout snapshot refreshes visibility and reports root-space diagnostics',()=>{
    const {list,q}=setup('Description',400);
    list.FitLayout();
    q.ApplyHeightLimit(q.ClipBottom(q.DescriptionTextField)-1);
    assert.equal(q.DescriptionTextField._visible,false);
    const state=list.GetLayoutSnapshot();
    assert.equal(q.DescriptionTextField._visible,true);
    assert.ok(state.includes('safeLimitLocal='));
    assert.ok(state.includes('sharedHudSafeBottomRoot='));
    assert.ok(state.includes('layoutSpace='));
    assert.ok(state.includes('headerHeight='));
    assert.ok(state.includes('omissionReason='));
    assert.equal(list.omissionReason,'none');
  });

test('fitted rendered bounds do not immediately trigger omission after camera motion',()=>{
    const {list,q,field}=shrinkable();
    const startY=field._y;
    list.FitLayout();
    const originalWidth=list.effectiveWidth,originalScale=list.effectiveScale;
    for(const delta of [0,2,6,3,0]) {
      field._y=startY+delta;list.FitLayout();
      assert.equal(list.fitOverflow,false);
      const limit=list.GetViewportBottom();
      assert.ok(q.GetRenderedBottom()<=limit,`${q.GetRenderedBottom()} > ${limit}`);
      assert.equal(list.PrepareOverflowLabel(limit),limit);
      q.ApplyHeightLimit(limit);assert.ok(q.ObjectiveItemList.every(r=>r._visible));
    }
    near(list.effectiveWidth,originalWidth);near(list.effectiveScale,originalScale);
  });

test('horizontal-only overflow never triggers widening',()=>{
    const {list}=setup('Short description',500);
    list.Stage.width=550;
    list.FitLayout();
    assert.equal(list.effectiveWidth,1);
  });

test('width is capped at the last horizontal-safe step before shrinking',()=>{
    const {list}=setup('Long description '.repeat(60),760);
    const original=list.FitsHorizontal;
    list.FitsHorizontal=function(b) { return original.call(list,b) && b.xMax-b.xMin<=175; };
    list.FitLayout();
    assert.ok(list.effectiveWidth<=1.2,'must not widen after reducing scale');
  });

test('offsets persist through anchoring and still follow the parent compass',()=>{
    const {list}=setup('Short description',500);
    list.FitLayout();const x=list._x,y=list._y;
    list.SetOffsetX(35);list.FitLayout();
    near(list._x,x+35);near(list._y,y);
    list.UpdateAnchor();near(list._x,x+35);near(list._y,y);
    const p={x:0,y:0};list.localToGlobal(p);
    list._parent._x+=60;list._parent._y+=10;list.UpdateAnchor();
    const q={x:0,y:0};list.localToGlobal(q);near(q.x-p.x,60);near(q.y-p.y,10);
    list.SetOffsetX(0);list.FitLayout();near(list._x,x);near(list._y,y);
  });

test('offset setters reject invalid values and clamp to the supported range',()=>{
    const {list}=setup('Description '.repeat(20),500);
    assert.equal(timeline.includes('function SetMaxHeight('),false);
    list.SetOffsetX(-50);list.SetOffsetX(NaN);
    assert.equal(list.offsetX,-50);assert.equal(list.offsetY,undefined);
    list.SetOffsetX(999);assert.equal(list.offsetX,200);assert.equal(list.offsetY,undefined);
    list.SetOffsetX(-999);assert.equal(list.offsetX,-200);
    list.SetOffsetX(Infinity);assert.equal(list.offsetX,-200);
  });

test('adaptive solver respects request, viewport and caches unchanged layout',()=>{
    const {list}=setup('Short description');list.FitLayout();
    assert.equal(list.effectiveScale,110);assert.equal(list.effectiveWidth,1);
    assert.equal(list.fitOverflow,false);
    const runs=list.fitRuns;list.FitLayout();assert.equal(list.fitRuns,runs);
  });

test('adaptive solver keeps ornament width, shrinks long content, resets after content change',()=>{
    const {list,q}=shrinkable();list.FitLayout();
    assert.ok(list.effectiveScale>=90&&list.effectiveScale<110);
    assert.equal(list.effectiveWidth,1);
    assert.equal(list.fitOverflow,false);
    assert.ok(list.FitsViewport(list.LayoutCandidate(list.effectiveScale,list.effectiveWidth)));
    q.SetQuestInfo(1,'Title','Short',true,[pending],0);q.dataSignature='v2';list.FitLayout();
    assert.equal(list.effectiveScale,110);assert.equal(list.effectiveWidth,1);
    assert.equal(list.TEXT_SCALE,110);
  });

test('adaptive solver responds to anchor and stage changes and flags unfit minimum',()=>{
    const {list,field}=setup('Details '.repeat(40),600);list.FitLayout();
    const runs=list.fitRuns;field._y+=32;list.FitLayout();assert.ok(list.fitRuns>runs);
    list.Stage.height=900;list.FitLayout();assert.ok(list.fitRuns>runs+1);
    const huge=setup('Huge text '.repeat(10000),800).list;huge.FitLayout();
    assert.equal(huge.effectiveScale,90);assert.equal(huge.fitOverflow,true);
  });
test('passenger respects desired scale and the 90 percent readability floor',()=>{
  for(const request of [25,70,90,100,110]) {
    const {list}=setup('Huge text '.repeat(1000),100);
    list.compassPassengerMode=true;
    list.TEXT_SCALE=request;list.Update();
    assert.equal(list.effectiveScale,Math.min(90,request));
    assert.equal(list.TEXT_SCALE,request);
  }
  const {list,q}=setup('',100);
  q.SetQuestInfo(1,'Title','',true,[],0);
  list.compassPassengerMode=true;
  list.compassPassengerConfig.width=900;list.compassPassengerConfig.height=800;
  list.compassPassengerConfig.offsetX=0;list.compassPassengerConfig.offsetY=0;
  list.Update();assert.equal(list.effectiveScale,110);
});

test('passenger stays inside the sampled continuous band without crossing its upper seam',()=>{
  const {list,q,field}=setup('Description',50);
  list.compassPassengerMode=true;
  list._parent._y=706.45;
  field._x=-949.45;field._y=9.5;field._width=1898.85;field._height=35.55;
  q.SetQuestInfo(1,'Title','Long description '.repeat(6),true,[pending,completed,failed],0);
  list.Update();
  near(list.GetSharedHudSafeTop(),760);
  near(list.GetSharedHudSafeBottom(),960);
  const bounds=list.GetViewportBounds();
  near(bounds.yMin,760-list._parent._y);
  near(bounds.yMax,960-list._parent._y);
  assert.ok(bounds.yMax-bounds.yMin<220);
  near(q.GetContentBounds(list._root).yMin,706.45+bounds.yMin+4.1);
  assert.equal(q.Title._visible,true);
  assert.ok(list.effectiveScale>=90);
  assert.ok(list.viewportMask.getBounds(list._root).yMax<=960.001);
  assert.ok(list.viewportMask.getBounds(list._root).yMin>=759.999);
  assert.deepEqual(list.GetDebugObservation().viewport,bounds);
  for(const row of q.ObjectiveItemList)
    if(row._visible)assert.ok(row.getBounds(list._root).yMax<=960.001);
  list.SetOffsetX(200);list.Update();
  assert.ok(list.viewportMask.getBounds(list._root).yMax<=960.001);
  assert.ok(list.viewportMask.getBounds(list._root).yMin>=759.999);
});

test('sampled band contains transformed viewport corners for rotated and scaled parents',()=>{
  for(const rotation of [-12,0,12]) {
    const {list}=setup('Description',50);
    list.compassPassengerMode=true;
    list._parent._y=706.45;list._parent._rotation=rotation;
    list._parent._xscale=110;list._parent._yscale=90;
    for(const offset of [-200,0,200]) {
      list.SetOffsetX(offset);list.Update();
      const b=list.GetViewportBounds();assert.ok(b.yMax>b.yMin);
      for(const x of [b.xMin,b.xMax])for(const y of [b.yMin,b.yMax]) {
        const p={x,y};list._parent.localToGlobal(p);list._root.globalToLocal(p);
        assert.ok(p.y>=759.999 && p.y<=960.001);
        assert.ok(p.x>=11.999 && p.x<=1012.001);
      }
      assert.ok(list.effectiveScale>=90);
    }
  }
});

test('ellipsis never evicts the last otherwise fitting objective',()=>{
  const {list,q}=setup('Description',400);
  q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
  list.FitLayout();
  const row=q.ObjectiveItemList[0];
  const limit=q.TransformBounds(row,{xMin:0,yMin:0,xMax:q.DetailBody.layoutWidth,yMax:row.contentHeight},list._root).yMax+4.1;
  const result=list.PrepareOverflowLabel(limit);
  q.ApplyHeightLimit(result,list._root);
  assert.equal(row._visible,true);
  assert.equal(list.overflowLabel._visible,false);
  assert.equal(list.omissionReason,'preserve last readable objective');
});

test('ellipsis uses fitted item scale and keeps a goal when the compact indicator fits',()=>{
  const {list,q}=setup('Description',400);
  q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
  list.TEXT_SCALE=90;list.FitLayout();
  const row=q.ObjectiveItemList[0];
  const rowBottom=q.TransformBounds(row,{xMin:0,yMin:0,xMax:q.DetailBody.layoutWidth,yMax:row.contentHeight},list._root).yMax+4;
  const limit=rowBottom+34;
  const result=list.PrepareOverflowLabel(limit);q.ApplyHeightLimit(result,list._root);
  assert.equal(row._visible,true);assert.equal(list.overflowLabel._visible,true);
  near(list.overflowLabel._yscale,list.SCALE*list.effectiveScale/100);
  assert.ok(list.overflowLabel.getBounds(list._root).yMax<=limit);
});

test('ellipsis reserves the icon slot and follows the actual objective text column',()=>{
  for(const scale of [90,110]) {
    const {list,q}=setup('Description',400);
    q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
    list.TEXT_SCALE=scale;list.FitLayout();
    const limit=q.GetRenderedBottomInSpace(list._root)-10;
    const reduced=list.PrepareOverflowLabel(limit);
    assert.ok(reduced<=limit);assert.equal(list.overflowLabel._visible,true);
    const row=q.ObjectiveItemList.find(r=>r._visible);
    const expected={x:0,y:0};row.localToGlobal(Object.assign(expected,{x:row.TextFieldInstance._x,y:row.TextFieldInstance._y}));list.globalToLocal(expected);
    near(list.overflowLabel._x,expected.x);
    assert.equal(list.overflowLabel.symbol,'. . .','no whitespace padding or fake glyph');
    // A changed text-column offset must be measured rather than hard-coded.
    for(const r of q.ObjectiveItemList)r.TextFieldInstance._x+=9;
    list.PrepareOverflowLabel(limit);
    const moved={x:0,y:0};row.localToGlobal(Object.assign(moved,{x:row.TextFieldInstance._x,y:row.TextFieldInstance._y}));list.globalToLocal(moved);
    near(list.overflowLabel._x,moved.x);
  }
});

test('omission alignment works with real AS2 TextField API limitations',()=>{
  const {list,q}=setup('Description',400);
  q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
  list.FitLayout();
  for(const row of q.ObjectiveItemList) {
    row.TextFieldInstance.localToGlobal=undefined;
    row.TextFieldInstance.globalToLocal=undefined;
  }
  const limit=q.GetRenderedBottomInSpace(list._root)-10;
  assert.doesNotThrow(()=>list.PrepareOverflowLabel(limit));
  assert.equal(list.overflowLabel._visible,true);
  const row=q.ObjectiveItemList.find(r=>r._visible),field=row.TextFieldInstance;
  const p={x:field._x,y:field._y};field._parent.localToGlobal(p);list.globalToLocal(p);
  near(list.overflowLabel._x,p.x);
});

test('passenger horizontal offset moves at both expanded endpoints and caches unchanged settings',()=>{
  const {list,field}=setup('Short description',50);
  list.compassPassengerMode=true;
  list._parent._x=495.65;list._parent._y=706.45;
  field._x=-949.45;field._y=9.5;field._width=1898.85;field._height=35.55;
  list.SetOffsetX(0);list.Update();
  const origin={x:0,y:0};list.localToGlobal(origin);
  for(const offset of [-200,200,0]) {
    list.SetOffsetX(offset);list.Update();
    const point={x:0,y:0};list.localToGlobal(point);
    near(point.x,origin.x+offset);near(point.y,origin.y);
    const runs=list.fitRuns;list.SetOffsetX(offset);list.Update();assert.equal(list.fitRuns,runs);
    const b=list.viewportMask.getBounds(list._root);
    assert.ok(b.xMin>=11.999 && b.xMax<=1012.001);
    assert.ok(b.yMin>=759.999 && b.yMax<=960.001);
  }
  assert.equal(typeof list.SetOffsets,'undefined');assert.equal(list.offsetY,undefined);
});

test('passenger compact replacement preserves the last readable objective',()=>{
  for(const scale of [90,110]) {
    const {list,q,field}=setup('Description',50);
    list.compassPassengerMode=true;list._parent._x=495.65;list._parent._y=706.45;
    field._x=-949.45;field._y=9.5;field._width=1898.85;field._height=35.55;
    q.SetQuestInfo(1,'Title','Description',true,[pending,{text:'Long objective '.repeat(20),completed:false},failed],0);
    list.TEXT_SCALE=scale;list.Update();
    const space=list.GetLayoutSpace(),viewport=list.GetViewportBounds();
    const hb=list.overflowLabel.getBounds(space),height=hb.yMax-hb.yMin;
    let candidate;
    for(let limit=viewport.yMin+1;limit<=viewport.yMax;limit+=0.25) {
      q.ApplyHeightLimit(limit,space);
      if(q.ObjectiveItemList.filter(r=>r._visible).length!==1 || !q.HasOmittedContent())continue;
      const bottom=list.GetVisibleBottomInRoot(limit);
      if(bottom+height+4<=limit && bottom>limit-height-8) {candidate=limit;break;}
    }
    assert.ok(candidate!==undefined,'fixture reaches the narrow slack interval');
    q.ApplyHeightLimit(candidate,space);
    const visible=q.ObjectiveItemList.map(r=>r._visible),bottom=list.GetVisibleBottomInRoot(candidate);
    near(list.PrepareOverflowLabel(candidate),candidate);
    assert.equal(list.overflowLabel._visible,true);
    assert.deepEqual(q.ObjectiveItemList.map(r=>r._visible),visible);
    assert.match(list.omissionReason,/compact replacement/);
    const label=list.overflowLabel.getBounds(space);
    const omitted=q.ObjectiveItemList.find(r=>!r._visible),origin={x:0,y:0};
    omitted.localToGlobal(origin);space.globalToLocal(origin);
    near(label.yMin,origin.y);assert.ok(label.yMax<=candidate+0.001);
    const row=q.ObjectiveItemList.find(r=>r._visible),p={x:row.TextFieldInstance._x,y:row.TextFieldInstance._y};
    row.localToGlobal(p);space.globalToLocal(p);near(label.xMin,p.x);
    list.PrepareOverflowLabel(candidate);assert.equal(list.overflowLabel._visible,true);
    q.SetQuestInfo(1,'Title','',true,[],0);list.PrepareOverflowLabel(candidate);
    assert.equal(list.overflowLabel._visible,false);
  }
});


test('compact dots reserve exactly their drawn five-unit height including borders',()=>{
  for(const scale of [25,90,100,110]) {
    const {list}=setup('Description',50);list.effectiveScale=scale;
    list.PrepareOverflowLabel(10000);
    const local=list.overflowLabel.getBounds(list.overflowLabel);
    near(local.xMin,0);near(local.yMin,0);near(local.xMax,23);near(local.yMax,5);
    const drawn=list.overflowLabel.getBounds(list);near(drawn.yMax-drawn.yMin,5*65*scale/10000);
    assert.equal(list.overflowLabel.text,undefined);assert.equal(list.overflowLabel.symbol,'. . .');
    assert.equal(list.overflowLabel.filters.length,0);
  }
});

test('any objective with even a fractional clipped child is replaced and following rows stay hidden',()=>{
  for(const index of [0,1,2])for(const element of ['text','icon']) {
    const {list,q}=setup('Description',50);
    q.SetQuestInfo(1,'Title','Description',true,[pending,pending,pending],0);
    list.FitLayout();
    const space=list.GetLayoutSpace(),vp=list.GetViewportBounds(),row=q.ObjectiveItemList[index];
    const factor=q._xscale/100;
    if(element==='text') {
      const b=q.DisplayBounds(row.TextFieldInstance,space);
      row.TextFieldInstance._width+=(vp.xMax-b.xMax-4+0.01)/factor;
    } else {
      const b=q.DisplayBounds(row.StateIcon,space);
      row.StateIcon._x-=(b.xMin-vp.xMin-4+0.01)/factor;
    }
    list.PrepareOverflowLabel(vp.yMax);
    assert.equal(list.overflowLabel._visible,true,element+' '+index);
    assert.deepEqual(q.ObjectiveItemList.map(r=>r._visible),[0,1,2].map(i=>i<index));
    const p={x:row.TextFieldInstance._x,y:0};row.localToGlobal(p);space.globalToLocal(p);
    const dots=list.overflowLabel.getBounds(space);near(dots.xMin,p.x);near(dots.yMin,p.y);
    assert.ok(dots.xMin>=vp.xMin && dots.xMax<=vp.xMax && dots.yMin>=vp.yMin && dots.yMax<=vp.yMax);
  }
});


test('a fractional bottom clip of any objective child produces a compact replacement',()=>{
 for(const index of [0,1,2])for(const element of ['text','icon']) {
  const {list,q}=setup('Description',50);
  q.SetQuestInfo(1,'Title','Description',true,[pending,pending,pending],0);list.FitLayout();
  const space=list.GetLayoutSpace(),vp=list.GetViewportBounds(),row=q.ObjectiveItemList[index];
  const child=element==='text'?row.TextFieldInstance:row.StateIcon;
  const b=q.DisplayBounds(child,space),factor=q._yscale/100;
  child._y+=(vp.yMax-b.yMax-4+0.01)/factor;
  list.PrepareOverflowLabel(vp.yMax);
  assert.equal(list.overflowLabel._visible,true);
  assert.deepEqual(q.ObjectiveItemList.map(r=>r._visible),[0,1,2].map(i=>i<index));
  const p={x:row.TextFieldInstance._x,y:0};row.localToGlobal(p);space.globalToLocal(p);
  near(list.overflowLabel.getBounds(space).yMin,p.y);
 }
});

test('first omitted objective suppresses later quest entries and recovers after content is repaired',()=>{
 const {list,q}=setup('Description',50),second=setup('Other description',50).q;
 list.add('extraQuest',second);list.entries.push(second);
 q.SetQuestInfo(1,'Title','Description',true,[pending,pending],2);
 second.SetQuestInfo(1,'Other','Other description',true,[pending],1);
 list.Update();q.ObjectiveItemList[0].TextFieldInstance._width=10000;list.Update();
 assert.equal(list.overflowStopIndex,0);assert.equal(list.overflowLabel._visible,true);
 assert.equal(second._visible,false);
 q.SetQuestInfo(1,'Title','Description',true,[pending,pending],2);list.Update();
 assert.equal(list.overflowStopIndex,-1);assert.equal(list.overflowLabel._visible,false);
 assert.equal(second._visible,true);
});


test('normal and direct-omission updates apply objective clipping once per entry',()=>{
 const {list,q}=setup('Description',50);
 q.SetQuestInfo(1,'Title','Description',true,[pending,pending],0);
 list.Update();
 let calls=0;const apply=q.ApplyHeightLimit;
 q.ApplyHeightLimit=function(...args){calls++;return apply.apply(this,args);};
 list.Update();assert.equal(list.omissionReason,'none');assert.equal(calls,1);
 let allocations=0;list.Array=function(){allocations++;return [];};
 list.PrepareOverflowLabel(list.GetViewportBottom());assert.equal(allocations,0);
 q.ObjectiveItemList[0].TextFieldInstance._width=10000;calls=0;
 list.Update();assert.equal(list.overflowLabel._visible,true);
 assert.match(list.omissionReason,/compact replacement/);assert.equal(calls,1);
 allocations=0;list.PrepareOverflowLabel(list.GetViewportBottom());assert.equal(allocations,0);
});

};
