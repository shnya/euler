#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

#include "euler.hpp"

using namespace std;
using namespace euler;


int main(int argc, char *argv[])
{
  Frac f(5,7),g(-8,5);
  cout << f + g << endl;

  return 0;
}
