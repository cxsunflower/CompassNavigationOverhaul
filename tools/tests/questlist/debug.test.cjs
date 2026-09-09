module.exports = function registerTests(h) {
  const {assert,fs,vm,MovieClip,TextField,QuestItem,context,pending,completed,failed,test,create,near,bottom,originalOrnamentFixture,assertDetailInsideOrnament,setup,shrinkable} = h;

test('dedicated panel lays out long content without any shared HUD atlas or foreign anchor',()=>{
    const {list,q}=setup('Description',850);
    list.Stage.width=512;list.Stage.height=768;
    delete list._root.HUDMovieBaseInstance;
    list.SetPanelSurface();
    q.SetQuestInfo(1,'Title','A longer quest description. '.repeat(8),true,
      [pending,completed,failed,pending,completed,failed],0);
    list.Update();
    assert.equal(list._alpha,100);
    assert.equal(list.anchorText._parent,list._parent);
    assert.ok(q.ObjectiveItemList.every(row=>row._visible));
    assert.equal(q.HasOmittedContent(),false);
    assert.ok(q.GetContentBounds(list._root).yMin>=20);
    assert.ok(q.GetRenderedBottomInSpace(list._root)<=768);
    list.SetLayoutDebug(true);list.Update();
    assert.equal(list.layoutDebugOverlay._parent,list._root);
    assert.equal(list.layoutDebugOverlay.drawnRegions,list.GetLayoutDebugData().regions.length);
    assert.ok(!list.GetLayoutDebugData().regions.some(r=>r.name==='Compass'||r.name==='TargetText'));
    assert.equal(list.GetLayoutDebugVisibility().reason,'dedicated panel');
  });

test('debug drawing supports the real TextField API and finite transformed name corners',()=>{
    const {list,field}=setup('Description',400);
    list._parent._xscale=120;list._parent._yscale=80;list._parent._rotation=17;
    const width=field._width,height=field._height;
    Object.defineProperties(field,{
      _width:{value:width,writable:true},_height:{value:height,writable:true},
      getBounds:{value:undefined},localToGlobal:{value:undefined},globalToLocal:{value:undefined}
    });
    list.SetLayoutDebug(true);
    const target=list.GetLayoutDebugData().regions.find(r=>r.name==='TargetText');
    assert.ok(target);
    const expected=[{x:field._x,y:field._y},{x:field._x+width,y:field._y},
      {x:field._x+width,y:field._y+height},{x:field._x,y:field._y+height}];
    expected.forEach((point,i)=>{
      field._parent.localToGlobal(point);list._root.globalToLocal(point);
      near(target.points[i].x,point.x);near(target.points[i].y,point.y);
    });
    const drawn=list.layoutDebugOverlay.Lines.commands;
    assert.ok(drawn.some(c=>c.op==='stroke'&&c.color===0xFFFF00));
    assert.ok(drawn.some(c=>c.op==='stroke'&&c.color===0xFF3030));
    assert.ok(drawn.filter(c=>c.op==='line'||c.op==='move').every(c=>Number.isFinite(c.x)&&Number.isFinite(c.y)));
    assert.ok(list.GetLayoutDebugState().includes('enabled=true'));
    assert.ok(/drawnRegions=[1-9]/.test(list.GetLayoutDebugState()));
    assert.ok(list.GetAnchorState().includes('layoutDebug=true'));
  });

test('debug overlay is opt-in and never changes normal layout bounds or fit caching',()=>{
    const {list,q}=setup('Description',400);
    list.Update();
    const original=q.GetContentBounds(list._root),runs=list.fitRuns;
    assert.equal(list._root.QuestListLayoutDebugOverlay,undefined);
    list.Update();assert.equal(list.fitRuns,runs);
    list.SetLayoutDebug(true);list.Update();
    const overlay=list.layoutDebugOverlay;
    assert.equal(overlay._parent,list._root);
    assert.equal(overlay.mask,undefined);
    assert.equal(overlay.mouseEnabled,false);
    assert.equal(overlay.tabEnabled,false);
    assert.equal(list.fitRuns,runs);
    const current=q.GetContentBounds(list._root);
    for(const key of ['xMin','yMin','xMax','yMax'])near(current[key],original[key]);
    assert.equal(q.DetailBody.mask,q.DetailContentMask);
    assert.equal(list.mask,list.viewportMask);
    const lines=overlay.Lines.commands.length;
    list.Update();assert.equal(overlay.Lines.commands.length,lines);
    assert.equal(list.fitRuns,runs);
    list.SetLayoutDebug(false);list.Update();
    assert.equal(overlay._visible,false);
    assert.equal(overlay.Lines.drawn.length,0);
    assert.equal(list.layoutDebugEnabled,false);
    assert.equal(list.fitRuns,runs);
  });

test('debug rectangles preserve transformed corners and expose exact root and local sizes',()=>{
    const {list,q}=setup('Description',400);
    list._parent._x=31;list._parent._y=42;list._parent._xscale=120;list._parent._yscale=85;list._parent._rotation=17;
    list.Update();list.SetLayoutDebug(true);list.Update();
    const data=list.GetLayoutDebugData();
    const box=data.regions.find(r=>r.name==='Q0/Box');
    assert.ok(box);
    const expected=q.GetContentBounds(list._root);
    for(const key of ['xMin','yMin','xMax','yMax'])near(box.bounds[key],expected[key]);
    near(box.localWidth,q.DetailBox.layoutWidth);near(box.localHeight,q.DetailBox.layoutHeight);
    assert.ok(Math.abs(box.points[0].y-box.points[1].y)>1,'rotated edge must not be flattened');
    assert.ok(data.regions.some(r=>r.name==='Q0/Header'));
    assert.ok(data.regions.some(r=>r.name==='Q0/Body mask'&&r.color===0x00DDEE));
    assert.ok(data.regions.some(r=>r.name==='Q0/Description'));
    assert.ok(data.regions.some(r=>r.name==='Q0/OBJECTIVES'));
    assert.ok(data.regions.some(r=>r.name==='Q0/Row0'));
    const drawn=list.layoutDebugOverlay.Lines.commands;
    assert.ok(drawn.some(c=>c.op==='stroke'&&c.color===0xFF3030));
    assert.ok(drawn.some(c=>c.op==='line'&&Math.abs(c.y-list.GetViewportBottom())<0.01));
    assert.ok(data.lines.some(s=>s.includes('Full bottom')));
    assert.ok(list.layoutDebugOverlay.Labels.Region0.text.includes('R ('));
    assert.ok(list.layoutDebugOverlay.Labels.Region0.text.includes('L '));
  });

test('omitted rows remain outlined and diagnostic reports hidden HUD and recovery',()=>{
    const {list,q,field}=setup('Description',940);
    q.SetQuestInfo(1,'Title','Description',true,[pending,completed,failed],0);
    list.SetLayoutDebug(true);list.Update();
    assert.ok(list.layoutDebugOverlay._visible);
    const omitted=list.GetLayoutDebugData().regions.filter(r=>r.name.includes('/Row')&&!r.visible);
    assert.ok(omitted.length>0);
    assert.ok(list.layoutDebugOverlay.Lines.commands.some(c=>c.op==='move'));
    const full=q.GetRenderedBottomInSpace(list._root);
    field._y=100;list.Update();
    assert.ok(list.layoutDebugOverlay._visible);
    assert.ok(q.ObjectiveItemList.every(r=>r._visible));
    assert.equal(list.GetLayoutDebugData().regions.filter(r=>r.name.includes('/Row')&&!r.visible).length,0);
    field._y=940-28;list.Update();
    assert.ok(q.HasOmittedContent());
    assert.ok(q.GetRenderedBottomInSpace(list._root)>=full-1);
    list._root.HUDMovieBaseInstance.CompassShoutMeterHolder._alpha=0;list.Update();
    assert.equal(list.layoutDebugOverlay._visible,true);
    assert.equal(list.GetLayoutDebugVisibility().reason,'compass alpha');
    assert.ok(list.GetLayoutDebugState().includes('hudVisible=false'));
    list._root.HUDMovieBaseInstance.CompassShoutMeterHolder._alpha=100;list.Update();
    assert.equal(list.layoutDebugOverlay._visible,true);
    list._parent._visible=false;list.UpdateLayoutDebug();
    assert.equal(list.layoutDebugOverlay._visible,true);
    assert.ok(list.GetLayoutDebugState().includes('hidden ancestor'));
    list._parent._visible=true;list.UpdateLayoutDebug();
    assert.equal(list.layoutDebugOverlay._visible,true);
    assert.equal(list.GetLayoutDebugVisibility().visible,true);
  });

test('enabled diagnostic creates immediately and remains observable without entries or anchor',()=>{
    const {list,q}=setup('Description',400);
    list.SyncQuests([]);
    list.anchorText=undefined;
    const before=list.fitRuns;
    list.SetLayoutDebug(true);
    const overlay=list.layoutDebugOverlay;
    assert.ok(overlay);
    assert.equal(overlay._parent,list._root);
    assert.equal(overlay._visible,true);
    assert.equal(list.GetLayoutDebugVisibility().reason,'no entries');
    assert.ok(list.GetLayoutDebugState().includes('entries=0'));
    assert.ok(overlay.Labels.SummaryText.text.includes('no entries'));
    assert.equal(list.fitRuns,before);
    list.SetLayoutDebug(false);
    assert.equal(overlay._visible,false);
    list.SetLayoutDebug(true);
    assert.equal(list.layoutDebugOverlay,overlay);
    assert.equal(overlay._visible,true);
  });

test('diagnostic visibility never changes original HUD visibility or its layout bounds',()=>{
    const {list,q}=setup('Description',400);
    list.Update();
    const bounds=q.GetContentBounds(list._root);
    list._parent._visible=false;
    list._root.HUDMovieBaseInstance.CompassShoutMeterHolder._alpha=0;
    list.SetLayoutDebug(true);
    assert.equal(list.layoutDebugOverlay._visible,true);
    assert.equal(list._parent._visible,false);
    assert.equal(list._root.HUDMovieBaseInstance.CompassShoutMeterHolder._alpha,0);
    assert.equal(list._alpha,100);
    assert.equal(list.GetLayoutDebugVisibility().reason,'compass alpha');
    const after=q.GetContentBounds(list._root);
    for(const key of ['xMin','yMin','xMax','yMax'])near(after[key],bounds[key]);
    list.SetLayoutDebug(false);
    assert.equal(list.layoutDebugOverlay._visible,false);
  });

test('debug labels are reused, bounded and cleaned up without touching user content',()=>{
    const {list,q,ctx}=setup('Description',400);
    const rows=Array.from({length:40},(_,i)=>({text:'Objective '+i,completed:false,failed:false}));
    q.SetQuestInfo(1,'Title','Description',true,rows,0);
    list.SetLayoutDebug(true);list.Update();
    const overlay=list.layoutDebugOverlay;
    const data=list.GetLayoutDebugData();
    assert.equal(data.totalRows,40);
    assert.equal(data.regions.filter(r=>r.name.includes('/Row')).length,24);
    assert.ok(data.regions.length<=34);
    const labels=overlay.Labels.children.size;
    list.Update();assert.equal(overlay.Labels.children.size,labels);
    q.SetQuestInfo(1,'Title','Short',true,[pending],0);q.dataSignature='v2';list.Update();
    assert.ok(list.layoutDebugLabelCount<labels);
    for(let i=list.layoutDebugLabelCount;i<labels-1;i++)
      assert.equal(overlay.Labels['Region'+i],undefined);
    const count=q.ObjectiveItemList.length;
    list.SetLayoutDebug(false);list.SetLayoutDebug(true);list.Update();
    assert.equal(list.layoutDebugOverlay,overlay);
    assert.equal(q.ObjectiveItemList.length,count);
    vm.runInContext('onUnload()',ctx);
    assert.equal(overlay.removed,true);
    assert.equal(list._root.QuestListLayoutDebugOverlay,undefined);
  });
test('passenger debug uses root coordinates and never draws filled panels',()=>{
  const {list,q}=setup('Description',100);
  list.compassPassengerMode=true;
  list._parent._x=120;list._parent._y=50;
  list._parent._xscale=120;list._parent._yscale=80;list._parent._rotation=7;
  list.Update();list.SetLayoutDebug(true);
  const region=list.GetLayoutDebugData().regions.find(r=>r.name==='Q0/Box');
  const expected={x:q.contentRect.xMin,y:q.contentRect.yMin};
  q.DetailBox.localToGlobal(expected);list._root.globalToLocal(expected);
  near(region.points[0].x,expected.x);near(region.points[0].y,expected.y);
  const overlay=list.layoutDebugOverlay;
  assert.equal(overlay.ClipMask,undefined);
  assert.equal(overlay.Lines.fill,undefined);assert.equal(overlay.Summary.fill,undefined);
  for(const field of overlay.Labels.children.values())assert.equal(field.background,false);
});

test('calibration bypasses masks and fitting, preserves settings and restores normal content',()=>{
  const {list,ctx}=setup('Description',400);
  list.Update();const runs=list.fitRuns,scale=list.TEXT_SCALE,x=list.offsetX,y=list.offsetY;
  list.SetLayoutDebug(true);list.SetCalibration(true,0,700,40,512);list.Update();
  const overlay=list.calibrationOverlay;
  assert.equal(overlay._parent,list._parent);assert.equal(overlay.mask,undefined);
  assert.equal(overlay.fill,undefined);assert.equal(list._alpha,0);
  assert.equal(list.layoutDebugOverlay._visible,false);assert.equal(list.fitRuns,runs);
  assert.equal(overlay.Tick8.text,'Y=1020');
  assert.ok(overlay.commands.some(c=>c.op==='line'&&c.y>942.08));
  list._parent._x=50;list._parent._y=30;list._parent._rotation=13;
  list.Update();const cmd=overlay.commands.find(c=>c.op==='move');
  const point={x:cmd.x,y:cmd.y};overlay.localToGlobal(point);list._root.globalToLocal(point);
  near(point.x,504);near(point.y,700);
  list.SetCalibration(true,1,200,40,860);assert.equal(overlay.Tick0.text,'X=200');
  assert.equal(overlay.children.size,9);
  list.SetCalibration(false,0,700,40,512);assert.equal(overlay.removed,true);
  assert.equal(list._alpha,100);assert.equal(list.TEXT_SCALE,scale);assert.equal(list.offsetX,x);assert.equal(list.offsetY,y);
  list.SetCalibration(true,0,900,2,512);const second=list.calibrationOverlay;
  vm.runInContext('onUnload()',ctx);assert.equal(second.removed,true);
});
};
