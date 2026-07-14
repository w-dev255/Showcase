import System.Process (callCommand)
import Text.Read (readMaybe)

isNumber :: String -> Bool
isNumber s =
   case readMaybe s :: Maybe Double of
      Just _ -> True
      Nothing -> False

clearScreen :: IO ()
clearScreen = callCommand "clear"

sign d
  | d > 0 = "Everyone should give: "
  | otherwise = ""

add :: Double -> Double -> Double
add a b = a + b

sub :: Double -> Double -> Double
sub a b = a - b

mul :: Double -> Double -> Double
mul a b = a * b

division :: Double -> Double -> Double
division a b = a / b

loop :: IO ()
loop = do
  putStrLn "Mode: "
  input <- getLine
  if input == "quotes" then do
       putStrLn "Full price: "
       input <- getLine
       if isNumber input then do
              let a = read input :: Double
              putStrLn "Quotes ammount: "
              input <- getLine
              if isNumber input then do
                    let b = read input :: Double
                    putStrLn "How many people: "
                    input <- getLine
                    if isNumber input then do
                          let c = read input :: Double
                          let d = (a - b) / c
                          putStrLn (sign d ++ show d ++ "$")
                          putStrLn "Now: "
                          cmd <- getLine
                          if cmd == "exit" then
                                putStrLn "goodbye" 
                          else do 
                                clearScreen 
                                loop
                    else do
                          clearScreen
                          loop
              else do
                    clearScreen
                    loop
       else do
             clearScreen
             loop
  else if input == "calculator" then do
       putStrLn "Operation: "
       input <-getLine
       if input == "add" then do
              putStrLn "A value: "
              input <- getLine
              if isNumber input then do
                    let a = read input :: Double
                    putStrLn "B value: "
                    input <- getLine
                    if isNumber input then do
                          let b = read input :: Double
                          let c = add a b
                          print ("result: " ++ show c)
                          loop
                    else do
                          clearScreen
                          loop
              else do
                    clearScreen
                    loop
       else if input == "sub" then do
             putStrLn "A value: "
             input <- getLine
             if isNumber input then do
                   let a = read input :: Double
                   putStrLn "B value: "
                   input <- getLine
                   if isNumber input then do
                         let b = read input :: Double
                         let c = sub a b
                         print ("Result: " ++ show c)
                         loop
                   else do
                         clearScreen
                         loop
             else do
                   clearScreen
                   loop
       else if input == "mul" then do
             putStrLn "A value: "
             input <- getLine
             if isNumber input then do
                   let a = read input :: Double
                   putStrLn "B value: "
                   input <- getLine
                   if isNumber input then do
                         let b = read input :: Double
                         let c = mul a b
                         print ("Result: " ++ show c)
                         loop
                   else do
                         clearScreen
                         loop
             else do
                   clearScreen
                   loop
       else if input == "division" then do
             putStrLn "A value: "
             input <- getLine
             if isNumber input then do
                   let a = read input :: Double
                   putStrLn "B value: "
                   input <- getLine
                   if isNumber input then do
                         let b = read input :: Double
                         if b /= 0 then do
                               let c = division a b
                               print ("Result: " ++ show c)
                               loop
                         else do
                               clearScreen
                               loop
                   else do
                         clearScreen
                         loop
             else do
                   clearScreen
                   loop
       else do
             clearScreen
             loop            
  else if input == "exit" then
       putStrLn "Goodbye"
  else do
        clearScreen
        loop
          
main :: IO ()
main = loop
