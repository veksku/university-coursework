kvadriraj :: Integral a => [a] -> [a]
kvadriraj = map (^2) . filter even
