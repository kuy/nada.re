type color = int;

module ColorPattern = {
  external _BLACK: color = "BLACK" [@@bs.scope "ColorPattern"] [@@bs.module "obelisk.js"] [@@bs.val];
  external _GRAY: color = "GRAY" [@@bs.scope "ColorPattern"] [@@bs.module "obelisk.js"] [@@bs.val];
  external _BLUE: color = "BLUE" [@@bs.scope "ColorPattern"] [@@bs.module "obelisk.js"] [@@bs.val];
  external _YELLOW: color = "YELLOW" [@@bs.scope "ColorPattern"] [@@bs.module "obelisk.js"] [@@bs.val];
};

module SideColor = {
  type t;
  /* FIXME: Incorrect signature */
  external make: unit => t =
    "SideColor" [@@bs.module "obelisk.js"] [@@bs.new];
  external getByInnerColor: t => color => t = "" [@@bs.send];
};

module CubeColor = {
  type t;
  external make: border::color? => borderHighlight::color? => left::color? => right::color? => horizontal::color? => unit => t =
    "CubeColor" [@@bs.module "obelisk.js"] [@@bs.new];
  external getByHorizontalColor: t => color => t = "" [@@bs.send];
};

module Point = {
  type t;
  external make: int => int => t =
    "Point" [@@bs.module "obelisk.js"] [@@bs.new];
  external to_s: t => string = "toString" [@@bs.send];
};

module Point3D = {
  type t;
  external make: int => int => int => t =
    "Point3D" [@@bs.module "obelisk.js"] [@@bs.new];
  external x: t => int = "" [@@bs.get];
  external y: t => int = "" [@@bs.get];
  external z: t => int = "" [@@bs.get];
  external to_s: t => string = "toString" [@@bs.send];
};

module BrickDimension = {
  type t;
  external make: int => int => t =
    "BrickDimension" [@@bs.module "obelisk.js"] [@@bs.new];
};

module Brick = {
  type t;
  external make: BrickDimension.t => SideColor.t => t =
    "Brick" [@@bs.module "obelisk.js"] [@@bs.new];
};

module CubeDimension = {
  type t;
  external make: int => int => int => t =
    "CubeDimension" [@@bs.module "obelisk.js"] [@@bs.new];
};

module Cube = {
  type t;
  external make: CubeDimension.t => CubeColor.t => bool => t =
    "Cube" [@@bs.module "obelisk.js"] [@@bs.new];
};

module PixelView = {
  type t;
  external make: Dom.element => Point.t => t =
    "PixelView" [@@bs.module "obelisk.js"] [@@bs.new];

  /* FIXME */
  external renderObjectBrick: t => Brick.t => Point3D.t => unit = "renderObject" [@@bs.send];
  external renderObjectCube: t => Cube.t => Point3D.t => unit = "renderObject" [@@bs.send];
  let renderObject view obj pos => 
    switch obj {
      | `Brick o => renderObjectBrick view o pos
      | `Cube o => renderObjectCube view o pos
    };

  external clear: t => unit = "" [@@bs.send];
};
