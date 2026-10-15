zbircifara :: Integral a => a -> a
zbircifara x
  | x < 0 = zbircifara (-x)
  | x < 10 = x
  | otherwise = x `mod` 10 + zbircifara (x `div` 10)
