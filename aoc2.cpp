//-----------------------------------------------------------------------------
// Advent of Code: Day 2
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

int currentX = 1;
int currentY = 1;

//-----------------------------------------------------------------------------
void
processLine(const char* line)
{
  unsigned int i = 0;
  while(line[i] != '\0')
  {
    switch(line[i])
    {
      case 'L': if (currentX > 0) --currentX; break;
      case 'R': if (currentX < 2) ++currentX; break;
      case 'U': if (currentY > 0) --currentY; break;
      case 'D': if (currentY < 2) ++currentY; break;
    }
    ++i;
  }

  printf("%c", '1' + (currentY * 3) + currentX);
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

