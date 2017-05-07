module ColorPattern = {
  type t;
  external _GRAY: t = "GRAY" [@@bs.scope "ColorPattern"] [@@bs.module "obelisk.js"] [@@bs.val];
};

module SideColor = {
  type t;
  /* FIXME: Incorrect signature */
  external make: unit => t =
    "SideColor" [@@bs.module "obelisk.js"] [@@bs.new];
  external getByInnerColor: t => ColorPattern.t => t = "" [@@bs.send];
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

module PixelView = {
  type t;
  external make: Dom.element => Point.t => t =
    "PixelView" [@@bs.module "obelisk.js"] [@@bs.new];
  external renderObject: t => Brick.t => Point3D.t => unit = "" [@@bs.send];
  external clear: t => unit = "" [@@bs.send];
};
