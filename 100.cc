#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LLI;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



#include "euler.hpp"
using namespace euler;

long long gcd(long long m, long long n){
  long long temp;
  while(m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}

long long _lcm (long long m, long long n){
  return m * n / gcd(m,n);
}



int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  BigInt one_twelve = BigInt(1000000) * BigInt(1000000);

  Frac a = Frac(1,2);
  for(int i = 1; i < 1000; i++){
    a = 1 / ( 2 + a);
    Frac c = a + 1;
    if(c.numerator() * c.numerator() - 2 * c.denominator() * c.denominator()
       == -1){
      BigInt m = (c.denominator() + 1) / 2;
      BigInt n = (c.numerator() + 1) / 2;
      cout << m << "/" << n << endl;
      if(n > one_twelve){
        cout << m << endl;
        break;
      }
    }
  }

  return 0;
}
