podliste :: Int -> [a] -> [[a]]
podliste _ [] = []
podliste n x = take n x : podliste n (drop n x)
