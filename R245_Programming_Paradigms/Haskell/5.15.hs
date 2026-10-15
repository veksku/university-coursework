delioci n
	| n == 1 = [1]
	| otherwise = delioci' n 2
	where delioci' n k
			| k == n = []
			| n `mod` k == 0 = [k] ++ (delioci' n (k+1))
			| otherwise = delioci' n (k+1)
