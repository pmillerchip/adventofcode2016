//-----------------------------------------------------------------------------
// Advent of Code: Day 3
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

//-----------------------------------------------------------------------------
int
main(int argc, char** argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s <input filename>\n", argv[0]);
    return(1);
  }

  std::ifstream file(argv[1]);
  std::string line; 
  int a, b, c, numPossible = 0;
  while (std::getline(file, line))
  {
    std::stringstream(line) >> a >> b >> c;
    if (((a+b) > c) && ((b+c) > a) && ((a+c) > b)) ++numPossible;
    printf("%d %d %d %d\n", a, b, c, numPossible);
  }
  printf("%d possible\n", numPossible);

  return(0);
}

