pozicije :: Eq a => a -> [a] -> [Int]
pozicije x [] = []
pozicije x lista = [i | (x1, i) <- zip lista [0..n], x == x1]
	where n = length lista - 1
