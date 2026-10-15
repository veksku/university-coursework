varijacije xs 0 = [[]]
varijacije xs k = concat (map(\ x -> map (x:) ys) xs)
	where ys = varijacije xs (k-1)
