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


#include <cassert>

int dp[12345678];

int dfs(LLI n){
  //assert(n > 0);
  if(n >= 10000000) cout << "test" << endl;
  if(n > 0 && n < 10000000 && dp[n] != 0){
    return dp[n];
  }

  if(n == 1) return 0;
  int res = 1;
  if(n % 2 == 0){
    res += dfs(n/2);
  }else{
    res += dfs(3*n+1);
  }
  return n < 10000000 ? dp[n] = res : res;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  CLR(dp);

  int maxc=0,maxn=0;
  FOR(i,2,1000001){
    int c = dfs(i);
    if(maxc < c){
      maxn = i;
      maxc = c;
    }
  }

  cout << maxn << endl;
  return 0;
}
