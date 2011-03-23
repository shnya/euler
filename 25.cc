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





namespace MP{
  const int N = 100;
  typedef vector<int> mp_digit;

  mp_digit mp(int n){
    mp_digit res;
    while(1){
      res.push_back(n % N);
      n /= N;
      if(n == 0) break;
    }
    return res;
  }

  string mp_str(const mp_digit &v){
    string str;
    for(int i = 0; i < int(v.size()); i++){
      int n = v[i];
      for(int j = 0; j < log10(N); j++){
        str += (n % 10) + '0';
        n /= 10;
      }
    }
    reverse(str.begin(), str.end());
    for(int i = 0; i < int(str.size()); i++){
      if(str[i] != '0') return str.substr(i);
    }
    return "0";
  }

  const mp_digit mp_plus(const mp_digit &v1, const mp_digit &v2){
    if(v1.size() > v2.size())
      return mp_plus(v2, v1);

    mp_digit res;
    int carry = 0;
    for(int i = 0; i < int(v1.size()); i++){
      int n = carry + v1[i] + v2[i];
      res.push_back(n % N);
      carry = n / N;
    }
    for(int i = v1.size(); i < int(v2.size()); i++){
      int n = carry + v2[i];
      res.push_back(n % N);
      carry = n / N;
    }
    while(1){
      if(carry == 0) break;
      res.push_back(carry % N);
      carry = carry / N;
    }
    return res;
  }

  const mp_digit mp_shift(const mp_digit &v1, int n){
    mp_digit res;
    for(int i = 0; i < n; i++){
      res.push_back(0);
    }
    for(int i = 0; i < int(v1.size()); i++){
      res.push_back(v1[i]);
    }
    return res;
  }


  const mp_digit mp_mul(const mp_digit &v1, const mp_digit &v2){
    mp_digit res(v1.size() + v2.size() - 1, 0);
    for(int i = 0; i < int(v1.size()); i++){
      for(int j = 0; j < int(v2.size()); j++){
        res[i+j] += v1[i] * v2[j];
      }
    }
    for(int i = 0; i < int(res.size()) -1; i++){
      res[i+1] += res[i] / N;
      res[i] %= N;
    }
    while(res.back() >= N){
      res.push_back(res.back() / N);
      res[res.size()-2] %= N;
    }
    return res;
  }
}

using namespace MP;

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  mp_digit a[3];
  a[0] = mp(1);
  a[1] = mp(1);
  int n = 2;
  while(1){
    n++;
    mp_digit tmp = a[1];
    a[1] = mp_plus(a[0],a[1]);
    a[0] = tmp;
    if(mp_str(a[1]).size() >= 1000) break;
  }
  cout << mp_str(a[1]).size() << endl;
  cout << n << endl;

  return 0;
}
