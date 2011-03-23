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


// 0 Mon 1 Tue 2 Wed 3 Thu 4 Fri 5 Sat 6 Sun


int getDays(int y, int m){
  if(m == 4 || m == 6 || m == 9 || m == 11){
    return 30;
  }else if(m == 2){
    if(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)){
      return 29;
    }else{
      return 28;
    }
  }else{
    return 31;
  }
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false); 
  int n = -1;
  int c = 0;
  for(int y = 1900; y <= 2000; y++){
    for(int m = 1; m <= 12; m++){
      //cout << y << ' ' << m << ' ' << getDays(y,m) << endl;
      for(int d = 1; d <= getDays(y,m); d++){
        n++;
        n %= 7;
        if(n == 6 && d == 1 && y > 1900) c++;
      }
    }
  }
  cout << c << endl;
  return 0;
}
