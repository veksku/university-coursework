izDekadne :: Int -> Int -> Int
uDekadnu :: Int -> Int -> Int

izDekadne x osn = 
	if x == 0 then 0
	else izDekadne (x `div` osn) osn*10 + (mod x osn) 

uDekadnu x osn = 
	if x == 0 then 0
	else uDekadnu (x `div` 10) osn*osn + (mod x 10)
