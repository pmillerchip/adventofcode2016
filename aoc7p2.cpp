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
bool findBAB(std::string line, std::string bab)
{
  bool inBrackets = false;
  std::string check;
  for(int i=0; i < line.length() - 2; ++i)
  {
    check = line.substr(i, 3);
    if (check[0] == '[') inBrackets = true;
    else if (check[0] == ']') inBrackets = false;
    else if (inBrackets && (check == bab)) return(true);
  }
  return(false);
}

//-----------------------------------------------------------------------------
bool isValid(std::string line)
{
  bool inBrackets = false;
  bool isABA;
  std::string check;
  for(int i=0; i < line.length() - 2; ++i)
  {
    check = line.substr(i, 3);
    isABA = false;
    if (check[0] == '[') inBrackets = true;
    else if (check[0] == ']') inBrackets = false;
    else
    isABA = ((check[0] == check[2])
          && (check[0] != check[1]));

    if (isABA && !inBrackets)
    {
      if (findBAB(line, std::string{check[1]} + check[0] + check[1])) return(true);
    }
  }
  return(false);
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

