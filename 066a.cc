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





int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  vector<bool> is_square(10000000001);
  for(LLI i = 1; i * i < is_square.size(); i++) is_square[i*i] = 1;
  

  LLI D = 100;
  for(LLI i = 2; i <= D; i++){
    if(is_square[i]) continue;
    bool skip_flg = false;
    for(LLI j = 1; j < std::numeric_limits<int>::max(); j++){
      LLI j2 = j*j;
      if((j2 - 1) % i != 0) continue;
      if(!skip_flg && (j2 - 1) / i < is_square.size()-1){
        if(is_square[(j2-1)/i]){
          cout << i << " " << j << " " << (j2-1)/i << endl;
          goto success;
        }else{
          continue;
        }
      }else{
        skip_flg = true;
      }
      LLI n = sqrt((j2-1)/i);
      for(LLI k = n - 3; k < n + 3; k++){
        if(k*k*i > j2 - 1) break;
        if(j2 == 1 + k*k*i){
          cout << i << " " << j << " " << k << endl;
          goto success;
        }
      }
    }
  success:;
  }
  return 0;
}
