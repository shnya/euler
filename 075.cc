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



long long gcd(long long m, long long n){
  long long temp;
  while(m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}p

long long _lcm (long long m, long long n){
  return m * n / gcd(m,n);
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  int N = 1500000;
  //int N = 100;
  //set<pair<pair<LLI,LLI>,LLI> > used1,used2;
  vector<bool> used1(N+1),used2(N+1);
  set<pair<LLI,LLI> > s;
  for(LLI u = 1; u <= N; u++){
    for(LLI v = u+1; v <= N; v++){
      if(gcd(u,v) != 1) continue;
      LLI a = v*v - u*u;
      LLI b = 2 * u * v;
      LLI c = v*v + u*u;
      if(a > b) swap(a,b);
      if(a+b+c > N) break;
      LLI L2 = a+b+c;
      for(LLI i = 1; i <= N/L2; i++){
        if(s.find(make_pair(a*i,b*i)) != s.end()) continue;
        s.insert(make_pair(a*i,b*i));
        LLI L = L2 * i;
        if(used1[L]){
          used2[L] = true;
        }else{
          used1[L] = true;
        }
      }
    }
  }

  int sum = 0;
  for(size_t i = 0; i < used1.size(); i++){
    if(used1[i] && !used2[i]){
      cout << i << endl;
      sum++;
    }
  }
  cout << sum << endl;


  return 0;
}
