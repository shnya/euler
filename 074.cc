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



int fact(int n){
  int res = 1;
  for(int i = 2; i <= n; i++){
    res *= i;
  }
  return res;
}
vector<int> factv(10);
vector<int> digit_sumv(1000001,-1);

int digit_sum(int n){
  if(n < 1000000 && digit_sumv[n] != -1)
    return digit_sumv[n];
  int sum = 0;
  int k = n;
  while(k != 0){
    sum += factv[k % 10];
    k /= 10;
  }
  if(n < 1000000) digit_sumv[n] = sum;
  return sum;
}


int find_repeat(int n){
  set<int> s;
  s.insert(n);
  int count = 1;
  while(count < 61){
    n = digit_sum(n);
    if(s.find(n) != s.end()){
      return count;
    }
    s.insert(n);
    count++;
  }
  return 0;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);

  for(int i = 0; i < 10; i++)
    factv[i] = fact(i);

  int count = 0;
  for(int i = 1; i < 1000000; i++){
    if(find_repeat(i) == 60){
      count++;
    }
  }
  cout << count << endl;

  return 0;
}
