include "globals.mzn";

int: n = 10;
array[1..n,1..n] of var (1..n): M;
constraint forall(i in 2..n) (sum([M[i,j] | j in 1..n]) > sum([M[i-1,j] | j in 1..n]));
% constraint forall(i in 2..n) (sum(row(M, i)) > sum(row(M, i-1)));
solve satisfy;