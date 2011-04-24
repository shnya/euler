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

LLI dp[1001][1001];
vector<int> prime;
LLI rec(LLI n, LLI maxi){
  if(n == 0){
    return 1;
  }
  if(dp[n][maxi] != -1) return dp[n][maxi];
  LLI res = 0;
  for(size_t i = 0; prime[i] <= min(maxi,n); i++){
    LLI k = prime[i];
    res += rec(n-k,min((LLI)k,maxi));
  }
  //return res;
  return dp[n][maxi] = res;
}

vector<int> primes;
void get_primes(int N){
  primes.resize(N+1);
  for(int i = 0; i <= N; i++) primes[i] = 1;
  primes[0] = 0;
  primes[1] = 0;
  for(int i = 2; i <= N; i++){
    for(int j = 2; i*j <= N; j++){
      if(primes[i * j] == 1){
        primes[i * j] = 0;
      }
    }
  }
  for(size_t i = 0; i < primes.size(); i++)
    if(primes[i]) prime.push_back(i);
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  memset(dp,-1,sizeof(dp));
  get_primes(1000);
  for(int i = 5; i < 1000; i++){
    int n = rec(i,i);
    if(primes[i]) n--;
    cout << i << " " << n << endl;
    if(n >= 5000){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
