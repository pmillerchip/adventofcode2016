//-----------------------------------------------------------------------------
// Advent of Code: Day 5 part 1
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
  std::string input = "ugkcyxxp";
  std::string checksum;
  std::string password;
  unsigned int index = 0;
  char attempt[32];
  MD5 md5;
  while(index < 0xffffffff)
  {
    snprintf(attempt, 32, "%s%u", input.data(), index);
    checksum = md5.getMD5(attempt, strlen(attempt));
    if (checksum.substr(0, 5) == "00000")
    {
      printf("Mined: attempt '%s' produces checksum '%s'\n", attempt, checksum.data());
      password += checksum[5];
      if (password.length() > 7)
      {
        printf("Password is: '%s'\n", password.data());
        return(0);
      }
    }
    ++index;
  }

  return(0);
}

