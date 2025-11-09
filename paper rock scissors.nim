import std/random
import strutils

randomize()

echo "Welcome to rock, paper, scissors!!"
echo "Game ends when the first get's 3 points!!"


echo "Press 0. to play rock"
echo "Press 1. to play paper"
echo "Press 2. to play scissors"

let botChoice: int = rand(0..2)

var playerChoice: string = readLine(stdin)
let playerChoiceInt = playerChoice.parseInt()

if playerChoiceInt < 0 or playerChoiceInt > 2:
  echo "Please insert a valid choice!"
else:
  echo "Bot chose: ", botChoice

  if botChoice == playerChoiceInt:
    echo "It's a tie!"
  elif botChoice == 0 and playerChoiceInt == 1:
    echo "Bot chose rock..."
    echo "You won!"
  elif botChoice == 0 and playerChoiceInt == 2:
    echo "Bot chose rock..."
    echo "You lost!"
  elif botChoice == 1 and playerChoiceInt == 0:
    echo "Bot chose paper..."
    echo "You lost!"
  elif botChoice == 1 and playerChoiceInt == 2:
    echo "Bot chose paper..."
    echo "You won!"
  elif botChoice == 2 and playerChoiceInt == 0:
    echo "Bot chose scissors..."
    echo "You won!"
  elif botChoice == 2 and playerChoiceInt == 1:
    echo "Bot chose scissors..."
    echo "You lost!"
