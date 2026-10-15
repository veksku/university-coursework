data Box a = Box a

instance Functor Box where
	fmap f (Box a) = Box (f a)
