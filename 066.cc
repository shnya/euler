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

#include "euler.hpp"
using namespace euler;


LLI gcd(LLI m, LLI n){
  LLI temp;
  while(1){
    temp = n;
    n = m % n;
    if(n == 0)
      return temp;
    m = temp;
  }
  return n;
}

LLI sqrti(BigInt n){
  LLI i = 1;
  while(1){
    LLI k = i * i;
    if(k > n){
      return i - 1;
    }else if(k == n){
      return -1;
    }
    i++;
  }
  return 1;
}

template<class T> ostream &operator<<(ostream &o,const vector<T> &v){
  o << "["; REP(i,SZ(v)) o << v[i] << (i < SZ(v)-1 ? ",":""); return o << "]";
}
template<class T,class U> ostream &operator<<(ostream &o,const pair<T,U> &v){
  return o << v.first << ":" << v.second;
}

vector<LLI> solve(int n){
  LLI num = sqrti(n);
  if(num == -1) return vector<LLI>();
  LLI den=1,nn=num;
  map<pair<LLI,LLI>, int> s;
  vector<LLI> v;
  v.push_back(nn);
  LLI square = num;
  int count = 1;
  while(1){
    LLI den_1 = den;
    den = n - num*num;
    LLI g = gcd(den,den_1);
    den /= g;
    nn = (square + num) / den;
    num = -(num - nn * den);
    //dump(nn);
    pair<LLI,LLI> p(num,den);
    if(s.find(p) != s.end()){
      v.insert(v.begin()+s[p],-1);
      break;
    }
    s.insert(make_pair(p,count));
    v.push_back(nn);
    count++;
    //dump(den);
    //dump(num);
  }
  return v;
}

LLI nth(size_t n, size_t cycle, const vector<LLI> &v){
  size_t noncycle = v.size() - cycle - 1;
  if(n >= v.size() - 1){
    return v[(n - noncycle)%(cycle) + noncycle + 1];
  }else{
    if(n > noncycle - 1){
      return v[n+1];
    }else{
      return v[n];
    }
  }
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  BigInt max;
  int d = 0;
  for(int i = 2; i <= 1000; i++){
    vector<LLI> v = solve(i);
    //cout << v << endl;
    if(v.size() == 0) continue;
    size_t cycle = 0;
    REP(k,SZ(v)){
      if(v[k] == -1){
        cycle = v.size() - k - 1;
        break;
      }
    }

    int k = 0;
    while(1){
      Frac f(nth(k,cycle,v));
      for(int j = k-1; j >= 0; j--){
        f = nth(j,cycle,v) + 1 / f;
      }
      k++;
      if(f.numerator() * f.numerator() -
         i * f.denominator() * f.denominator() == 1){
        if(max < f.numerator()){
          max = f.numerator();
          d = i;
        }
        cout << i << " " << f << endl;
        break;
      }
      //cout << f << endl;
    }
    //  string s = (2 + (1 / f)).numerator().str();

    /*
      cout << v << endl;
      for(int i = 0; i < 1000; i++){
      cout << i << " " << nth(i,cycle,v) << endl;
      }
    */
  }
  cout << d << endl;
  return 0;
}
