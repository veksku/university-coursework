firstAndLast :: [a] -> Maybe (a, a)
firstAndLast [] = Nothing
firstAndLast x = Just (head x, last x)
