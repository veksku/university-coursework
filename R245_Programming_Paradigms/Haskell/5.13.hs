ceoDeo :: Int -> Int
ceoDeo x = ceoDeo' x 1
		where	ceoDeo' x i
				| (i*i) > x = (i-1)
				| otherwise = ceoDeo' x (i+1)
