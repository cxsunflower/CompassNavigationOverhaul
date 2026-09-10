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
    assert.ok(list.GetDebugObservation().full);
  });

test('ordinary debug is a read-only provider, not a legacy overlay',()=>{
  const {list}=setup('Description',400);
  list.Update();
  const state=[list.fitRuns,list._x,list._y,list._alpha,list.TEXT_SCALE,list.effectiveScale];
  const observation=list.GetDebugObservation();
  assert.ok(observation.full && observation.shown && observation.viewport);
  assert.match(observation.details,/logical-not-UV/);
  list.GetDebugDetails();
  assert.deepEqual([list.fitRuns,list._x,list._y,list._alpha,list.TEXT_SCALE,list.effectiveScale],state);
  assert.equal(list.SetLayoutDebug,undefined);
  assert.equal(list.layoutDebugOverlay,undefined);
});

test('calibration bypasses masks and fitting, preserves settings and restores normal content',()=>{
  const {list,ctx}=setup('Description',400);
  list.Update();const runs=list.fitRuns,scale=list.TEXT_SCALE,x=list.offsetX,y=list.offsetY;
  list.SetCalibration(true,0,700,40,512);list.Update();
  const overlay=list.calibrationOverlay;
  assert.equal(overlay._parent,list._parent);assert.equal(overlay.mask,undefined);
  assert.equal(overlay.fill,undefined);assert.equal(list._alpha,0);
  assert.equal(list.fitRuns,runs);
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
