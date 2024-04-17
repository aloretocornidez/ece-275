#!/usr/bin/env wolframscript
(* ::Package:: *)

(* Set the Recursion limit to infinity (defaults to 1024) *)
$RecursionLimit = Infinity;

(* Get command line arguments *)
argv = Rest @ $ScriptCommandLine;
argc = Length @ argv;

(* Function to calculate Ackerman Numbers *)
Ackermann[0, n_] := n + 1;
Ackermann[m_, 0] := Ackermann[m-1, 1]
Ackermann[m_, n_] := Ackermann[m-1, Ackermann[m, n-1]]

m = argv[[1]]
n = argv[[2]]
ans = Ackermann[m, n]
res = "Ackerman["<>ToString[i]<>"]["<>ToString[j]<>"] = "<> ToString[ans];
Print[res]
