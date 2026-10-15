module Lib where
import Data.Char
import Data.Int
import Data.Maybe

data Poklapanje = MkPoklapanje {kar :: Char, poz :: Int} deriving Show

get_kar :: Poklapanje -> Char
get_kar poklapanje = kar poklapanje
   
get_poz :: Poklapanje -> Int
get_poz poklapanje = poz poklapanje

poklapanjeShow :: Poklapanje -> String
poklapanjeShow p = [kar p] ++ " (" ++ show (poz p) ++ ")"

poklapanjeM :: Int -> String -> Maybe Poklapanje
poklapanjeM i str = if length(str) < i then Nothing else Just (MkPoklapanje (str!!i) i)

poklapanjeE :: Int -> String -> Either String Poklapanje
poklapanjeE i str = if length(str) < i then Left $ "Greska" else Right $ (MkPoklapanje (str!!i) i)

pronadjiM :: Poklapanje -> String -> Maybe Bool
pronadjiM p str = if length(str)>=i then Just (if str!!i == char then True else False) else Nothing
        where i = poz p
              char = kar p

pronadjiE :: Poklapanje -> String -> Either String Bool
pronadjiE p str = if length(str)>=i then Right $ (if str!!i == char then True else False) else Left $ "Greska"
        where i = poz p
              char = kar p
