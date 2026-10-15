prost :: Int -> Bool
prost n = prostTest n 2
	where prostTest n k
		| n == k = True
		| n `mod` k == 0 = False
		| otherwise = prostTest n (k+1)
