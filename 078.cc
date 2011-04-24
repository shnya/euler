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

template<class T> ostream &operator<<(ostream &o,const vector<T> &v){
  o << "["; REP(i,SZ(v)) o << v[i] << (i < SZ(v)-1 ? ",":""); return o << "]";
}

#include "euler.hpp"
using namespace euler;
vector<BigInt> v;

BigInt p(LLI n){
  BigInt res = 0;
  LLI k = 1;
  while(1){
    LLI n1 = n - (3 * k * k - k) / 2;
    LLI n2 = n - (3 * k * k + k) / 2;
    if(n1 < 0 && n2 < 0) break;
    if((k + 1) % 2 == 0){
      if(n1 >= 0){
        res += v[n1];
      }
      if(n2 >= 0){
        res += v[n2];
      }
    }else{
      if(n1 >= 0){
        res -= v[n1];
      }
      if(n2 >= 0){
        res -= v[n2];
      }
    }
    k++;
  }
  v.push_back(res);
  return res;
}


int main(int argc, char *argv[]){
  //ios::sync_with_stdio(false);
  v.push_back(1);

  for(int i = 1; i < 10000000; i++){
    BigInt n = p(i);
    //cout << n << endl;
    if(n % 1000000 == 0){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
