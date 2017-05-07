open ReasonJs.Dom;
open Obelisk;

Js.log "Hello, Sandpile!";

let canvas = Document.getElementById "stage" document;
Js.log canvas;

switch canvas {
  | None => ()
  | Some el => {
    let base = Point.make 200 200;
    let view = PixelView.make el base;

    let color = (SideColor.getByInnerColor (SideColor.make ()) ColorPattern._GRAY);
    let dim = BrickDimension.make 160 160;
    let brick = Brick.make dim color;

    PixelView.renderObject view brick (Point3D.make 0 0 0);

    ()
  }
};
