open ReasonJs.Dom;
open Obelisk;

Random.self_init ();
let random_pos () => (Random.int 5, Random.int 5);

switch (Document.getElementById "stage" document) {
  | None => ()
  | Some canvas => {
    let base = Point.make 200 200;
    let view = PixelView.make canvas base;

    let rec update pile => {
      let next = Sandpile.incr (random_pos ()) pile;
      Renderer.render view next;

      Js.Global.setTimeout (fun () => update next) 500;
      ()
    };
    update (Sandpile.make (5, 5))
  }
};
