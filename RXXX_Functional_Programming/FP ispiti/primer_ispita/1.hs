module Zad1 where

-- Zadatak 1:
--
-- Definisati tip podataka `Point2D` koji se može konstruisati 
-- putem konstruktora `MkPoint2D` i koji se sastoji od atributa:
--  * `x` (tipa `Double`) koje predstavlja x-koordinatu tačke 
--  * `y` (tipa `Double`) koje predstavlja y-koordinatu tačke 

data Point2D = MkPoint2D {x :: Double, y :: Double} deriving (Show)

instance Eq Point2D where
	(==) p1 p2 = x p1 == x p2 && y p1 == y p2

-- Definisati tip podataka `Rectangle` koji se može konstruisati 
-- putem konstruktora `MkRectangle` i koji se sastoji od atributa:
--  * `bott_left` (tipa `Point2D`) koje predstavlja teme A pravougaonika 
--  * `top_right` (tipa `Point2D`) koje predstavlja teme C pravougaonika
-- (pretpostaviti da su stranice pravougaonika paralelene koordinatnim osama)
--
--             D     (C)
--
--            (A)     B
--

data Rectangle = MkRectangle {bott_left :: Point2D, top_right :: Point2D} deriving (Show)

instance Eq Rectangle where
	(==) r1 r2 = 
		(bott_left r1 == bott_left r2 && top_right r1 == top_right r2) ||
		(bott_left r1 == top_right r2 && top_right r1 == bott_left r2)

-- Definisati klasu `Traversible a` koja sadrži funkciju
-- `traverse :: a -> [Point2D]`
--

class Traversible a where
	traverse :: a -> [Point2D]

-- Instancirati `Traversible` za `Rectangle` tako da funkcija `traverse`
-- vrati listu [A,B,C,D]
--

instance Traversible Rectangle where
	traverse r = [a, b, c, d]
		where
			a = bott_left r
			c = top_right r
			b = MkPoint2D { x = x c, y = y a }
			d = MkPoint2D { x = x a, y = y c }

--
-- Definisati funkciju `rotTrans rect` koja rotira pravougaonik za 90 stepeni
-- u smeru kazaljke na satu ali tako da teme B dođe na mesto temena A 
-- (kao na slici ispod) i vraća dobijeni pravougaonik:
--
--            | D     (C)         | A   (D)
--            |             ->    |
--            |(A)     B          |(B)   C
--            ````````````        ``````````
--

rotTrans_rect :: Rectangle -> Rectangle
rotTrans_rect r = MkRectangle { bott_left = b, top_right =  d} 
	where
		[a, b, c, d] = Zad1.traverse r

--
-- Napisati QuickCheck test koji testira funkciju `rotTrans`. 
-- Pomoc: Iskoristiti činjenicu da dva puta primenjena rotacija na ovakav
--        nacin predstavlja identitet.
--

quickCheck :: Rectangle -> Bool
quickCheck r = r == (rotTrans_rect . rotTrans_rect) r
