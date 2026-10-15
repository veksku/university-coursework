instance Functor ((,) a) where
    fmap f (x, y) = (x, f y)
