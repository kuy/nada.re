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

let make (w, h) =>
  (w * h)
  |> ListX.zero
  |> ListX.chunk w;

let clear (x, y) pile =>
  List.mapi (fun row line => List.mapi (fun col c => row == y && col == x ? 0 : c) line) pile;

let incr (x, y) pile =>
  List.mapi (fun row line => List.mapi (fun col c => row == y && col == x ? c + 1 : c) line) pile;

let avalanche_cell (x, y) pile =>
  pile
  |> clear (x, y)
  |> incr (x, y - 1)
  |> incr (x + 1, y)
  |> incr (x, y + 1)
  |> incr (x - 1, y);

let avalanche pile => {
  pile
  |> List.mapi (fun row line => List.mapi (fun col c => c < 4 ? (false, (col, row)) : (true, (col, row))) line)
  |> List.fold_left (fun acc line => List.append acc line) []
  |> List.filter (fun (over, _) => over)
  |> List.map (fun (_, pos) => pos)
  |> List.fold_left (fun pl pos => avalanche_cell pos pl) pile
};

let size pile =>
  switch pile {
    | [] => (0, 0)
    | [hd, ...tl] => (List.length hd, List.length pile)
  };

let to_array pile =>
  Array.of_list pile |> Array.map (fun lst => Array.of_list lst);
