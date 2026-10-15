poslednji :: [a] -> a
poslednji l = l !! poz
	where poz = length(tail l)
