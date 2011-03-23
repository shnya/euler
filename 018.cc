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


vector<vector<int> > g;
int dp[16][16];

int dfs(int i, int j){
  if(dp[i][j] != 0){
    return dp[i][j];
  }
  if(i == g.size() - 1){
    return g[i][j];
  }
  int res = g[i][j];
  res += max(dfs(i+1,j), dfs(i+1,j+1));
  return dp[i][j] = res;
  return res;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false); 
  CLR(dp);
  ifstream ifs("18.txt");
  for(int i = 0; i < 15; i++){
    vector<int> v;
    for(int j = 0; j < i + 1; j++){
      int n;
      ifs >> n;
      v.push_back(n);
      //cout << n << " ";
    }
    g.push_back(v);
    //cout << endl;
  }

  int total = dfs(0,0);
  cout << total << endl;

  return 0;
}
