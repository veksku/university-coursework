izbaci :: Int -> [a] -> [a]
izbaci _ [] = []
izbaci 0 (_:xs) = xs
izbaci k (x:xs) = x : (izbaci (k-1) xs)
