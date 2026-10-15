-- Napraviti tip survey koji ima ime i odgovore,
-- odgovor moze biti binarni (da/ne), multichoice
-- i slobodan tekst, moze i da nema odgovor

data Answer 
	= Binarni Bool
	| Multichoice Int
	| FreeText String
	| NoAnswer
	deriving (Show, Eq)

data Survey = Survey
	{ ime :: String
	, odgovori :: [Answer]
	} deriving (Show, Eq)
	
	
