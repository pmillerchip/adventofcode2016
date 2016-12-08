//-----------------------------------------------------------------------------
// Advent of Code: Day 8
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

#define WIDTH 50
#define HEIGHT 6

char display[WIDTH][HEIGHT];

//-----------------------------------------------------------------------------
bool startsWith(const std::string& str, const char* h)
{
  return(!strncmp(str.data(), h, strlen(h)));
}

//-----------------------------------------------------------------------------
void handleRect(std::string line)
{
  line = line.substr(5);
  int w = atoi(line.data());
  int h = atoi(line.substr(line.find('x') + 1).data());
  printf("Rct: %d by %d\n", w, h);

  for(int y=0; y < h; ++y)
    for(int x=0; x < w; ++x)
      display[x][y] = '#';
}

//-----------------------------------------------------------------------------
void splitCoords(std::string line, int& a, int& b)
{
  a = atoi(line.data());
  b = atoi(line.data() + line.find('y') + 2);
}

//-----------------------------------------------------------------------------
void handleRow(std::string line)
{
  line = line.substr(13);
  int row;
  int shift;
  splitCoords(line, row, shift);
  printf("Row: %d shift %d\n", row, shift);

  char buf[WIDTH];
  int x;
  for(x=0; x < WIDTH; ++x) buf[(x + shift) % WIDTH] = display[x][row];
  for(x=0; x < WIDTH; ++x) display[x][row] = buf[x];
}

//-----------------------------------------------------------------------------
void handleColumn(std::string line)
{
  line = line.substr(16);
  int col;
  int shift;
  splitCoords(line, col, shift);
  printf("Col: %d shift %d\n", col, shift);

  char buf[HEIGHT];
  int y;
  for(y=0; y < HEIGHT; ++y) buf[(y + shift) % HEIGHT] = display[col][y];
  for(y=0; y < HEIGHT; ++y) display[col][y] = buf[y];
}

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  if (argc < 2) return(1);

  memset(display, '.', sizeof(display));

  std::ifstream file(argv[1]);
  std::string line; 
  while (std::getline(file, line))
  {
    if (startsWith(line, "rect ")) handleRect(line);
    if (startsWith(line, "rotate row y=")) handleRow(line);
    if (startsWith(line, "rotate column x=")) handleColumn(line);
  }

  int total=0;
  char c;
  for(int y=0; y < HEIGHT; ++y)
  {
    for(int x=0; x < WIDTH; ++x)
    {
      c = display[x][y];
      putchar(c);
      if (c == '#') ++total;
    }
    printf("\n");
  }
  printf("Total: %d\n", total);

  return(0);
}

