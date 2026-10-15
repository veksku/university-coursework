parovi :: Int -> Int -> Int -> Int -> [(Int,Int)]
parovi a b c d = [(x, y) | x <- [a..b], y <- [c..d]]
