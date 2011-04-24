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

#include "euler.hpp"
using namespace euler;



BigInt binsearch(BigInt n){
  BigInt minn=0,maxn=n;

  while(maxn - minn > 1){
    BigInt n1 = minn + (maxn - minn) / 2;
    //cout << maxn << endl <<  minn << endl;
    if(n1 * n1 - n < 0){
      minn = n1;
    }else{
      maxn = n1;
    }
  }
  return minn;
}

int main(int argc, char *argv[]){
  vector<bool> sq(10001);
  for(int i = 1; i <= 100;i++) sq[i*i] = true;
  int sum = 0;

  for(int i = 1; i <= 100; i++){
    BigInt n(i);
    if(sq[i]) continue;
    for(int j = 0; j < 100; j++){
      n *= 100;
    }
    n *= 100;
    string s = binsearch(n).str();
    //cout << s << endl;
    int sum2 = 0;
    for(size_t j = 0; j < 100; j++){
      sum += s[j] - '0';
      sum2 += s[j] - '0';
    }
    cout <<  i << " " << sum2 << endl;
  }
  cout << sum << endl;

  return 0;
}
