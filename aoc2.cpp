//-----------------------------------------------------------------------------
// Advent of Code: Day 2
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

int currentX = 0;
int currentY = 2;

int keypad[] = { 0x0, 0x0, 0x1, 0x0, 0x0,
                 0x0, 0x2, 0x3, 0x4, 0x0,
                 0x5, 0x6, 0x7, 0x8, 0x9,
                 0x0, 0xa, 0xb, 0xc, 0x0,
                 0x0, 0x0, 0xd, 0x0, 0x0 };

//-----------------------------------------------------------------------------
void
processLine(const char* line)
{
  unsigned int i = 0;
  int nextX;
  int nextY;
  while(line[i] != '\0')
  {
    nextX = currentX;
    nextY = currentY;
    switch(line[i])
    {
      case 'L': nextX = currentX - 1; break;
      case 'R': nextX = currentX + 1; break;
      case 'U': nextY = currentY - 1; break;
      case 'D': nextY = currentY + 1; break;
    }

    if ((nextX > -1)
     && (nextY > -1)
     && (nextX < 5)
     && (nextY < 5))
    {
      // Next move is in the square, is it valid?
      int nextNum = keypad[(nextY * 5) + nextX];
      if (nextNum != 0)
      {
        // Valid key
        currentX = nextX;
        currentY = nextY;
      }
    }

    ++i;
  }

  printf("%x", keypad[(nextY * 5) + nextX]);
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
    processLine(line.data());
  }
  printf("\n");

  return(0);
}

