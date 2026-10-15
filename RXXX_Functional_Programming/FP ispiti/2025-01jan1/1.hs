-- Definisi tip Kutija koji moze biti prazan ili 
-- neprazan, kada je neprazan ima vrednost a i neki string
-- Instancirati Show tako da ukoliko nije prazan prikaze
-- vrednost u suprotnom ispisuje </>
-- Instancirati Functor i Applicative (pure ima tekst pure)

data Kutija a = Empty
			| Full a String
			
instance Show a => Show (Kutija a) where
	show Empty = "</>"
	show (Full v str) = (show v) ++ " (" ++ str ++ ") "
	
instance Functor Kutija where
	fmap f Empty = Empty
	fmap f (Full a str) = Full (f a) str

instance Applicative Kutija where
	pure v = Full v "pure"
	Empty <*> _ = Empty
	_ <*> Empty = Empty
	(Full f tag1) <*> (Full v tag2) = Full (f v) (tag1 ++ tag2)
