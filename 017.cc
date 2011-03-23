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

template<class T, class U> struct MAPPER { T t; U u; };
template<class T, class U, size_t N> map<T,U> toMap(MAPPER<T,U> (&o)[N]){map<T,U> m;for(int i=0;i<N;i++) m[o[i].t]=o[i].u;return m;}
/* helper function end */



int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);

  MAPPER<int, string> a[] = {
    {0,""},
    {1,"one"},
    {2,"two"},
    {3,"three"},
    {4,"four"},
    {5,"five"},
    {6,"six"},
    {7,"seven"},
    {8,"eight"},
    {9,"nine"},
    {10,"ten"},
    {11,"eleven"},
    {12,"twelve"},
    {13,"thirteen"},
    {14,"fourteen"},
    {15,"fifteen"},
    {16,"sixteen"},
    {17,"seventeen"},
    {18,"eighteen"},
    {19,"nineteen"},
    {20,"twenty"},
    {30,"thirty"},
    {40,"forty"},
    {50,"fifty"},
    {60,"sixty"},
    {70,"seventy"},
    {80,"eighty"},
    {90,"ninety"},
    {100,"hundred"},
    {1000, "thousand"}
  };

  map<int,string> m = toMap(a);
  int count = 0;
  for(int i = 1; i < 1000; i++){
    int n = i;
    if(n >= 100){
      if(n % 100 != 0) count += 3; //and
      count += m[n / 100].size();
      count += m[100].size();
      cout << m[n/100] << " " << m[100] << ((n % 100 != 0) ? " and " : " ");
      n %= 100;
    }
    if(n >= 20){
      count += m[n - n % 10].size();
      count += m[n%10].size();
      cout << m[n - n % 10] << " " << m[n%10] << "\t" << m[n - n % 10].size() 
           << " " << m[n%10].size() << endl;
    }else{
      count += m[n].size();
      cout << m[n] << "\t" << m[n].size() << endl;
    }
  }
  count += m[1000].size() + 3; //one thousand
  cout << count << endl;

  return 0;
}
