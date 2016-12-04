//-----------------------------------------------------------------------------
// Advent of Code: Day 4
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
processRoom(std::string name, int sector, std::string checksum)
{
  unsigned int counts[26] = {};
  unsigned int highCount = 0;
  unsigned int thisCount = 0;
  for(char& c : name)
  {
    if ((c >= 'a') && (c <= 'z'))
    {
      thisCount = ++counts[c - 'a'];
      if (thisCount > highCount) highCount = thisCount;
    }
  }

  std::string calcChecksum;
  while(highCount > 0)
  {
    for(int i=0; i < 26; ++i)
    {
      if (counts[i] == highCount) calcChecksum += ('a' + i);
    }
    --highCount;
  }
  calcChecksum = calcChecksum.substr(0, 5);

  bool isValid = (checksum == calcChecksum);
  if (isValid)
  {
    std::string decrypt;
    for(char c : name)
    {
      if (c != '-') c = 'a' + (((int)(c-'a') + sector) % 26);
      decrypt += c;
    }
    name = decrypt;
  }

  printf("Name='%s', sector=%d, checksum='%s', cc='%s'\n",
    name.data(), sector, checksum.data(), calcChecksum.data());

  return(isValid? sector: 0);
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
  std::string name; 
  int total = 0;
  while (std::getline(file, line))
  {
    size_t found = line.find_first_of("0123456789");
    if (found != std::string::npos)
    {
      name = line.substr(0, found);
      line = line.substr(found);
      total += processRoom(name, atoi(line.data()), line.substr(line.find('[') + 1, 5));
    }
  }
  printf("Total valid = %d\n", total);

  return(0);
}

