-- Imas fajl i flag u argv, iscitaj fajl
-- i u zavisnosti od flaga odredi:
-- broj karaktera, broj reci
-- broj linija ili duzina najduze linije

import System.Environment

main :: IO ()
main = do
	args <- getArgs
	let 
		file = args !! 0
		flag = args !! 1
	contents <- readFile file
	case flag of
		"c" -> print (countChars contents)
		"w" -> print (countWords contents)
		"l" -> print (countLines contents)
		"m" -> print (maxLine contents)
		_ -> putStrLn ("Nepoznat flag: " ++ flag)

countChars :: String -> Int
countChars = length

countWords :: String -> Int
countWords = length . words

countLines :: String -> Int
countLines = length . lines

maxLine :: String -> Int
maxLine = maximum . map length . lines
