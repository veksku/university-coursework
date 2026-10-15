quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = quicksort manji ++ [x] ++ quicksort veci
  where
    manji = [a | a <- xs, a <= x]
    veci = [a | a <- xs, a > x]
