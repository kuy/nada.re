open ReasonJs.Dom;
open Obelisk;

Random.self_init ();

let interval = 200;
let size = (20, 20);
let seed = 500;

switch (Document.getElementById "stage" document) {
  | None => ()
  | Some canvas => {
    let base = Point.make 400 60;
    let view = PixelView.make canvas base;

    let rec update pile => {
      let cells = Sandpile.unstables pile;
      let next = switch (List.length cells) {
        | 0 => Sandpile.drop pile
        | _ => Sandpile.flatten_all cells pile
      };

      Renderer.render view next;

      Js.Global.setTimeout (fun () => update next) interval;
      ()
    };
    update (Sandpile.make size |> Sandpile.drop n::seed)
  }
};
