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
  Frac d(1,2);
  int sum = 0;
  for(int i = 0; i < 1000; i++){
    //cout << 1 + a << endl;
    d = 1 / (d + 2);
    Frac c = d + 1;
    int nlen = c.numerator().str().size();
    int dlen = c.denominator().str().size();
    cout << nlen << " " << dlen << endl;
    if(nlen > dlen){
      sum++;
    }
  }
  cout << sum << endl;
  /*
  cout << pow(BigInt(2),1000) << endl;

  vector<BigInt> v;
  for(size_t i = 0; i < 1000; i++){
    v.push_back(i);
  }
  cout << v << endl;
  //cout << pow(BigInt(65535),65535) << endl;
  BigInt a(3),b(2);
  cout << "3 % 2 = " <<  3 % 2 << endl;
  cout << "3 % -2 = " <<  3 % -2 << endl;
  cout << "-3 % 2 = " <<  -3 % 2 << endl;
  cout << "-3 % -2 = " <<  -3 % -2 << endl;
  cout << "3 % 2 = " <<  a % b << endl;
  cout << "3 % -2 = " <<  a % -b << endl;
  cout << "-3 % 2 = " <<  -a % b << endl;
  cout << "-3 % -2 = " <<  -a % -b << endl;
  */
  return 0;
}
