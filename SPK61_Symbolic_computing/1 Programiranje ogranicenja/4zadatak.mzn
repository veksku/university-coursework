include "globals.mzn";

int: n=8;
int: k=7;
array [1..n] of var {0,1}: x;
constraint forall(i in 1..n) (atmost(1,[x[j] | j in 1..k],1));
constraint x != [0, 0, 0, 0, 0, 0, 0, 0];
constraint x != [1, 0, 0, 0, 0, 0, 0, 0];
constraint x != [0, 1, 0, 0, 0, 0, 0, 0];
constraint x != [0, 0, 1, 0, 0, 0, 0, 0];
constraint x != [0, 0, 0, 1, 0, 0, 0, 0];
constraint x != [0, 0, 0, 0, 1, 0, 0, 0];
constraint x != [0, 0, 0, 0, 0, 1, 0, 0];
constraint x != [0, 0, 0, 0, 0, 0, 1, 0];
constraint x != [0, 0, 0, 0, 0, 0, 0, 1];
solve satisfy;