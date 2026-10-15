parni :: Int -> Int -> [Int]
neparni :: Int -> Int -> [Int]

parni a b = [x | x <- [a..b], even x]
neparni a b = [x | x <- [a..b], odd x]
