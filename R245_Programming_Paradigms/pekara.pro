pekara(Vars) :- Vars = [H, K],
	H :: 0..120,
	K :: 0..67,

	10*H + 12*K #=< 1200,
	
	300*H + 120*K #=< 20000,
	
	labeling([maximize(7*H + 9*K)], Vars),
	Zarada is 7*H + 9*K,
	Vreme is H*10 + K*12,
	write('Maks zarada od '), write(Zarada), write(' dinara se ostvaruje za '),
	write(H), write(' komada hleba i '), write(K), write(' komada kifli.'), nl,
	write('Vreme potrebno za ovo sve je bilo: '), write(Vreme), write(' minuta.'),nl.
	
prevede se sa cl('imeprograma.pro')
pokrene se sa pekara(Vars)
