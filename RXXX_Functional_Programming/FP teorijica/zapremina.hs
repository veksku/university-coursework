zapremina :: Double -> Double -> Double
zapremina r h = pi * r2 * h
  where
    r2 = r ^ 2
    
zapremina' :: Double -> Double -> Double
zapremina' r h = 
  let r2 = r ^ 2
  in pi * r2 * h
