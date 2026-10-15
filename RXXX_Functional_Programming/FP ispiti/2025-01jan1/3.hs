-- Definisi strukturu Task gde on moze biti prost ili slozen
-- Prost se sastoji od imena,trajanja i Maybe rok
-- Slozeni isto to samo sto moze imati vise taskova

data Task
	= Prost 
		{ ime :: String
		, trajanje :: Int
		, rok :: Maybe String
		}
	| Slozen
		{ ime :: String
		, opis :: String
		, taskovi :: [Task]
		}
	deriving (Show, Eq)
	
