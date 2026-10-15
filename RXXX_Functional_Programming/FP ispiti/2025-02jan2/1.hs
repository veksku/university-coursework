-- Napraviti tip aritmeticki izraz koji moze biti
--  varijabla, konstanta, mnozenje i sabiranje.
-- Instancirati funktor tako da primeni fmap f na
-- konstante. Napisati funkciju eval koja dobije
-- listu ("varname", vrednost) i  izraz i evaluira
-- za date vrednosti, ako neka var nema vrednost
-- podrazumevati 1.

data Izraz a
	= Varijabla String
	| Konstanta a
	| Mnozenje (Izraz a) (Izraz a)
	| Sabiranje (Izraz a) (Izraz a)

instance Functor Izraz where
	fmap f (Konstanta k) = Konstanta (f k)
	
eval :: Num a => [(String, a)] -> Izraz a -> a
eval _ (Konstanta k) = k
eval vname (Varijabla v) = maybe 1 id (lookup v vname)
eval vname (Mnozenje e1 e2) = eval vname e1 * eval vname e2
eval vname (Sabiranje e1 e2) = eval vname e1 + eval vname e2
