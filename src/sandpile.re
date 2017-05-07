module ListX = {
  let zero len => {
    let rec loop acc n =>
      switch n {
        | 0 => acc
        | n => loop [0, ...acc] (n - 1)
      };
    loop [] len
  };

  let chunk len lst => {
    let rec loop acc lst =>
      switch lst {
        | [] => acc
        | [x, ...xs] =>
          switch acc {
            | [hd, ...rst] when (List.length hd) < len => loop [[x, ...hd], ...rst] xs
            | _ => loop [[x], ...acc] xs
          }
      };
    loop [[]] lst |> List.rev |> List.map (fun l => List.rev l)
  };
};

type t = list (list int);

let make (w, h) =>
  (w * h)
  |> ListX.zero
  |> ListX.chunk w;

let incr (x, y) pile =>
  List.mapi (fun row line => List.mapi (fun col c => row == y && col == x ? c + 1 : c) line) pile;

let decr (x, y) pile =>
  List.mapi (fun row line => List.mapi (fun col c => row == y && col == x ? c - 1 : c) line) pile;

let size pile =>
  switch pile {
    | [] => (0, 0)
    | [hd, ...tl] => (List.length hd, List.length pile)
  };

let to_array pile =>
  Array.of_list pile |> Array.map (fun lst => Array.of_list lst);
