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
    assert.ok(reduced<limit);
    assert.equal(list.overflowLabel.text,'. . .');
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
      assert.ok(cut<limit);
      assert.ok(list.TextBoundsInRoot(list.overflowLabel).yMax<=list.GetViewportBottom());
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
    assert.ok(reduced<limit);
    assert.ok(q.HasOmittedContent());
    const label=list.TextBoundsInRoot(list.overflowLabel);
    near(label.yMin,list.GetVisibleBottomInRoot(reduced)+4);
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
    assert.equal(list.omissionReason,'preserve readable description');
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
    list.SetOffsets(35,-40);list.FitLayout();
    near(list._x,x+35);near(list._y,y-40);
    list.UpdateAnchor();near(list._x,x+35);near(list._y,y-40);
    const p={x:0,y:0};list.localToGlobal(p);
    list._parent._x+=60;list._parent._y+=10;list.UpdateAnchor();
    const q={x:0,y:0};list.localToGlobal(q);near(q.x-p.x,60);near(q.y-p.y,10);
    list.SetOffsets(0,0);list.FitLayout();near(list._x,x);near(list._y,y);
  });

test('offset setters reject invalid values and clamp to the supported range',()=>{
    const {list}=setup('Description '.repeat(20),500);
    assert.equal(timeline.includes('function SetMaxHeight('),false);
    list.SetOffsets(-50,30);list.SetOffsets(NaN,Infinity);
    assert.equal(list.offsetX,-50);assert.equal(list.offsetY,30);
    list.SetOffsets(999,-999);assert.equal(list.offsetX,100);assert.equal(list.offsetY,-100);
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
  list.SetOffsets(100,100);list.Update();
  assert.ok(list.viewportMask.getBounds(list._root).yMax<=960.001);
  assert.ok(list.viewportMask.getBounds(list._root).yMin>=759.999);
});

test('sampled band contains transformed viewport corners for rotated and scaled parents',()=>{
  for(const rotation of [-12,0,12]) {
    const {list}=setup('Description',50);
    list.compassPassengerMode=true;
    list._parent._y=706.45;list._parent._rotation=rotation;
    list._parent._xscale=110;list._parent._yscale=90;
    for(const offset of [-100,0,100]) {
      list.SetOffsets(offset,offset);list.Update();
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
  assert.ok(list.TextBoundsInRoot(list.overflowLabel).yMax<=limit);
});

};
