glava :: [a] -> a
glava (x:_) = x

rep :: [a] -> [a]
rep (_:xs) = xs
