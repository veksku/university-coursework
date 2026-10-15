module Lib where
import Data.Char
import Data.List.Split

najduza :: [String] -> String
najduza [x] = x 
najduza (x:xs) = if length(x) >= length(najduza(xs)) then x else najduza(xs)

umanji :: String -> String
--umanji x = [toLower lowstr | lowstr <- x]
umanji (x:xs) = if null xs then [toLower x] else [toLower x] ++ umanji xs

razdvoj :: Char -> String -> [String]
--razdvoj sep str = [takeWhile(/=sep) (str)]
razdvoj sep str = splitOn [sep] str

spoj :: String -> [String] -> String
spoj sep [x] = x
spoj sep (x:xs) = x ++ sep ++ (spoj sep xs)
