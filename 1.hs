main :: IO()
main = do 
  print $ foldl (+) 0 [x|x<-[1..1000-1], x `mod` 3 == 0 || x `mod` 5 ==0]