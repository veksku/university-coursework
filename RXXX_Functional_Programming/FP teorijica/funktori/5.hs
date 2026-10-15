data Trio a = Trio a a a

instance Functor Trio where
	fmap f (Trio x y z) = Trio (f x) (f y) (f z)
