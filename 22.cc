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
  std::size_t current = 0, found, delimlen = delim.size();
  while((found = str.find(delim, current)) != std::string::npos){
    res.push_back(string(str, current, found - current));
    current = found + delimlen;
  }
  res.push_back(std::string(str, current, str.size() - current));
  return res;
}


#include <cassert>

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false); 
  string line;
  ifstream ifs("names.txt");
  getline(ifs,line);
  vector<string> names = split(line,",");
  cout << names.size() << endl;
  REP(i,SZ(names))
    names[i] = names[i].substr(1, names[i].size()-2);
  SORT(names);
  int res = 0;
  REP(i,SZ(names)){
    int val = 0;
    REP(j,SZ(names[i])){
      val += names[i][j] - 'A' + 1;
    }
    val *= (i + 1);
    if(i == 937)
      assert(val == 49714);
    res += val;
    //cout << val << endl;
  }
  cout << res << endl;
  return 0;
}
