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



LLI gcd(LLI m, LLI n){
  LLI temp;
  while(m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  int N = 1000000000;
  //int N = 100;
  LLI sum = 0;
  LLI slimit = sqrt(N)+1;
  for(LLI t = 1; t <= slimit; t+=2){
    for(LLI s = t+2; s <= N; s+=2){
      if(gcd(s,t) != 1) continue;
      LLI a = s*t;
      LLI b = (s*s - t*t)/2;
      LLI c = (s*s + t*t)/2;
      if(a > b) swap(a,b);
      if(2*c+2*a > N) break;
      if(abs(c - 2*b) == 1){
        sum += 2*c + 2*b;
        //for(int i = 1; i <= N/L2; i++){
        //sum += i*L2;
        //}
      }
      if(abs(c - 2*a) == 1){
        sum += 2*c + 2*a;
        //for(int i = 1; i <= N/L3; i++){
        //sum += i*L3;
        //}
      }
    }
  }

  cout << sum << endl;


  return 0;
}
