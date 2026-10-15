-- Imena fajlova se daju kao argumenti komandne linije
-- i učitava se reč sa stdin-a. Prebrojati pojavljivanje
-- te reči u fajlovima.

import System.Environment
import Data.Char

main :: IO ()
main = do
	files <- getArgs
	word <- getLine
	contents <- mapM readFile files
	print $ sum $ countWords word <$> contents
	
countWords :: String -> String -> Int
countWords word str =
		length
	$	filter (== word)
	$	words
	$ 	filter (\ x -> isLetter x || (isSpace x))
	$	toLower
	<$> str
