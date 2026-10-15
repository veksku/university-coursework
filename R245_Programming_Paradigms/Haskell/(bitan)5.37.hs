bezbedanRep1 :: [a] -> [a]
bezbedanRep1 xs = if null xs then [] else tail xs

bezbedanRep2 :: [a] -> [a]
bezbedanRep2 xs
	| null xs = []
	| otherwise = tail xs
	
bezbedanRep3 :: [a] -> [a]
bezbedanRep3 [] = []
bezbedanRep (_:xs) = xs
