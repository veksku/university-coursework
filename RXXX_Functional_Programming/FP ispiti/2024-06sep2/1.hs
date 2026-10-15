-- Napisati tip Stream a koji ce primati beskonacno elemenata tipa a.
-- Napisati i fromList:: [a] -> Stream a,
-- kao i toList:: Stream a -> [a].
-- Napisati i Show tako da ako gledamo da je ovo lista [1..100],
-- da ispisuje samo prvih 10 el, tj [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
-- Instancirati Funktor i Applicative.

data Stream a = Stream a (Stream a)

fromList :: [a] -> Stream a
fromList [] = error "Lista za stream mora biti beskonacna"
fromList (x:xs) = Stream x (fromList xs)

toList :: Stream a -> [a]
toList (Stream x xs) = x : toList xs

instance Show a => Show (Stream a) where
	show s = show prvih10
		where prvih10 = take 10 (toList s)

instance Functor Stream where
	fmap f (Stream x xs) = Stream (f x) (fmap f xs)
	
instance Applicative Stream where
	pure x = Stream x (pure x)
	(Stream f fs) <*> (Stream g gs) = Stream (f g) (fs <*> gs)
