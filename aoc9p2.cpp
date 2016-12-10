//-----------------------------------------------------------------------------
// Advent of Code: Day 9
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

//-----------------------------------------------------------------------------
unsigned long int getUncompressedSize(const std::string& input)
{
  unsigned long int rv = 0;
  size_t len = input.length();
  for(size_t i=0; i < len; ++i)
  {
    if (input[i] == '(')
    {
      int length, repeat;
      sscanf(input.data() + i + 1, "%dx%d)", &length, &repeat);
      while(input[i++] != ')')
        ; // Empty
      printf("Uncompressing (%dx%d)...\n", length, repeat);
      rv += getUncompressedSize(input.substr(i, length)) * repeat;
      i += length - 1;
    }
    else
    {
      ++rv;
    }
  }
  return(rv);
}

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  char c;
  std::string input;
  while((c = getchar()) != EOF)
  {
    if (!isspace(c)) input += c;
  }

  printf("Input is %lu bytes:\n'%s'\n", input.length(), input.data());
  unsigned long int sz = getUncompressedSize(input);
  printf("Uncompressed size: %lu bytes\n", sz);

  return(0);
}

