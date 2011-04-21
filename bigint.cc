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
  return o << "]";
}

int len(const BigInt &a){
  ostringstream os;
  os << a;
  return os.str().size();
}

int main(int argc, char *argv[])
{
  //BigInt x(61181), y(25342);
  //cout << x % y << endl;
  /*
  Frac a(1,2);
  int sum = 0;
  for(int i = 0; i < 1000; i++){
    //cout << 1 + a << endl;
    a = 1 / (2 + a);
    Frac c = 1 + a;
    int nlen = c.numerator().str().size();
    int dlen = c.denominator().str().size();
    cout << nlen << " " << dlen << endl;
    if(nlen > dlen){
      sum++;
    }
  }
  */
  cout << pow(BigInt(65535),65535) << endl;
  /*
  BigInt a(3),b(2);
  cout << "3 % 2 " <<  3 % 2 << endl;
  cout << "3 % -2 " <<  3 % -2 << endl;
  cout << "-3 % 2 " <<  -3 % 2 << endl;
  cout << "-3 % -2 " <<  -3 % -2 << endl;
  cout << "3 % 2 " <<  a % b << endl;
  cout << "3 % -2 " <<  a % -b << endl;
  cout << "-3 % 2 " <<  -a % b << endl;
  cout << "-3 % -2 " <<  -a % -b << endl;
  */
  //cout << pow(BigInt(2),1000) << endl;
  return 0;
}
