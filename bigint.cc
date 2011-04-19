#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

#include "euler.hpp"

using namespace std;
using namespace euler;


using namespace std;
template<class T>
ostream& operator<<(ostream& o, vector<T> v){
  o << "[";
  for(size_t i = 0; i < v.size(); i++) o << v[i] << (i +1 < v.size() ? "," : "");
  o << "]";
}

int main(int argc, char *argv[])
{
  //BigInt x(61181), y(25342);
  //cout << x % y << endl;
  Frac a(1,2);
  int sum = 0;
  for(int i = 0; i < 1000; i++){
    //cout << Frac(1) + a << endl;
    a = Frac(2) + (Frac(1) / a);
  }

  return 0;
}
