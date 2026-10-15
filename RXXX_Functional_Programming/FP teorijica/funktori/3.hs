data Pair a = Pair a a

instance Functor Pair where
	fmap f (Pair x y) = Pair (f x) (f y)
