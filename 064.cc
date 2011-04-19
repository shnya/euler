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

template<class T> ostream &operator<<(ostream &o,const vector<T> &v){
  o << "["; REP(i,SZ(v)) o << v[i] << (i < SZ(v)-1 ? ",":""); return o << "]";
}
template<class T,class U> ostream &operator<<(ostream &o,const pair<T,U> &v){
  return o << v.first << ":" << v.second;
}

LLI sqrti(LLI n){
  LLI i = 1;
  while(1){
    int k = i * i;
    if(k > n){
      return i - 1;
    }else if(k == n){
      return -1;
    }
    i++;
  }
  return 1;
}

LLI gcd(LLI m, LLI n){
  LLI temp;
  while(m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}

LLI _lcm (LLI m, LLI n){
  return m * n / gcd(m,n);
}


int solve(int n){
  LLI num = sqrti(n);
  if(num == -1) return 0;
  LLI den=1,nn=num;
  map<pair<LLI,LLI>,int> s;
  vector<LLI> v;
  LLI square = num;
  v.PB(num);
  int count = 0;
  while(1){
    LLI den_1 = den;
    den = n - num*num;
    LLI g = gcd(den,den_1);
    den /= g;
    nn = (square + num) / den;
    num = -(num - nn * den);
    //dump(nn);
    //dump(den);
    //dump(num);
    v.PB(nn);
    if(s.find(make_pair(num,den)) != s.end()){
      return count - s[make_pair(num,den)];
    }
    s.insert(make_pair(make_pair(num,den),count));
    count++;
  }
  return 1;
}



int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);

  int sum = 0;
  FOR(i,2,10000){
    int period = solve(i);
    if(period % 2 == 1) sum++;
  }
  cout << sum << endl;

  return 0;
}
