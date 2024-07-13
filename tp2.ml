(* Course      : Functional and Logical Programming *)
(* Course Code : INF6120 *)
(* Group       : 020 *)
(* Semester    : Summer 2024 *)
(* Author      : Zakariae Bouargan (BOUZ90340206) *)


module Utils = Utils

module Atom = struct
  type t = string list

  let to_string (atom : t) : string =
    String.concat " " atom

  let of_string (s : string) : t =
    String.split_on_char ' ' s
end


module System = struct
  type t = {
    iterations : int;
    angle : float;
    init : Atom.t;
    rules : (string * Atom.t) list;
  }

exception InvalidSystem of string

  let map_result f lst =
  let rec aux acc = function
    | [] -> Ok (List.rev acc)
    | x :: xs ->
      match f x with
      | Ok res -> aux (res :: acc) xs
      | Error e as err -> err
  in
  aux [] lst

  let parse_rule line =
    match String.split_on_char ':' line with
    | [left; right] -> Ok (String.trim left, Atom.of_string (String.trim right))
    | _ -> Error ("Failed to parse rule line: " ^ line)

  let parse_header headers key =
    try
      Ok (List.assoc key headers)
    with Not_found -> Error ("Key not found: " ^ key)
    
let of_string (s : string) : (t, string) result =
  try
    let lines = String.split_on_char '\n' s |> List.filter (fun line -> line <> "") in
    let headers, rule_lines = List.partition (fun line -> not (String.contains line ':')) lines in
    let parsed_headers = List.map (fun line ->
      match String.split_on_char '=' line with
      | [left; right] -> Ok (String.trim left, String.trim right)
      | _ -> Error "Failed to parse header line"
    ) headers in
    match List.fold_left (fun acc h -> match h, acc with
      | Ok h, Ok acc -> Ok (h :: acc)
      | Error e, _ | _, Error e -> Error e) (Ok []) parsed_headers with
    | Error e -> Error e
    | Ok headers ->
      let rules_result = map_result parse_rule rule_lines in
      (match rules_result with
      | Error e -> Error e
      | Ok rules ->
        (try
          let iterations = List.assoc "iterations" headers |> int_of_string in
          let angle = List.assoc "angle" headers |> float_of_string in
          let init = Atom.of_string (List.assoc "init" headers) in
          Ok { iterations; angle; init; rules }
        with
        | Not_found -> Error "Required configuration missing"
        | Failure _ -> Error "Numeric conversion failed"))
  with
    | _-> InvalidSystem -> Error "An unspecified system error occurred"

  (* Apply the rules to an atom for a given number of iterations *)
  let apply_rules (rules : (string * Atom.t) list) (atom : Atom.t) : Atom.t =
  List.flatten (List.map (fun symbol ->
    match List.assoc_opt symbol rules with
    | Some replacement -> replacement
    | None -> [symbol]
  ) atom)

  let apply ?iterations (system : t) : Atom.t =
  let iters = match iterations with
    | Some i -> i
    | None -> system.iterations
  in
  let rec iter n atom =
    if n <= 0 then atom
    else iter (n - 1) (apply_rules system.rules atom)
  in
  iter iters system.init


  let draw ?(iterations=None) ?(angle=None) (system : t) : Utils.Canvas.t =
  let actual_angle = Option.value angle ~default:system.angle in
  let iters = Option.value iterations ~default:system.iterations in
  let atom = apply ~iterations:iters system in  (* Adjusted this line *)
  let rec draw_atom (atom : Atom.t) (current_pos : float * float) current_angle lines stack =
    match atom with
    | [] -> lines
    | "F" :: rest ->
      let rad = current_angle *. (Float.pi /. 180.0) in
      let new_x = fst current_pos +. 10.0 *. cos rad in
      let new_y = snd current_pos +. 10.0 *. sin rad in
      let new_line = { Utils.Line.origin = { Utils.Coord.x = fst current_pos; y = snd current_pos };
                       destination = { Utils.Coord.x = new_x; y = new_y } } in
      draw_atom rest (new_x, new_y) current_angle (new_line :: lines) stack
    | "-" :: rest -> draw_atom rest current_pos (current_angle -. actual_angle) lines stack
    | "+" :: rest -> draw_atom rest current_pos (current_angle +. actual_angle) lines stack
    | "[" :: rest -> draw_atom rest current_pos current_angle lines ((current_pos, current_angle) :: stack)
    | "]" :: rest ->
      let (saved_pos, saved_angle) = List.hd stack in
      let remaining_stack = List.tl stack in
      draw_atom rest saved_pos saved_angle lines remaining_stack
    | _ :: rest -> draw_atom rest current_pos current_angle lines stack
  in
  let lines = draw_atom atom (0.0, 0.0) 0.0 [] [] in
  let bounds = List.fold_left (fun (min_x, min_y, max_x, max_y) line ->
    let { Utils.Coord.x = x1; y = y1 } = line.Utils.Line.origin in
    let { Utils.Coord.x = x2; y = y2 } = line.Utils.Line.destination in
    (min min_x x1, min min_y y1, max max_x x2, max max_y y2)
  ) (Float.infinity, Float.infinity, Float.neg_infinity, Float.neg_infinity) lines in
  let (min_x, min_y, max_x, max_y) = bounds in
  { Utils.Canvas.topleft = { Utils.Coord.x = min_x; y = min_y };
    bottomright = { Utils.Coord.x = max_x; y = max_y };
    lines = List.rev lines }


end
