ubaci :: Int -> a -> [a] -> [a]
ubaci 0 n l = n : l
ubaci k n [] = [n]
ubaci k n (x:xs) = x : (ubaci (k-1) n xs) 
