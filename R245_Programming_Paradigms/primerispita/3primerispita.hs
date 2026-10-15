otvori :: [(String, Int)] -> String -> [(String, Int)]
zatvori :: [(String, Int)] -> String -> [(String, Int)]
uplati :: [(String, Int)] -> String -> Int -> [(String, Int)]


otvori b br
	| (filter (\(x,y) -> x == br) b) /= [] = b
	| otherwise = (br, 0) : b

{-
zatvori b br
	| filter (\(x,y) -> x == br) b == [] = b
	| otherwise = takeWhile (\(x,y) -> x /= br) b ++ tail(drugideo)
		where drugideo = dropWhile (\(x,y) -> x /= br) b
-}

zatvori [] _ = []
zatvori (x:xs) br = if br == (fst x) then xs else x : zatvori xs br

uplati (x:xs) br iznos = if br == (fst x) then (fst x, (snd x) + iznos) : xs else x : uplati xs br iznos

