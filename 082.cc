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

int dp[81][81];

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  ifstream ifs("matrix.txt");
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
  REP(i,SZ(v)) REP(j,SZ(v[i])) dp[i][j] = 1000000000;
  dp[0][0] = v[0][0];
  for(size_t i = 0; i < v.size(); i++){
    for(size_t j = 0; j < v[i].size(); j++){
      if(i == 0 && j == 0) continue;
      if(j != 0){
        dp[i][j] = min(dp[i][j-1]+v[i][j],dp[i][j]);
      }
      if(i != 0){
        dp[i][j] = min(dp[i-1][j]+v[i][j],dp[i][j]);
      }
    }
  }

  cout << dp[79][79] << endl;


  return 0;
}
