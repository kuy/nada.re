open Obelisk;

let size = 16;

let clear view => {
  PixelView.clear view;
  view
};

let render_stage pile view => {
  let (w, h) = Sandpile.size pile;
  let color = (SideColor.getByInnerColor (SideColor.make ()) ColorPattern._GRAY);
  let dim = BrickDimension.make (size * w) (size * h);
  let brick = Brick.make dim color;

  PixelView.renderObject view (`Brick brick) (Point3D.make 0 0 0);
  view
};

let scale x y z =>
  Point3D.make (size * x) (size * y) (size * z);

let render_stack h (x, y) view => {
  let rec render n =>
    switch n {
      | n when n < h => {
        let color = (CubeColor.getByHorizontalColor (CubeColor.make ()) ColorPattern._BLUE);
        let dim = CubeDimension.make size size size;
        let cube = Cube.make dim color true;

        PixelView.renderObject view (`Cube cube) (scale x y n);
        render (n + 1)
      }
      | _ => ()
    };
  render 0
};

let render_pile pile view => {
  List.iteri (fun y line => List.iteri (fun x h => render_stack h (x, y) view) line) pile;
  view
};

let render view pile => {
  view
  |> clear
  |> render_stage pile
  |> render_pile pile;
};
