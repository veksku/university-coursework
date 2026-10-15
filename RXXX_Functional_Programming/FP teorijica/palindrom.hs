palindrom :: Eq a => [a] -> Bool
palindrom x
  | length x <= 1 = True
  | head x /= last x = False
  | otherwise = palindrom (init (tail x))
