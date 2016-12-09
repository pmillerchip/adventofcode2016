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
int main(int argc, char** argv)
{
  char c;
  while((c = getchar()) != EOF)
  {
    if (c == '(')
    {
      int length, repeat;
      scanf("%dx%d)", &length, &repeat);
      std::string buf;
      for(int i=0; i < length; ++i) buf += getchar();
      for(int i=0; i < repeat; ++i) fputs(buf.data(), stdout);
    }
    else if (!isspace(c))
    {
      putchar(c);
    }
  }

  printf("\n");
  return(0);
}

