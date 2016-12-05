//-----------------------------------------------------------------------------
// Advent of Code: Day 5 part 2
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "MD5.h"

//-----------------------------------------------------------------------------
int
main(int argc, char** argv)
{
  //std::string input = "abc";
  std::string input = "ugkcyxxp";
  std::string checksum;
  std::string password = "________";
  unsigned int index = 0;
  char attempt[32];
  MD5 md5;
  while(index < 0xffffffff)
  {
    snprintf(attempt, 32, "%s%u", input.data(), index);
    checksum = md5.getMD5(attempt, strlen(attempt));
    if (checksum.substr(0, 5) == "00000")
    {
      char c = checksum[5];
      if ((c >= '0') && (c < '8'))
      {
        int pos = c - '0';
        if (password[pos] == '_') password[pos] = checksum[6];
        printf("[%s] Found '%s' that produces checksum '%s'\n", password.data(), attempt, checksum.data());
        if (password.find('_') == std::string::npos)
        {
          printf("Password is: '%s'\n", password.data());
          return(0);
        }
      }
    }
    ++index;
  }

  return(0);
}

