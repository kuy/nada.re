open ReasonJs.Dom;
open Obelisk;

let size = 10;

Random.self_init ();
let random_pos () => (Random.int size, Random.int size);

switch (Document.getElementById "stage" document) {
  | None => ()
  | Some canvas => {
    let base = Point.make 200 200;
    let view = PixelView.make canvas base;

    let rec update pile => {
      let next = pile
        |> Sandpile.avalanche
        |> Sandpile.incr (random_pos ());
      Renderer.render view next;

      Js.Global.setTimeout (fun () => update next) 250;
      ()
    };
    update (Sandpile.make (size, size))
  }
};
