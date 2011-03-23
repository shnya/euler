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


int dp[8][201];

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  memset(dp,0,sizeof dp);

  int a[] = {1,2,5,10,20,50,100,200};
  for(int i = 0; i < 8; i++){
    for(int j = 0; j <= 200; j++){
      for(int k = 0; k * a[i] <= j; k++){
        if(j - a[i]*k == 0){
          dp[i][j] += 1;
        }
        if(i > 0 && j-a[i]*k > 0){
          dp[i][j] += dp[i-1][j-a[i]*k];
        }
      }
    }
  }
  for(int i = 0; i < 8; i++){
    for(int j = 0; j <= 200; j++){
      cout << i << ' ' << j << " " << dp[i][j] << endl;
    }
  }
  cout <<  dp[7][200] << endl;

  return 0;
}
