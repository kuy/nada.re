open ReasonJs.Dom;
open Obelisk;

Js.log "Hello, Sandpile!";

let canvas = Document.getElementById "stage" document;
Js.log canvas;

let pile = [(0, 0), (0, 0), (1, 0), (3, 0), (2, 2), (1, 3), (4, 4)]
  |> List.fold_left (fun pile pos => Sandpile.incr pos pile) (Sandpile.make (5, 5));
Js.log (Sandpile.to_array pile);

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
