-- Uraditi tako da ucitavamo reci iz vise
-- fajlova (./Main 1.txt 2.txt) i da pronadjemo
-- najkracu i najduzu rec od svih reci iz svih fajlova. 
-- Ispisati:
-- min: najkraca_rec
-- max: najduza_rec

import System.Environment
import Data.List
import Data.Ord

main :: IO ()
main = do
    files    <- getArgs
    contents <- mapM readFile files
    let allWords = concatMap words contents
        shortest = minimumBy (comparing length) allWords
        longest  = maximumBy (comparing length) allWords
    putStrLn ("min: " ++ shortest)
    putStrLn ("max: " ++ longest)
