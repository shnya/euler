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




int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  int N = 2000;

  vector<int> used1(N+1);
  vector<bool> is_square(N*N*5+1);
  for(LLI i = 1; i *i < LLI(is_square.size()); i++)
    is_square[i*i] = true;
  for(LLI i = 1; i <= N; i++){
    for(LLI j = i; j <= N; j++){
      for(LLI k = j; k <= N; k++){
        LLI c2 = (i+j)*(i+j) + k*k;
        if(is_square[c2]){
          used1[k]++;
        }
      }
    }
  }

  int sum = 0;
  for(size_t i = 0; i < used1.size(); i++){
    //cout << i << " " << used1[i] << endl;
    sum += used1[i];
    if(sum > 1000000){
      cout << i << " Found" << endl;
      return 0;
    }
  }
  cout << sum << endl;


  return 0;
}
