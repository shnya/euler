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


void vec_set(size_t i, int n, vector<int> &v){
  if(i == 1){
    v[1] = n;
    v[14] = n;
  }else if(i == 2){
    v[2] = n;
    v[4] = n;
  }else if(i == 5){
    v[5] = n;
    v[7] = n;
  }else if(i == 8){
    v[8] = n;
    v[10] = n;
  }else if(i == 11){
    v[11] = n;
    v[13] = n;
  }else{
    v[i] = n;
  }
}
//1079196268385457
vector<string> res;
void rec(size_t i, int total, int maxnn, vector<int> &v, vector<bool> &used, const vector<int> &a){
  if(i == 15){
    cout << v << endl;
    string s;
    for(size_t j = 0; j < v.size(); j++){
      s += toString(v[j]);
    }
    if(s.size() == 16)
      res.push_back(s);
    return;
  }
  if(v[i] != -1){
    rec(i+1,total,maxnn,v,used,a);
    return;
  }
  for(size_t j = 0; j < a.size(); j++){
    int totaln = total;
    int maxn = maxnn;
    if(used[j]) continue;
    if(i == 2){
      totaln = a[j] + v[i-1] + v[i-2];
    }else if(i == 5 || i == 8 || i == 11){
      if(total != a[j] + v[i-1] + v[i-2])
        continue;
    }else if(i == 12){
      if(total != a[j] + v[i+1] + v[i+2] || a[j] < maxnn)
        continue;
    }else if(i == 0){
      maxn = a[j];
    }else if(i % 3 == 0){
      if(a[j] < maxnn)
        continue;
    }
    vec_set(i,a[j],v);
    used[j] = true;
    //cout << v << endl;
    rec(i+1,totaln,maxn,v,used,a);
    used[j] = false;
    vec_set(i,-1,v);
  }
}




int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  vector<int> v(15,-1);
  int _a[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> a(_a,_a+10);
  vector<bool> used(a.size(),false);
  rec(0,0,100,v,used,a);
  sort(res.rbegin(),res.rend());
  if(res.size() == 0){
    cout << "Not Found" << endl;
  }else{
    cout << res[0] << endl;
  }
  return 0;
}
