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

  let empty lst => List.length lst == 0;
};

type t = list (list int);

let size pile =>
  switch pile {
    | [] => (0, 0)
    | [hd, ...tl] => (List.length hd, List.length pile)
  };

let make (w, h) =>
  (w * h)
  |> ListX.zero
  |> ListX.chunk w;

let clear (x, y) pile =>
  List.mapi (fun row line => List.mapi (fun col c => row == y && col == x ? 0 : c) line) pile;

let incr (x, y) pile =>
  List.mapi (fun row line => List.mapi (fun col c => row == y && col == x ? c + 1 : c) line) pile;

let flatten (x, y) pile =>
  pile
  |> clear (x, y)
  |> incr (x, y - 1)
  |> incr (x + 1, y)
  |> incr (x, y + 1)
  |> incr (x - 1, y);

let flatten_all cells pile =>
  List.fold_left (fun pl pos => flatten pos pl) pile cells;

let unstables pile =>
  pile
  |> List.mapi (fun row line => List.mapi (fun col c => (c >= 4, (col, row))) line)
  |> List.flatten
  |> List.filter (fun (s, _) => s)
  |> List.map (fun (_, pos) => pos);

let random_cell (w, h) =>
  (Random.int w, Random.int h);

let rec drop ::n=1 pile =>
  switch n {
    | 0 => pile
    | n => drop n::(n - 1) (incr (random_cell (size pile)) pile)
  };

let to_array pile =>
  Array.of_list pile |> Array.map (fun lst => Array.of_list lst);
