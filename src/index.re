open ReasonJs.Dom;
open Obelisk;

Js.log "Hello, Sandpile!";

let canvas = Document.getElementById "stage" document;
Js.log canvas;

let pile = Sandpile.make (5, 5);
Js.log (Sandpile.to_array pile);

let pile2 = Sandpile.incr (4, 4) pile;
Js.log (Sandpile.to_array pile2);

Random.self_init ();
Js.log (Random.int 10);
Js.log (Random.int 10);

switch canvas {
  | None => ()
  | Some el => {
    let base = Point.make 200 200;
    let view = PixelView.make el base;

    Renderer.render view pile;
    ()
  }
};
