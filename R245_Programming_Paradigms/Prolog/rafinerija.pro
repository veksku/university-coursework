/* pokrece se sa rafinerija(X) */
	
rafinerija(Vars) :- Vars = [B, D],
	B :: 150000..175000,
	D :: 300000..325000,
	
	labeling([maximize(2*B + D)], Vars),
	Zarada is 2*B + D,
	X is B,
	Y is D,
	write('Maksimalna zarada je: '), write(Zarada), write(' dolara'), nl,
	write('Kolicina benzina: '), write(X), write(' galona'), nl,
	write('Kolicina dizela: '), write(Y), write(' galona'), nl.
