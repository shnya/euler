#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

typedef long long int LLI;

int main(int argc, char *argv[])
{
  for(int a = 1; a < 1000; a++){
    for(int b = a + 1; b < 1000; b++){
      for(int c = b+1; c < 1000; c++){
        if(a + b + c != 1000) continue;
        if(a*a + b*b == c*c) 
          cout << a * b * c << endl;
      }
    }
  }

  return 0;
}


