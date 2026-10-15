difference :: Eq a => [a] -> [a] -> [a]
difference x y = filter (`notElem` y) x
