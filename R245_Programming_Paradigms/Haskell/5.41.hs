spoji :: [[a]] -> [a]
spoji [] = []
spoji (x:xs) = x ++ spoji xs
