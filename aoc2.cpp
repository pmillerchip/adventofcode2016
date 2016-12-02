//-----------------------------------------------------------------------------
// Advent of Code: Day 2
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

int currentX = 0;
int currentY = 2;

const int keypad[] = { 0x0, 0x0, 0x1, 0x0, 0x0,
                       0x0, 0x2, 0x3, 0x4, 0x0,
                       0x5, 0x6, 0x7, 0x8, 0x9,
                       0x0, 0xa, 0xb, 0xc, 0x0,
                       0x0, 0x0, 0xd, 0x0, 0x0 };

//-----------------------------------------------------------------------------
// Get a key from the keypad at the given coordinate. Returns 0 if invalid.
int
getKeypad(int x, int y)
{
  if ((x > -1) && (y > -1) && (x < 5) && (y < 5))
    return(keypad[(y * 5) + x]);

  return(0);
}

//-----------------------------------------------------------------------------
void
processLine(const std::string line)
{
  int nextX;
  int nextY;
  int nextNum;
  for(auto c : line)
  {
    nextX = currentX;
    nextY = currentY;
    switch(c)
    {
      case 'L': nextX = currentX - 1; break;
      case 'R': nextX = currentX + 1; break;
      case 'U': nextY = currentY - 1; break;
      case 'D': nextY = currentY + 1; break;
    }

    nextNum = getKeypad(nextX, nextY);
    if (nextNum > 0)
    {
      // Valid key
      currentX = nextX;
      currentY = nextY;
    }
  }

  printf("%x", getKeypad(currentX, currentY));
}

//-----------------------------------------------------------------------------
int
main(int argc, char** argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s <input filename>\n", argv[0]);
    return(1);
  }

  printf("The code is: ");
  std::ifstream file(argv[1]);
  std::string line; 
  while (std::getline(file, line))
  {
    processLine(line);
  }
  printf("\n");

  return(0);
}

