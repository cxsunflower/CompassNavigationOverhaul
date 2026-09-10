// Tests actual JPEXS-exported observer bytecode via the existing display simulation.
// Does not simulate VR UV mapping, font rendering or the game's native UI thread.
const fs=require('node:fs'),vm=require('node:vm'),assert=require('node:assert/strict');
const {createHarness}=require('./questlist/harness.cjs');
const h=createHarness(process.argv[2],process.argv[3]);
const source=fs.readFileSync(process.argv[4],'utf8');
const start=source.indexOf('var debugEnabled'),end=source.indexOf('_global.gfxExtensions',start);
assert.ok(start>=0&&end>start,'export includes observer');
const debug=source.slice(start,end);
function setup(){
 const fixture=h.setup('description',800);fixture.list.Update();
 const root=fixture.list._root;
 const compass=root.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass;
 const info=compass.createEmptyMovieClip('FocusedMarkerInfo');
 const target=info.createEmptyMovieClip('Target');
 target.add('QuestItemList',fixture.list);target._y=800;
 const distance=info.createEmptyMovieClip('Distance');distance._x=470;distance._y=600;
 distance.createTextField('TextFieldInstance',1,0,0,60,22).text='123 m';
 distance.createEmptyMovieClip('HeightIndicatorInstance')._width=12;distance.HeightIndicatorInstance._height=20;distance.HeightIndicatorInstance._x=70;
 target.createTextField('TextFieldInstance',1,430,0,120,24).text='Test name';
 info.Movie=compass.DirectionRect.createEmptyMovieClip('Marker');info.Movie._x=480;info.Movie._y=640;info.Movie._width=24;info.Movie._height=24;
 info.DistanceScale=150;info.NameScale=100;info._currentframe=12;info._totalframes=22;info.Index=2;
 let clock=0;
 Object.assign(compass,{_root:root,Stage:{width:1024,height:1024},Math,Number,String,Array,isFinite,isNaN,
  TextFormat:class{},flash:{filters:{GlowFilter:class{}}},getTimer:()=>clock});
 const ctx=vm.createContext(compass);vm.runInContext(debug,ctx);
 const tick=(ms=20)=>{clock+=ms;compass.UpdateDebugOverlay();};
 return {...fixture,root,compass,info,distance,target,tick};
}
let count=0;function test(name,fn){fn();console.log('PASS',name);count++;}
test('default-off and source contains no legacy drawing or mutating gameplay methods',()=>{
 const {compass}=setup();assert.equal(compass.debugEnabled,false);assert.equal(compass.debugOverlay,undefined);
 for(const token of ['beginFill(','.gotoAndStop(','.gotoAndPlay(','.setMask(','SetLayoutDebug','UpdateLayoutDebug'])assert.ok(!debug.includes(token),token);
});
test('all seven IDs and short Chinese status; no fill, layout mutation or label overlap',()=>{
 const {compass,list,distance}=setup();const before=[list.fitRuns,list._x,list._y,list._alpha,list.effectiveScale,distance._y];
 compass.SetDebugOverlay(true,false,true);
 assert.deepEqual([list.fitRuns,list._x,list._y,list._alpha,list.effectiveScale,distance._y],before);
 assert.equal(compass.debugOverlay._parent,list._root);
 const fields=compass.debugOverlay.Labels;
 for(const id of 'DHMNQFV')assert.equal(fields['ID'+id].text,id);
 assert.match(fields.Status.text,/距离 150%.*稳定显示/);
 assert.equal(fields.Warning._visible,false);assert.equal(compass.debugOverlay.Lines.fill,undefined);
 const visible=[...fields.children.values()].filter(f=>f._visible);
 for(let i=0;i<visible.length;i++)for(let j=i+1;j<visible.length;j++)assert.equal(compass.DebugOverlap(visible[i].getBounds(list._root),visible[j].getBounds(list._root)),0);
});
test('hidden ancestors, alpha and calibration suppress root overlay without changing HUD',()=>{
 const {compass,tick}=setup();compass.SetDebugOverlay(true,false,false);
 compass._parent._visible=false;tick();assert.equal(compass.debugOverlay._visible,false);assert.equal(compass._parent._visible,false);
 compass._parent._visible=true;compass._parent._alpha=0;tick();assert.equal(compass.debugOverlay._visible,false);
 compass._parent._alpha=100;tick();assert.equal(compass.debugOverlay._visible,true);
 compass.SetDebugOverlay(true,true,false);assert.equal(compass.debugOverlay._visible,false);
 compass.SetDebugOverlay(true,false,false);assert.equal(compass.debugOverlay._visible,true);
});
test('distance observation continues with no quests, and missing objects report n/a',()=>{
 const {compass,list,tick,info}=setup();list.entries=[];compass.SetDebugOverlay(true,false,false);
 assert.equal(compass.debugOverlay.Labels.IDD._visible,true);
 assert.match(compass.DrainDebugLog(),/Q\{exists=true;state=empty-list/);
 assert.equal(compass.DebugNumber(undefined),'n/a');assert.equal(compass.DebugOverlap(undefined,{}),undefined);
 assert.equal(compass.DebugRegion('X',undefined,0,false).reason,'missing');
 info.Distance.HeightIndicatorInstance._alpha=0;tick();assert.match(compass.DrainDebugLog(),/alpha-zero/);
});
test('four corners preserve rotation/reflection and real TextField API',()=>{
 for(const angle of [-35,0,40])for(const scale of [-140,75,130]){
  const {compass,distance}=setup();distance._rotation=angle;distance._xscale=scale;
  const real=distance.TextFieldInstance;
  const field={text:real.text,_parent:distance,_x:real._x,_y:real._y,_width:real._width,_height:real._height,_visible:true,_alpha:100};
  assert.equal(typeof field.localToGlobal,'undefined');
  const region=compass.DebugRegion('D',field,0,false);assert.equal(region.points.length,4);
  const expected={x:field._x,y:field._y};distance.localToGlobal(expected);compass._root.globalToLocal(expected);
  h.near(region.points[0].x,expected.x);h.near(region.points[0].y,expected.y);
  assert.ok(Object.values(region.bounds).every(Number.isFinite));
 }
});
test('logical clipping, thin overlap and no false zero for unavailable geometry',()=>{
 const {compass}=setup();const win=[{x:0,y:0},{x:10,y:0},{x:10,y:10},{x:0,y:10}];
 const clipped=compass.DebugClip([{x:-5,y:5},{x:5,y:-5},{x:15,y:5},{x:5,y:15}],win);
 assert.ok(clipped.every(p=>p.x>=0&&p.y>=0&&p.x<=10&&p.y<=10));
 assert.equal(compass.DebugOverlap({xMin:0,yMin:0,xMax:10,yMax:10},{xMin:9,yMin:2,xMax:15,yMax:8}),1);
 assert.equal(compass.DebugOverlap({xMin:0,yMin:0,xMax:10,yMax:10},{xMin:10,yMin:2,xMax:15,yMax:8}),0);
 const line=compass.DebugClip([{x:-5,y:5},{x:15,y:5}],win);assert.ok(line.length>=2);assert.notDeepEqual(line[0],line[1]);
});
test('warning immediate on overlap; sampled detail bounded; stable state is silent',()=>{
 const {compass,info,distance,tick}=setup();compass.SetDebugOverlay(true,false,false);compass.DrainDebugLog();
 for(let i=0;i<100;i++)tick(20);assert.equal(compass.DrainDebugLog(),'');
 info.Movie._y=610;tick(1);assert.equal(compass.debugOverlay.Labels.Warning._visible,true);assert.match(compass.DrainDebugLog(),/event=transition/);
 let samples=0;for(let i=0;i<100;i++){distance._y-=0.01;tick(10);if(compass.DrainDebugLog())samples++;}assert.ok(samples<=5,samples);
 for(let i=0;i<30;i++){info._currentframe=i%2?2:12;tick(1);}assert.equal(compass.debugQueue.length,12);assert.match(compass.DrainDebugLog(),/droppedSnapshots=/);
});
test('authored phase/reference data, settings snapshot, disable/re-enable cleanup',()=>{
 const {compass,info,tick}=setup();compass.SetDebugOverlay(true,false,false);
 assert.equal(compass.debugTimeline.restFrame,12);assert.equal(compass.debugTimeline.distanceRest.y,-40.7);
 assert.match(compass.DrainDebugLog(),/authored-IdleShow-current-ancestors/);
 info._currentframe=2;tick(1);assert.match(compass.debugOverlay.Labels.Status.text,/淡入中/);assert.match(compass.DrainDebugLog(),/phase=FadeIn/);
 compass.SetDebugOverlay(true,false,true);assert.match(compass.DrainDebugLog(),/event=settings/);
 const old=compass.debugOverlay;compass.SetDebugOverlay(false,false,false);assert.equal(old.removed,true);assert.equal(compass.debugQueue.length,0);
 compass.SetDebugOverlay(true,false,false);assert.notEqual(compass.debugOverlay,old);
});
test('fixed summary never chases animation and hides when unsafe',()=>{
 const {compass,tick,distance}=setup();compass.SetDebugOverlay(true,false,false);
 const status=compass.debugOverlay.Labels.Status;const x=status._x,y=status._y;
 distance._x=x;distance._y=y;tick(1);assert.equal(status._visible,false);
 assert.equal(status._x,x);assert.equal(status._y,y);assert.match(compass.debugSuppressed,/no-safe-fixed-slot/);
});
test('segment clipping retains entering edges in both directions at all four sides',()=>{
 const {compass}=setup();const w={xMin:0,yMin:0,xMax:10,yMax:10};
 for(const [a,b] of [[[-5,5],[5,5]],[[15,5],[5,5]],[[5,-5],[5,5]],[[5,15],[5,5]]]){
  for(const pair of [[a,b],[b,a]]){
   const p=compass.DebugClipLine({x:pair[0][0],y:pair[0][1]},{x:pair[1][0],y:pair[1][1]},w);
   assert.equal(p.length,2);h.near(Math.hypot(p[1].x-p[0].x,p[1].y-p[0].y),5);
  }
 }
 assert.equal(compass.DebugClipLine({x:-5,y:-5},{x:-1,y:-1},w).length,0);
 const lines=setup();lines.compass.SetDebugOverlay(true,false,false);lines.compass.debugOverlay.Lines.clear();
 lines.compass.DebugDraw({reason:'visible',bounds:{},points:[{x:-5,y:5},{x:5,y:5}],color:0xffffff,dash:false});
 assert.ok(lines.compass.debugOverlay.Lines.commands.some(c=>c.op==='line'&&c.x===5&&c.y===5));
});
test('visible list union excludes hidden items and hidden DetailBox, keeps complete F',()=>{
 const {list}=setup();
 function item(show,min,max){return {_visible:show,_alpha:100,_currentframe:1,DetailBox:{_visible:true,_alpha:100},ObjectiveItemList:[],GetContentBounds(){return {xMin:min,yMin:min,xMax:max,yMax:max};},GetRenderedBottomInSpace(){return max+4;},GetVisibleContentBottom(){return max+4;}};}
 list.entries=[item(false,0,40),item(true,100,140)];list.overflowLabel=undefined;
 const o=list.GetDebugObservation();assert.equal(o.shown.xMin,100);assert.equal(o.shown.yMin,100);assert.equal(o.full.xMin,0);
 list.entries[1].DetailBox._alpha=0;assert.equal(list.GetDebugObservation().shownVisible,false);
});
test('empty list preserves object existence and logical V without inventing content',()=>{
 const {list,compass}=setup();list.entries=[];
 const o=list.GetDebugObservation();assert.equal(o.full,undefined);assert.equal(o.shown,undefined);assert.ok(o.viewport);
 compass.SetDebugOverlay(true,false,false);const log=compass.DrainDebugLog();
 assert.match(log,/Q\{exists=true;state=empty-list/);assert.match(log,/V\{exists=true/);
 assert.ok(!log.includes('Q{exists=false'));
});
console.log(`${count} observer regression groups passed (decompiled SWF, not VR rendering).`);
