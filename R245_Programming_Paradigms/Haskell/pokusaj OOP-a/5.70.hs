
data Krug = MkKrug { radijus :: Float }

data Pravougaonik = MkPravougaonik {a :: Float, b :: Float}

instance Show Krug where
	show (MkKrug r) = show r
	
instance Show Pravougaonik where
	show (MkPravougaonik a b) = show a + " " + show b
	
instance Eq Krug where
	s1 == s2 = (radijus s1) == (radijus s2)
	
instance Eq Pravougaonik where
  (==) (MkPravougaonik a1 b1) (MkPravougaonik a2 b2) =
  	a1 == a2 && b1 == b2 || a1 == b2 && b1 == a2
