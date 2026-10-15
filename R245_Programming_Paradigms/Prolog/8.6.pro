maksimum(A,B,M) :- A>=B, M is A.
maksimum(A,B,M) :- A<B, M is B.

suma(1,1).
suma(N,S) :- N>1, N1 is N-1, suma(N1,S1), S is S1+N.

sumaParnih(2,2).
sumaParnih(N,S) :- N>2, N1 is N-2, sumaParnih(N1,S1), S is S1+N.

proizvod(1,1).
proizvod(N,P) :- N>1, N1 is N-1, proizvod(N1, S1), S is S1+N.
