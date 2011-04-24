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
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  vector<LLI> two,three,four;
  LLI N = 50000000;
  vector<bool> s(N+1);
  get_primes(sqrt(N)+1);
  for(LLI i = 1; i * i < N; i++)
    if(primes[i]) two.push_back(i*i);
  for(LLI i = 1; i * i * i < N; i++)
    if(primes[i]) three.push_back(i*i*i);
  for(LLI i = 1; i * i * i * i< N; i++)
    if(primes[i]) four.push_back(i*i*i*i);

  int num = 0;
  REP(i,SZ(two)) REP(j,SZ(three)) REP(k,SZ(four)){
    LLI n = two[i] + three[j] + four[k];
    if(n < N){
      if(s[n]) continue;
      //cout << two[i] + three[j] + four[k] << endl;
      num++;
      s[n] = true;
    }
  }
  cout << num << endl;

  return 0;
}
