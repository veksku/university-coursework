--module Zad2 where

-- Zadatak 2:
--
-- Napisati program koji iz fajla čija je putanja data kao argument 
-- komandne linije, čita brojeve jedan po jedan, svaki u zasebnom redu.
-- Program ispisuje sve brojeve poravnate udesno u odnosu na najduži
-- broj, a zatim podvlaku i sumu svih brojeva
--
-- Na primer, za fajl:
--
-- 1020
-- 10
-- 3
-- 8000
-- 2000
-- 1
--
-- Treba ispisati:
--
--      1020
--        10
--         3
--      8000
--      2000
--         1
--     -----
--     11034


-- samo ispisujem zbir

import System.Environment
import Data.Char

main :: IO ()
main = do
	file <- getArgs
	numbers <- mapM readFile file
	print $ sumNumbers <$> numbers

sumNumbers :: String -> Int
sumNumbers str =
	sum
	$ map read
	$ lines
	$ str
