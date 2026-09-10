// Assert the Compass baseline carries the split name/distance scale API.
// Runs against JPEXS-decompiled scripts; checks presence and pass-through,
// not the actual Scaleform renderer or VR presentation.
// Usage: node tools/tests/compass_marker_scale.test.cjs <decompiled-scripts-dir>
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const dir = process.argv[2];
assert.ok(dir, 'usage: compass_marker_scale.test.cjs <decompiled-scripts-dir>');
const timeline = fs.readFileSync(path.join(dir, 'frame_1/DoAction.as'), 'utf8');
const cls = fs.readFileSync(path.join(dir, '__Packages/CompassMarkerInfo.as'), 'utf8');

// 2.12.0 split API on the main timeline.
assert.ok(timeline.includes('function SetMarkerNameScale('), 'timeline SetMarkerNameScale missing');
assert.ok(timeline.includes('function SetMarkerDistanceScale('), 'timeline SetMarkerDistanceScale missing');
assert.ok(timeline.includes('SetNameScale(a_scale)'), 'name scale is not passed through');
assert.ok(timeline.includes('SetDistanceScale(a_scale)'), 'distance scale is not passed through');
// The divide-by-100 bug (text shrunk to 1%) must never return.
assert.ok(!/a_scale\s*\/\s*100/.test(timeline), 'divide-by-100 regressed');
// Class implementations scale the right sub-clips.
assert.ok(cls.includes('function SetNameScale('), 'class SetNameScale missing');
assert.ok(cls.includes('Target.TextFieldInstance._xscale') && cls.includes('Target.TextFieldInstance._yscale'), 'name scale must resize Target');
assert.ok(cls.includes('function SetDistanceScale('), 'class SetDistanceScale missing');
assert.ok(cls.includes('Distance.TextFieldInstance._xscale') && cls.includes('Distance.TextFieldInstance._yscale'), 'distance scale must resize Distance');
// No collateral loss in the two replaced scripts.
for (const name of ['SetMarkers', 'SetFocusedMarkerInfo', 'UpdateFocusedMarker', 'FocusMarker', 'UnfocusMarker', 'SetUnits', 'SetMarkerTextScale']) {
  assert.ok(timeline.includes('function ' + name + '('), 'timeline lost ' + name);
}
for (const name of ['SetTextScale', 'SetDistanceAndHeightDifference']) {
  assert.ok(cls.includes('function ' + name + '('), 'class lost ' + name);
}
assert.ok(/==\s*MarkerUnknownLocation[\s\S]{0,200}gotoAndStop\(3\)/.test(timeline), 'unknown-marker frame-3 fix missing');
// Frame-1 statements kept from the old baseline (main timeline has 2 frames).
assert.ok(timeline.includes('_global.gfxExtensions = true'), 'gfxExtensions flag missing');
assert.ok(timeline.includes('HeightIndicatorInstance.gotoAndStop("Above")'), 'HeightIndicator default frame missing');
assert.ok(/^stop\(\);$/m.test(timeline), 'main timeline must stop on frame 1');
console.log('Compass marker scale API verified.');
// Execute decompiled class behavior, rather than only checking API strings.
const vm = require('node:vm');
function clip(width=100) {
  return {_x:0,_y:0,_xscale:100,_yscale:100,_alpha:100,_visible:true,
    get _height(){return 24*this._yscale/100;},
    localToGlobal(p){p.x=this._x+p.x*this._xscale/100;p.y=this._y+p.y*this._yscale/100;},
    set text(value){
      const previous=this._width;
      width=String(value).length*7+4;
      if(this.autoSize==='center') this._x+=(previous-this._width)/2;
    },
    getBounds(){return {xMin:this._x-this._width/2,xMax:this._x+this._width/2,
      yMin:this._y,yMax:this._y+(this.frame==='Below'?30:24)*this._yscale/100};},
    get _width(){return width*this._xscale/100;}, gotoAndStop(frame){this.frame=frame;}};
}
class MovieClip {
  constructor() {
    this.Target=clip();this.Target.TextFieldInstance=clip(200);
    this.Target.TextFieldInstance._x=-100;
    this.Target.QuestItemList=clip();
    this.Distance=clip();this.Distance.TextFieldInstance=clip(60);
    this.Distance.TextFieldInstance._y=2;
    this.Distance.HeightIndicatorInstance=clip(12);
    this.Distance.HeightIndicatorInstance._xscale=35;
    this.Distance.HeightIndicatorInstance._yscale=35;
    this.Distance.HeightIndicatorInstance._y=5.4;
  }
}
const start=cls.indexOf('function CompassMarkerInfo(');
assert.ok(start>0);
// Do not synthesize implicit member bindings: that concealed the runtime fault.
const body=cls.slice(start);
assert.ok(body.includes('this.NameScale ='), 'scale state must be stored on the instance');
assert.ok(body.includes('this.DistanceScale ='), 'distance state must be stored on the instance');
assert.ok(body.includes('this.ApplyTextScales()'), 'method calls need an explicit receiver');
assert.ok(body.includes('this.Target.TextFieldInstance._xscale'), 'target needs explicit receiver');
assert.ok(body.includes('this.Distance.TextFieldInstance._xscale'), 'distance needs explicit receiver');
const js=(cls.slice(0,start).replace(/^\s*(?:static\s+)?var\s+[A-Za-z_$][\w$]*\s*;\s*$/gm,'')+body)
 .replace(/\bstatic\s+var\s+/g,'static ')
 .replace(/\bfunction\s+CompassMarkerInfo\s*\(\)\s*\{/g,'constructor(){super();')
 .replace(/\bfunction\s+([A-Za-z_$][\w$]*)\s*\(/g,'$1(');
const context=vm.createContext({MovieClip,Math,Number,String,isNaN,isFinite,Stage:{height:1024},_root:{globalToLocal(p){}}});
vm.runInContext(js,context);
const Marker=vm.runInContext('CompassMarkerInfo',context);
const marker=new Marker();
marker.SetNameScale(300);marker.SetDistanceScale(150);
assert.equal(marker.Target.TextFieldInstance._xscale,150);
assert.equal(marker.Distance.TextFieldInstance._xscale,150);
assert.equal(marker.Target._xscale,100);
assert.equal(marker.Target.QuestItemList._xscale,100);
assert.equal(marker.Distance.HeightIndicatorInstance._xscale,52.5);
// Name changes must leave both arrow axes unchanged; only distance controls them.
for (const nameScale of [25, 100, 150]) {
 marker.SetNameScale(nameScale);
 assert.equal(marker.Distance.HeightIndicatorInstance._xscale,52.5);
 assert.equal(marker.Distance.HeightIndicatorInstance._yscale,52.5);
}
marker.SetNameScale(150);
marker.SetDistanceScale(50);
assert.equal(marker.Distance.HeightIndicatorInstance._xscale,17.5);
marker.SetDistanceScale(150);
// Simulate authored parent matrices on every fade frame; text must retain scales.
for(let frame=0;frame<18;frame++){
 marker.Target._xscale=100;marker.Target._yscale=100;marker.Target._y=frame;
 marker.Distance._xscale=100;marker.Distance._yscale=100;marker.Distance._y=-frame;
 marker.onEnterFrame();
 assert.equal(marker.Target.TextFieldInstance._xscale,150);
 assert.equal(marker.Distance.TextFieldInstance._xscale,150);
 assert.equal(marker.Target.TextFieldInstance._x+marker.Target.TextFieldInstance._width/2,0);
 assert.equal(marker.Target._y,frame);
}
marker.SetNameScale(25);marker.SetDistanceScale(300);
assert.equal(marker.Target.TextFieldInstance._xscale,25);
assert.equal(marker.Distance.TextFieldInstance._xscale,150);
marker.SetNameScale(NaN);marker.SetDistanceScale(Infinity);
assert.equal(marker.Target.TextFieldInstance._xscale,25);
assert.equal(marker.Distance.TextFieldInstance._xscale,150);
marker.SetNameScale(900);marker.SetDistanceScale(-1);
assert.equal(marker.Target.TextFieldInstance._xscale,150);
assert.equal(marker.Distance.TextFieldInstance._xscale,25);
marker.UseMetricUnits=true;marker.Movie={_alpha:100};
marker.SetDistanceAndHeightDifference(700,900);
assert.equal(marker.Distance.HeightIndicatorInstance.getBounds().xMin,marker.Distance.TextFieldInstance._x+
 marker.Distance.TextFieldInstance._width+marker.Distance.HeightIndicatorInstance._width/3);
assert.equal(marker.Distance.HeightIndicatorInstance.frame,'Above');
marker.SetDistanceAndHeightDifference(700,-900);
assert.equal(marker.Distance.HeightIndicatorInstance.frame,'Below');
assert.equal(marker.Distance.HeightIndicatorInstance._xscale,8.75);
assert.equal(marker.Distance.HeightIndicatorInstance._yscale,8.75);
// Text width, units, arrow state and repeated scaling must keep one fixed center.
const fixedCenter=marker.DistanceCenter;
for(const metric of [true,false]) {
 marker.UseMetricUnits=metric;
 for(const distance of [7,700,700000]) {
  for(const height of [900,-900,0]) {
   marker.SetDistanceAndHeightDifference(distance,height);
   for(const scale of [25,150,50,100,150]) {
    marker.SetDistanceScale(scale);
    const text=marker.Distance.TextFieldInstance, arrow=marker.Distance.HeightIndicatorInstance;
    const right=arrow._alpha>0?arrow.getBounds().xMax:text._x+text._width;
    assert.ok(Math.abs((text._x+right)/2-fixedCenter)<1e-8,'distance group drifted');
    const left=text._x;
    for(let frame=0;frame<10;frame++) marker.onEnterFrame();
    assert.ok(Math.abs(text._x-left)<1e-8,'centering accumulated across frames');
   }
  }
 }
}
console.log('PASS independent text scales, fade transforms, centering, clamps and arrow layout.');
// A name must never draw its out-of-range first animation frame.
marker.SetNameScale(150);
marker.Target._y=1000;marker.onEnterFrame();
assert.equal(marker.Target.TextFieldInstance._visible,false);
assert.equal(marker.Target.QuestItemList._visible,true);
assert.equal(marker.Target._visible,true);
marker.Target.TextFieldInstance._alpha=0;
marker.Target._y=800;marker.onEnterFrame();
assert.equal(marker.Target.TextFieldInstance._visible,true);
assert.equal(marker.Target.TextFieldInstance._alpha,0,'do not override combat/alpha gating');
marker.Target._y=950;marker.onEnterFrame();assert.equal(marker.Target.TextFieldInstance._visible,false);
marker.Target._y=800;marker.onEnterFrame();assert.equal(marker.Target.TextFieldInstance._visible,true);
assert.ok(timeline.includes('FocusedMarkerInfo.ApplyNameViewportGuard()'));
console.log('PASS name animation boundary guard and restoration without hiding QuestList.');
// Distance is above the navigation icon. Scaling must not move either readout bottom downward.
const anchorMarker=new Marker();
anchorMarker.UseMetricUnits=true;anchorMarker.Movie={_alpha:100};
const field=anchorMarker.Distance.TextFieldInstance;
const arrow=anchorMarker.Distance.HeightIndicatorInstance;
const authoredTextBottom=field._y+field._height;
const authoredArrowY=arrow._y, authoredArrowScaleY=arrow._yscale;
const close=(a,b,message)=>assert.ok(Math.abs(a-b)<1e-7,message+': '+a+' != '+b);
let verticalCases=0;
for(const height of [900,-900,0,900]) {
 for(const distance of [7,700,700000]) {
  anchorMarker.SetDistanceAndHeightDifference(distance,height);
  for(const scale of [100,150,25,125,50,150,100]) {
   anchorMarker.SetDistanceScale(scale);
   close(field._y+field._height,authoredTextBottom,'text bottom intrudes into marker space');
   const authoredArrowBottom=authoredArrowY+(arrow.frame==='Below'?30:24)*authoredArrowScaleY/100;
   close(arrow.getBounds().yMax,authoredArrowBottom,'arrow bottom intrudes into marker space');
   const fieldY=field._y,arrowY=arrow._y;
   for(let frame=0;frame<18;frame++) {
    anchorMarker.Distance._y=-56+frame; // authored parent animation is not ours to overwrite
    anchorMarker.onEnterFrame();
    close(field._y,fieldY,'text Y drifts across frames');
    close(arrow._y,arrowY,'arrow Y drifts across frames');
    close(anchorMarker.Distance._y,-56+frame,'parent timeline position changed');
   }
   if(scale===100) {
    close(field._y,2,'100% authored text Y not restored');
    close(arrow._y,authoredArrowY,'100% authored arrow Y not restored');
   }
   verticalCases++;
  }
 }
}
console.log('PASS '+verticalCases+' distance bottom-anchor cases; authored parent animation and 100% positions preserved.');
