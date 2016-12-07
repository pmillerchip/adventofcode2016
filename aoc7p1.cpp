//-----------------------------------------------------------------------------
// Advent of Code: Day 7
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

//-----------------------------------------------------------------------------
bool isValid(std::string line)
{
  bool inBrackets = false;
  bool foundABBA = false;
  bool isABBA;
  std::string check;
  for(int i=0; i < line.length() - 3; ++i)
  {
    check = line.substr(i, 4);
    if (check[0] == '[') inBrackets = true;
    else if (check[0] == ']') inBrackets = false;
    else
    isABBA = ((check[0] == check[3])
           && (check[1] == check[2]) 
           && (check[0] != check[1]));

    foundABBA = foundABBA || isABBA;
    if (isABBA && inBrackets) return(false);
  }
  return(foundABBA);
}

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  if (argc < 2) return(1);

  std::ifstream file(argv[1]);
  std::string line; 
  int total = 0;
  while (std::getline(file, line))
  {
    if (isValid(line)) ++total;
  }

  printf("Total valid: %d\n", total);
  return(0);
}

