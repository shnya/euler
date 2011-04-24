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

vector<int> v;
void make_euler(int N){
  v.resize(N+2);
  v[0] = 0;
  for(int i = 1; i <= N; i++)
    v[i] = i;

  for(int i = 2; i <= N; i++){
    if(v[i] != i) continue;
    v[i] = i - 1;
    for(int j = 2; j * i <= N; j++){
      LLI n = i * j;
      
      v[n] = (LLI)v[n] * (LLI)(i - 1) / i;
    }
  }
}
#include <limits>


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);

  make_euler(10000000);
  //cout << v << endl;
  long double minn = numeric_limits<long double>::max();
  int mini = 0;
  cout << v[3163] << endl;
  for(int i = 2; i < 10000000; i++){
    //cout << (double) i / v[i] << endl;
    if(minn > (long double)i / v[i]){
      //cout << (double) i / v[i] << endl;
      string s1(toString(i)),s2(toString(v[i]));
      SORT(s1); SORT(s2);
      if(s1 != s2) continue;
      minn = (long double)i / v[i];
      cout <<i << " " << minn << endl;
      mini = i;
    }
  }

  cout << mini << endl;
  return 0;
}
