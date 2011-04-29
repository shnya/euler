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

#include <queue>
template<class T> std::ostream &operator<<(std::ostream &o,const std::vector<T> &v)
{ o << "["; for(std::size_t i=0;i<v.size();i++) o << v[i] << (i < v.size()-1 ? ",":""); return o << "]"; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::pair<T,U> &v)
{ return o << v.first << ":" << v.second; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::map<T,U> &v)
{ o << "{"; typename std::map<T,U>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }
template<class T> std::ostream &operator<<(std::ostream &o,const std::set<T> &v)
{ o << "{"; typename std::set<T>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }



int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  int N = 10;
  int a,b,c,d;
  int maxn=0;
  FOR(i,1,N) FOR(j,i+1,N) FOR(k,j+1,N) FOR(l,k+1,N){
    //int i = 1, j = 2, k = 3, l = 4;
    vector<int> v;
    v.push_back(i);v.push_back(j);v.push_back(k);v.push_back(l);
    queue<vector<int> > Q;
    vector<bool> res(200,false);
    Q.push(v);
    while(!Q.empty()){
      vector<int> v2 = Q.front();
      Q.pop();
      if(v2.size() == 1){
        if(v2.back()>= 0 && v2.back() < 200) res[v2.back()] = true;
        continue;
      }
      FOR(x,0,SZ(v2)-1) FOR(y,x+1,SZ(v2)){
        vector<int> v3;
        REP(z,SZ(v2)) if(z != x && z != y) v3.push_back(v2[z]);
        int vx = v2[x];
        int vy = v2[y];
        v3.push_back(vx+vy);
        Q.push(v3);
        v3.pop_back();
        v3.push_back(vx-vy);
        Q.push(v3);
        v3.pop_back();
        v3.push_back(vy-vx);
        Q.push(v3);
        v3.pop_back();
        if(vy != 0 && vx % vy == 0){
          v3.push_back(vx/vy);
          Q.push(v3);
          v3.pop_back();
        }
        if(vx != 0 && vy % vx == 0){
          v3.push_back(vy/vx);
          Q.push(v3);
          v3.pop_back();
        }
        v3.push_back(vy*vx);
        Q.push(v3);
        v3.pop_back();
      }
    }
    int count = 0;
    for(int o = 1; o < 200; o++){
      if(!res[o]) break;
      count++;
    }
    if(count > maxn){
      a = i, b = j, c = k, d = l;
      maxn = count;
    }
    cout << i << " " << j << " " << k << " " << l
         << " " << count << endl;
  }
  //cout << res << endl;

  cout << a << " " << b << " " << c << " " << d
       << " " << maxn << endl;

  return 0;
}
