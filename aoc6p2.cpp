//-----------------------------------------------------------------------------
// Advent of Code: Day 6
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

typedef std::map<char, int> CharTotals;

//-----------------------------------------------------------------------------
int
main(int argc, char** argv)
{
  if (argc < 2) return(1);

  std::ifstream file(argv[1]);
  std::string line; 
  std::vector<CharTotals> totals;

  while (std::getline(file, line))
  {
    if (totals.empty()) for(auto& c : line) totals.push_back(CharTotals());
    for(int i{0}; i<line.size(); ++i) ++totals[i][line[i]];
  }

  printf("Message: ");
  for(auto& t : totals)
  {
    int minNum{0xffff};
    char minChar{' '};
    for(auto& sum : t)
    {
      if (sum.second < minNum)
      {
        minNum = sum.second;
        minChar = sum.first;
      }
    }
    putchar(minChar);
  }
  printf("\n");

  return(0);
}

