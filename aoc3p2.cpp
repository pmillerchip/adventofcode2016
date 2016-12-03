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

bool isTri(int a, int b, int c)
{
  printf("%d %d %d\n", a, b, c);
  return(((a+b) > c) && ((b+c) > a) && ((a+c) > b));
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

  std::ifstream file(argv[1]);
  std::string line; 
  int a[3], b[3], c[3];
  int numPossible = 0;
  int numLines = 0;
  while (std::getline(file, line))
  {
    std::stringstream(line) >> a[numLines] >> b[numLines] >> c[numLines];
    ++numLines;
    if (numLines == 3)
    {
      if (isTri(a[0], a[1], a[2])) ++numPossible;
      if (isTri(b[0], b[1], b[2])) ++numPossible;
      if (isTri(c[0], c[1], c[2])) ++numPossible;
      numLines = 0;
    }
  }
  printf("%d possible\n", numPossible);

  return(0);
}

