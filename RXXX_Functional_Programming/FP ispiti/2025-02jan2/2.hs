-- Ucitava se proizvoljan broj fajlova kao argumenti
-- komandne linije i racuna se prosek brojeva u
-- svakom fajlu

import System.Environment

main :: IO ()
main = do
	files <- getArgs
	contents <- mapM readFile files
	let averages = zip files (map average contents)
	mapM_ (\(f, avg) -> putStrLn (f ++ ": " ++ show avg)) averages
	
average :: String -> Double
average str =
	let nums = map read (lines str) :: [Double]
	in sum nums / fromIntegral (length nums)
