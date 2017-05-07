open Obelisk;

let size = 16;

let clear view => {
  PixelView.clear view;
  view
};

let render_stage view => {
  let color = (SideColor.getByInnerColor (SideColor.make ()) ColorPattern._GRAY);
  let dim = BrickDimension.make (size * 10) (size * 10);
  let brick = Brick.make dim color;

  PixelView.renderObject view (`Brick brick) (Point3D.make 0 0 0);
  view
};

let render_cell pile (x, y) view => {
  let color = (CubeColor.getByHorizontalColor (CubeColor.make ()) ColorPattern._BLUE);
  let dim = CubeDimension.make size size size;
  let cube = Cube.make dim color true;
  Js.log cube;

  PixelView.renderObject view (`Cube cube) (Point3D.make 0 0 0);
  view
};

let render_pile pile view => {
  render_cell pile (0, 0) view;
  view
};

let render view pile => {
  view
  |> clear
  |> render_stage
  |> render_pile pile;
};
