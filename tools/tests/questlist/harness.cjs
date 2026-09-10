// Shared AS2 display-list simulation. No game renderer or VR UV behavior is mocked.
const assert = require('node:assert/strict');
const fs = require('node:fs');
const vm = require('node:vm');

function createHarness(itemPath, timelinePath) {
class MovieClip {
  constructor() {
    this._x = 0; this._y = 0; this._xscale = 100; this._yscale = 100;
    this._rotation = 0; this._alpha = 100; this._visible = true;
    this._rect = {xMin: 0, yMin: 0, xMax: 0, yMax: 0};
    this.children = new Map(); this.depth = 0; this.filters = [];
    if (new.target.name === 'QuestItem') this.makeTitle();
  }
  get _width() { const b = this.getBounds(this); return b.xMax - b.xMin; }
  set _width(v) { this._rect.xMax = this._rect.xMin + v; }
  get _height() { const b = this.getBounds(this); return b.yMax - b.yMin; }
  set _height(v) { this._rect.yMax = this._rect.yMin + v; }
  setMask(mask) { this.mask = mask; }
  clear() { if(process.env.CNO_TRACE)console.log('TRACE clear',this._name);this.drawn=[]; this.commands=[]; this._rect={xMin:0,yMin:0,xMax:0,yMax:0}; }
  getNextHighestDepth() { return ++this.depth; }
  add(name, child) {
    child._parent = this; child._name = name; this.children.set(name, child);
    this[name] = child; return child;
  }
  createEmptyMovieClip(name) { return this.add(name, new MovieClip()); }
  createTextField(name, depth, x, y, width, height) {
    const field = this.add(name, new TextField());
    field._x = x; field._y = y; field._width = width; field._height = height;
    return field;
  }
  attachMovie(name, instance) {
    if (!MovieClip.linkages.has(name)) return undefined;
    const clip = this.add(instance, new MovieClip());
    const size = name === 'QuestObjectivesDivider' ? [481.25, 14.85] : [18, 27];
    clip._width = size[0]; clip._height = size[1];
    clip.linkage = name; return clip;
  }
  removeMovieClip() {
    if (this._parent) {
      this._parent.children.delete(this._name);
      delete this._parent[this._name];
    }
    this.removed = true;
  }
  gotoAndStop(frame) {
    const frames = {Main: 1, Misc: 6, 'longest name': 12};
    this._currentframe = typeof frame === 'number' ? frame : (frames[frame] || 1);
    this.playing = false;
  }
  gotoAndPlay(frame) { this.gotoAndStop(frame); this.playing = true; }
  lineStyle(width, color) { this.stroke = {width, color}; if(!this.commands)this.commands=[];this.commands.push({op:'stroke',width,color}); }
  beginFill(color) { this.fill = color; }
  endFill() {}
  moveTo(x, y) { if(process.env.CNO_TRACE&&this._name==='ClipMask')console.log('TRACE mask move',x,y);if(!this.commands)this.commands=[];this.commands.push({op:'move',x,y});this.drawPoint(x, y); }
  lineTo(x, y) { if(!this.commands)this.commands=[];this.commands.push({op:'line',x,y});this.drawPoint(x, y); }
  drawPoint(x, y) {
    if (!this.drawn) this.drawn = [];
    if (this.drawn.length > 10000) throw new Error('Diagnostic simulation exceeded 10000 drawing points: '+this._name);
    this.drawn.push({x, y});
    if (this.drawn.length === 1) this._rect = {xMin:x, yMin:y, xMax:x, yMax:y};
    this._rect.xMin = Math.min(this._rect.xMin, x);
    this._rect.yMin = Math.min(this._rect.yMin, y);
    this._rect.xMax = Math.max(this._rect.xMax, x);
    this._rect.yMax = Math.max(this._rect.yMax, y);
  }
  forward(p) {
    const x = p.x * this._xscale / 100, y = p.y * this._yscale / 100;
    const a = this._rotation * Math.PI / 180, c = Math.cos(a), s = Math.sin(a);
    return {x:this._x + x*c - y*s, y:this._y + x*s + y*c};
  }
  inverse(p) {
    const x = p.x - this._x, y = p.y - this._y;
    const a = this._rotation * Math.PI / 180, c = Math.cos(a), s = Math.sin(a);
    return {x:(x*c + y*s) * 100 / this._xscale,
      y:(-x*s + y*c) * 100 / this._yscale};
  }
  localToGlobal(p) {
    let q = {...p};
    for (let clip = this; clip; clip = clip._parent) q = clip.forward(q);
    p.x = q.x; p.y = q.y; return p;
  }
  globalToLocal(p) {
    const chain = []; for (let clip = this; clip; clip = clip._parent) chain.push(clip);
    let q = {...p}; for (const clip of chain.reverse()) q = clip.inverse(q);
    p.x = q.x; p.y = q.y; return p;
  }
  getBounds(target) {
    const boxes = [];
    if (this._rect.xMax > this._rect.xMin && this._rect.yMax > this._rect.yMin) boxes.push(this._rect);
    for (const child of this.children.values()) boxes.push(child.getBounds(this));
    const points = [];
    for (const b of boxes) for (const [x,y] of [[b.xMin,b.yMin],[b.xMax,b.yMin],[b.xMin,b.yMax],[b.xMax,b.yMax]]) {
      const p = {x,y}; this.localToGlobal(p); target.globalToLocal(p); points.push(p);
    }
    if (!points.length) return {xMin:0,yMin:0,xMax:0,yMax:0};
    return {xMin:Math.min(...points.map(p=>p.x)), yMin:Math.min(...points.map(p=>p.y)),
      xMax:Math.max(...points.map(p=>p.x)), yMax:Math.max(...points.map(p=>p.y))};
  }
  makeTitle() {
    // Match the compiled wrapper: the original symbol is an unchanged Header
    // and the outer DetailBox is the target of the original timeline.
    const box = this.createEmptyMovieClip('DetailBox');
    const title = box.createEmptyMovieClip('Header');
    this.Title = title;
    title.createTextField('TitleTextField', 1, 20, 0, 160, 22);
    const bracket = title.createEmptyMovieClip('Bracket'); bracket._width = 20; bracket._height = 22;
    const end = title.createEmptyMovieClip('EndPiece');
    end._x = 180; end._width = 20; end._height = 22; end.createEmptyMovieClip('SideArt');
  }
}
MovieClip.linkages = new Set();

class TextField extends MovieClip {
  // AS2 displayed width/height include the field transform. Text metrics stay local.
  get _width() { return (this._rect.xMax-this._rect.xMin)*Math.abs(this._xscale)/100; }
  set _width(v) { this._rect.xMax=this._rect.xMin+v*100/Math.abs(this._xscale); }
  get _height() { return (this._rect.yMax-this._rect.yMin)*Math.abs(this._yscale)/100; }
  set _height(v) { this._rect.yMax=this._rect.yMin+v*100/Math.abs(this._yscale); }
  removeTextField() { this.removeMovieClip(); }
  constructor() { super(); this.text = ''; this.format = {size:16, bold:false, color:0xffffff}; }
  getTextFormat() { return {...this.format}; }
  setNewTextFormat(f) { this.format = {...f}; }
  setTextFormat(f) { this.format = {...f}; }
  get textHeight() {
    const size = Number(this.format.size) || 16;
    const chars = Math.max(1, Math.floor(Math.max(1,this._rect.xMax-this._rect.xMin-4)/(size*0.55)));
    const lines = String(this.text).split('\n').reduce((n,s)=>n+Math.max(1,Math.ceil(s.length/chars)),0);
    return Math.ceil(lines*size*1.15);
  }
  get textWidth() { return Math.max(...String(this.text).split('\n').map(s=>s.length))*((Number(this.format.size)||16)*0.55); }
}

// JPEXS emits untyped AS2 class declarations; translate only that syntax.
const raw = fs.readFileSync(itemPath, 'utf8');
const constructorStart = raw.indexOf('function QuestItem(');
assert.ok(constructorStart > 0, 'QuestItem constructor not found');
// Remove AS2 class-field declarations only. Local var declarations must stay:
// JPEXS often declares a local before assigning it later in the method.
const js = (raw.slice(0, constructorStart).replace(/^\s*(?:static\s+)?var\s+[A-Za-z_$][\w$]*\s*;\s*$/gm, '')
  + raw.slice(constructorStart))
  .replace(/\bfunction\s+QuestItem\s*\(/g, 'constructor(')
  .replace(/\bfunction\s+([A-Za-z_$][\w$]*)\s*\(/g, '$1(');
const context = vm.createContext({MovieClip, TextField, Math, Number, String, Object, Array,
  isNaN, isFinite, flash:{filters:{GlowFilter:class {constructor(...args){this.args=args;}}}}});
vm.runInContext(js, context, {filename:'compiled-QuestItem.as'});
const QuestItem = vm.runInContext('QuestItem', context);
const pending = {text:'Talk to the steward', completed:false, failed:false};
const completed = {text:'Find the key', completed:true, failed:false};
const failed = {text:'Failed optional objective', completed:false, failed:true};
const tests = [];
function test(name, fn) { tests.push({name, fn}); }
function create(description, objectives, type=1) {
  const item = new QuestItem(); item.SetQuestInfo(type,'Test quest',description,true,objectives,0); return item;
}
function near(a,b) { assert.ok(Math.abs(a-b)<0.001, `${a} != ${b}`); }
function bottom(clip) { const p={x:0,y:clip.contentHeight||clip._height};clip.localToGlobal(p);return p.y; }

// Geometry measured from the immutable QuestItemListArt.original.swf and its
// QuestTitle placement. The real title field spans only the ornament's gap.
function originalOrnamentFixture(q) {
  const title=q.Title, bracket=title.Bracket, end=title.EndPiece;
  const field=title.TitleTextField;
  field._x=51.4;field._y=4.7;field._width=237.95;field._height=32.7;
  bracket._x=217.05;bracket._y=18.5;bracket._xscale=124.07227;bracket._yscale=124.07227;
  bracket._rect={xMin:-172.8547,yMin:-8,xMax:30.4154,yMax:14.4};
  end._x=296.15;end._y=17;end._xscale=125.75073;end._yscale=106.57959;
  end._rect={xMin:-1.9,yMin:-2.9,xMax:158.8,yMax:40.3};
}

function assertDetailInsideOrnament(q) {
  const title=q.Title, safe=q.detailBounds, box=q.DetailBox, body=q.DetailBody;
  const bracket=q.TitleBracket.getBounds(title), end=q.TitleEndPiece.getBounds(title);
  const outerLeft=Math.min(bracket.xMin,end.xMin),outerRight=Math.max(bracket.xMax,end.xMax);
  const mask=q.DetailContentMask.getBounds(box);
  assert.ok(safe.xMin>=outerLeft+7.9 && safe.xMax<=outerRight-7.9);
  assert.ok(mask.xMin>=outerLeft+3.9 && mask.xMax<=outerRight-3.9);
  near(mask.xMin,body._x-4);near(mask.xMax,body._x+body.layoutWidth+4);
  near(mask.yMin,body._y-4);near(mask.yMax,body._y+body.layoutHeight+4);
  assert.equal(body.mask,q.DetailContentMask);
  assert.equal(box.Header,title);
  assert.equal(title._parent,box);
  assert.equal(body._parent,box);
  assert.equal(q.DetailContentMask._parent,box);
  assert.equal(title.mask,undefined);
  assert.equal(box.mask,undefined);
  assert.equal(box._rect.xMax,0,'Box must not draw or set its own width');
  assert.equal(box._xscale,100);assert.equal(box._yscale,100);
  near(box.layoutLeft,safe.outerLeft-4);
  near(box.layoutWidth,safe.outerRight-safe.outerLeft+8);
  near(box.layoutTop,q.naturalLayout.top);
  near(box.layoutHeight,q.contentRect.yMax-q.contentRect.yMin);
  assert.ok(body.layoutWidth>0 && body.layoutWidth<=q.naturalLayout.width);
  assert.ok(body.layoutHeight>=0);
  assert.equal(q.DescriptionTextField._parent,body);
  const field=q.DescriptionTextField;
  near(field._x,0);near(field._width,body.layoutWidth);
  near(field._y,0);
  if(q.ObjectivesHeader) {
    const header=q.ObjectivesHeader,label=header.Label,art=header.Art;
    assert.equal(header._parent,body);
    near(header._x,0);
    assert.ok(label._x>=-0.001 && label._x+label._width<=body.layoutWidth+0.001);
    const leftWing=art.Left.Mask || art.Left, rightWing=art.Right.Mask || art.Right;
    near(leftWing._width,rightWing._width);
    assert.ok(art.Left._x>=-0.001);
    assert.ok(art.Right._x+rightWing._width<=body.layoutWidth+0.001);
    assert.equal(q.ObjectiveContainer._parent,body);
    for(const row of q.ObjectiveItemList) {
      const text=row.TextFieldInstance;
      near(row._x,0);near(text._x,26);
      near(text._width,body.layoutWidth-26);
      assert.ok(row._x+text._x+text._width<=body.layoutWidth+0.001);
      assert.ok(row._x+row.StateIcon._x-4>=-4.001);
      assert.ok(row._x+row.StateIcon._x+row.StateIcon._width+4<=body.layoutWidth+4.001);
    }
  }
  near(q.contentRect.xMin,safe.outerLeft-4);
  near(q.contentRect.xMax,safe.outerRight+4);
  near(q.contentRect.yMax,Math.max(q.naturalLayout.bottom,body._y+body.layoutHeight));
  const actual=q.GetDetailBoxBounds(box);
  near(actual.xMin,box.layoutLeft);near(actual.xMax,box.layoutLeft+box.layoutWidth);
  near(actual.yMin,box.layoutTop);near(actual.yMax,box.layoutTop+box.layoutHeight);
}


  const timeline = timelinePath ? fs.readFileSync(timelinePath,'utf8') : undefined;
  const timelineFunctions = timeline ? Array.from(timeline.matchAll(/^function\s+([A-Za-z_$][\w$]*)\s*\(/gm), m=>m[1]) : [];
  function setup(description,top=500) {
    const root=new MovieClip(), parent=root.createEmptyMovieClip('Target');
    const list=parent.createEmptyMovieClip('QuestItemList');
    const field=parent.createTextField('TextFieldInstance',1,412,top-28,200,22);
    const q=create(description,[pending]);list.add('quest0',q);q.dataSignature='v1';q.ageIndex=0;
    const hud=root.createEmptyMovieClip('HUDMovieBaseInstance');
    const holder=hud.createEmptyMovieClip('CompassShoutMeterHolder');
    const compass=holder.createEmptyMovieClip('Compass');
    compass.createEmptyMovieClip('DirectionRect')._width=300;
    compass.DirectionRect._height=32;
    Object.assign(list,{entries:[q],anchorText:field,anchorGap:6,Stage:{width:1024,height:1024},
      overflowLabel:undefined,TextFormat:class {},flash:{filters:{GlowFilter:class {}}},viewportMask:undefined,entriesByKey:{},_root:root,SCALE:65,TEXT_SCALE:110,offsetX:0,offsetY:0,fitKey:'',fitRuns:0,
      effectiveScale:110,effectiveWidth:1,fitGeometry:'',fitReason:'not fitted',fitOverflow:false,
      omissionReason:'none',omissionLimit:0,lastSafeLimit:0,lastVisibleBottom:0,
      calibrationEnabled:false,calibrationAxis:0,calibrationStart:700,calibrationStep:40,calibrationCross:512,calibrationOverlay:undefined,
      dedicatedPanel:false,
      compassPassengerMode:false,compassPassengerConfig:{width:320,height:220,offsetX:40,offsetY:40,scale:110,minScale:90},
      Math,Number,String,isNaN,isFinite});
    const configMatch=timeline.match(/(?:var\s+)?compassPassengerConfig\s*=\s*(\{[^}]+\})/);
    assert.ok(configMatch,'compiled passenger contract');
    list.compassPassengerConfig=vm.runInNewContext('('+configMatch[1]+')');
    const ctx=vm.createContext(list);
    for(const name of timelineFunctions) {
      const start=timeline.indexOf('function '+name+'(');assert.ok(start>=0,name);
      const brace=timeline.indexOf('{',start);let depth=1,end=brace+1;
      for(;depth&&end<timeline.length;end++) {if(timeline[end]==='{')depth++;if(timeline[end]==='}')depth--;}
      vm.runInContext(timeline.slice(start,end),ctx);
    }
    if(process.env.CNO_TRACE)for(const name of ['FitLayout','GetDebugObservation']){
      const original=list[name];
      if(typeof original==='function')list[name]=function(...args){console.log('TRACE begin',name,args[0]&&args[0].name,args[0]&&args[0].bounds);const result=original.apply(this,args);console.log('TRACE end',name,result&&result.bounds,result&&result.signature&&result.signature.length);return result;};
    }
    return {list,q,field,ctx};
  }
  function shrinkable() {
    for(let n=2;n<100;n++) {
      const result=setup('Very long description '.repeat(n),760);
      result.list.FitLayout();
      if(!result.list.fitOverflow && result.list.effectiveScale>=90 && result.list.effectiveScale<108) return result;
    }
    throw Error('no fixture fitting in automatic shrink range');
  }

  function run() {
    let passed=0;
    for(const {name,fn} of tests) {
      if(process.env.CNO_TEST_FILTER && !name.includes(process.env.CNO_TEST_FILTER))continue;
      try { fn(); passed++; console.log('PASS',name); }
      catch(error) { console.error('FAIL',name,'\n',error.stack); process.exitCode=1; }
    }
    console.log(`${passed}/${tests.length} layout/state simulation tests passed`);
  }
  return {assert,fs,vm,MovieClip,TextField,QuestItem,context,timeline,pending,completed,failed,
    test,create,near,bottom,originalOrnamentFixture,assertDetailInsideOrnament,setup,shrinkable,run};
}
module.exports = {createHarness};
