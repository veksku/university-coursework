-- Definisati binarno stablo i instancirati
-- Eq, Show (infiksni zapis) i Functor.

data BinaryTree a = 
		Null
	|	Node {l :: BinaryTree a, v :: a, r :: BinaryTree a}

instance Eq a => Eq (BinaryTree a) where
	Null == Null = True
	_ == Null = False
	Null == _ = False
	(Node l1 v1 r1) == (Node l2 v2 r2) =
			v1 == v2
		&&	l1 == l2
		&&	r1 == r2

instance Show a => Show (BinaryTree a) where
	show Null = []
	show (Node l v r) = (show l) ++ " " ++ (show v) ++ " " ++ (show r)

instance Functor BinaryTree where
	fmap f Null = Null
	fmap f (Node l v r) = Node (fmap f l) (f v) (fmap f r)
