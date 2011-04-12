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



int concat(int a, int b)
{
  int c = b;
  while(c != 0){
    a *= 10;
    c /= 10;
  }
  return a + b;
}

vector<int> primes;
void get_primes(int N){
  primes.resize(N+1);
  for(int i = 0; i <= N; i++) primes[i] = 1;
  primes[0] = 0;
  primes[1] = 0;
  for(int i = 2; i <= N; i++){
    for(int j = 2; i*j <= N; j++){
      if(primes[i * j] == 1){
        primes[i * j] = 0;
      }
    }
  }
}

bool is_prime(int n){
  if(n < 1000000){
    return primes[n];
  }else{
    for(int i = 2; i * i <= n; i++){
      if(n % i == 0) return false;
    }
    return true;
  }
}

vector<int> check(const vector<int> &s, int n, const set<pair<int,int> > &twop){
  EACH(i,s){
    int k = *i;
    if(twop.find(make_pair(min(k,n),max(k,n))) == twop.end()){
      return vector<int>();
    }
  }
  vector<int> res;
  EACH(i,s) res.push_back(*i);
  res.push_back(n);
  sort(res.begin(),res.end());
  return res;
}

set<vector<int> > make_set(const set<vector<int> > &v, const vector<int> &p, const set<pair<int,int> > &twop)
{
  set<vector<int> > res;
  EACH(i,v){
    const vector<int> &s = *i;
    REP(j,SZ(p)){
      vector<int> checked = check(s,p[j],twop);
      if(checked.size() > 0){
        res.insert(checked);
      }
    }
  }
  return res;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);

  get_primes(1000000);
  vector<int> p;
  REP(i,10000){
    if(primes[i] == 1)
      p.PB(i);
  }

  set<pair<int,int> > twop;
  set<vector<int> > two,three,four,five;

  cout << SZ(p) << endl;

  //make two
  REP(i,SZ(p)){
    FOR(j,i+1,SZ(p)){
      if(is_prime(concat(p[i],p[j]))
         && is_prime(concat(p[j],p[i]))){
        twop.insert(make_pair(min(p[i],p[j]),max(p[i],p[j])));
      }
    }
  }


  EACH(i,twop){
    const pair<int,int> &s = *i;
    REP(j,SZ(p)){
      if(twop.find(make_pair(min(s.first,p[j]),max(s.first,p[j]))) != twop.end()
         && twop.find(make_pair(min(s.second,p[j]),max(s.second,p[j])))
         != twop.end()){
        vector<int> tmp;
        tmp.PB(s.first);
        tmp.PB(s.second);
        tmp.PB(p[j]);
        sort(tmp.begin(),tmp.end());
        three.insert(tmp);
      }
    }
  }

  four = make_set(three,p,twop);
  five = make_set(four,p,twop);

  int sum = 1000000000;
  EACH(i,five){
    const vector<int> &s = *i;
    int n = 0;
    EACH(j,s){
      n += *j;
    }
    if(sum > n)
      sum = n;
  }
  cout << sum << endl;

  return 0;
}
