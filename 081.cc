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




std::vector<std::string>
split(const std::string &str, const std::string &delim){
  std::vector<std::string> res;
  size_t current = 0, found, delimlen = delim.size();
  while((found = str.find(delim, current)) != std::string::npos){
    res.push_back(string(str, current, found - current));
    current = found + delimlen;
  }
  res.push_back(std::string(str, current, str.size() - current));
  return res;
}

int maxn = 1000000000;
#include <queue>

struct node {
  int x,y,pt;
};
bool operator<(const node &a, const node &b){
  return a.pt < b.pt;
}
bool operator>(const node &a, const node &b){
  return a.pt > b.pt;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  ifstream ifs("matrix081.txt");
  string line;
  vector<vector<int> > v;
  while(getline(ifs,line)){
    vector<string> fs = split(line,",");
    vector<int> vfs;
    REP(i,SZ(fs)){
      vfs.push_back(toInt(fs[i]));
    }
    //cout << vfs.size() << endl;
    v.push_back(vfs);
  }
  //cout << v.size() << endl;

  int dp[81][81];
  REP(i,SZ(v)) REP(j,SZ(v[i])) dp[i][j] = maxn;
  priority_queue<node,vector<node>,greater<node> > Q;
  REP(j,SZ(v[0])) Q.push((node){0,j,v[j][0]});
  while(!Q.empty()){
    node n = Q.top();
    Q.pop();
    cout << "x " << n.x << " y = " << n.y <<
      " pt = " << n.pt << endl;
    if(n.y != 0){
      if(dp[n.y-1][n.x] > n.pt+v[n.y-1][n.x]){
        dp[n.y-1][n.x] = n.pt+v[n.y-1][n.x];
        Q.push((node){n.x,n.y-1,n.pt+v[n.y-1][n.x]});
      }
    }
    if(n.y != 79){
      if(dp[n.y+1][n.x] > n.pt+v[n.y+1][n.x]){
        dp[n.y+1][n.x] = n.pt+v[n.y+1][n.x];
        Q.push((node){n.x,n.y+1,n.pt+v[n.y+1][n.x]});
      }
    }
    if(n.x != 79){
      if(dp[n.y][n.x+1] > n.pt+v[n.y][n.x+1]){
        dp[n.y][n.x+1] = n.pt+v[n.y][n.x+1];
        Q.push((node){n.x+1,n.y,n.pt+v[n.y][n.x+1]});
      }
    }
  }
  int res = maxn;
  REP(j,SZ(v[0])) res = min(dp[j][79],res);
  cout << res << endl;
  return 0;
}
