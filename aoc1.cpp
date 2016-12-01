//-----------------------------------------------------------------------------
// Advent of Code: Day 1
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <set>

// Directions are listed in the order you'd see if you're turning right from
// north
enum Direction
{
  NORTH,
  EAST,
  SOUTH,
  WEST
};

int posX = 0;
int posY = 0;
std::set<std::pair<int, int>> visitedPositions;

//-----------------------------------------------------------------------------
int
walk(int dirX, int dirY, int numSteps)
{
  while(numSteps > 0)
  {
    --numSteps;

    posX += dirX;
    posY += dirY;

    printf("Current position is (%d, %d), taxicab distance %d\n", posX, posY, abs(posX) + abs(posY));

    auto pos = std::make_pair(posX, posY);
    if (visitedPositions.find(pos) != visitedPositions.end())
    {
      printf("Visited twice\n");
    }
    else
    {
      visitedPositions.insert(pos);
    }
  }
}

//-----------------------------------------------------------------------------
int
main(int argc, char** argv)
{
  Direction currentDirection = NORTH;
  
  // Input is given directly as argv[1], NOT a filename!
  if (argc < 2)
  {
    fprintf(stderr, "Error: Provide input as a command line parameter\n");
    return(1);
  }

  int numSteps;
  std::string input{argv[1]};
  std::string instruction;
  std::stringstream inputstream(input);
  while(std::getline(inputstream, instruction, ','))
  {
    // Trim a single whitespace, if present
    if (instruction.data()[0] == ' ') instruction = instruction.substr(1);

    // Valid instructions are at least two characters
    if (instruction.length() >= 2)
    {
      printf("Processing instruction '%s'\n", instruction.data());
      switch(instruction[0])
      {
        case 'L': currentDirection = static_cast<Direction>((currentDirection + 3) % 4); break;
        case 'R': currentDirection = static_cast<Direction>((currentDirection + 1) % 4); break;
        default:
          fprintf(stderr, "Error: Invalid instruction\n");
          return(1);
      }

      numSteps = atoi(instruction.data() + 1);
      switch(currentDirection)
      {
        case NORTH: walk( 0,  1, numSteps); printf("North %d\n", numSteps); break;
        case EAST:  walk( 1,  0, numSteps); printf("East %d\n",  numSteps); break;
        case SOUTH: walk( 0, -1, numSteps); printf("South %d\n", numSteps); break;
        case WEST:  walk(-1,  0, numSteps); printf("West %d\n",  numSteps); break;
        default:
          fprintf(stderr, "Error: Invalid direction\n");
          return(1);
      }
    }
  }
  
  return(0);
}

