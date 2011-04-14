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

template<class T>
ostream& operator<<(ostream &o, vector<T> &v){
  o << "[";
  for(int i = 0; i < int(v.size())-1; i++) o << v[i] << ", ";
  if(v.size()!=0) o << v.back(); o << "]";
}

template<class T, class U>
ostream& operator<<(ostream &o, pair<T,U> &v){
  o << "{" << v.first << "," << v.second << "}";
}


vector<LLI> fact(LLI n){
  vector<LLI> res;
  LLI j = 2;
  while(n != 1){
    while(n % j == 0){
      res.PB(j);
      n /= j;
    }
    j++;
  }
  return res;
}

/*
  void rec2(LLI i, const vector<LLI> &v,
  vector<LLI> &path, vector<vector<LLI> > &groups,
  vector<bool> &used, vector<pair<LLI,LLI> > &result);

  void rec1(const vector<LLI> &v,
  vector<vector<LLI> > &groups, vector<bool> &used,
  vector<pair<LLI,LLI> > &result){
  int k = -1;
  REP(j,SZ(v)) if(!used[j]){ k = j; break; }
  if(k == -1){
  LLI sum = 0;
  REP(x,SZ(groups)){
  LLI n = 1;
  REP(y,SZ(groups[x])){
  n *= groups[x][y];
  }
  sum += n;
  }
  result.push_back(make_pair(groups.size(),sum));
  return;
  }
  vector<LLI> path;
  path.push_back(v[k]);
  used[k] = true;
  rec2(k+1,v,path,groups,used,result);
  used[k] = false;
  }

  void rec2(LLI i, const vector<LLI> &v,
  vector<LLI> &path, vector<vector<LLI> > &groups,
  vector<bool> &used, vector<pair<LLI,LLI> > &result){
  groups.push_back(path);
  rec1(v,groups,used,result);
  groups.pop_back();

  FOR(j,i,SZ(v)){
  if(used[j]) continue;
  path.push_back(v[j]);
  used[j] = true;
  rec2(j+1,v,path,groups,used,result);
  used[j] = false;
  path.pop_back();
  }

  }
*/

void rec2(LLI i, const vector<LLI> &v,
          LLI sum, LLI mul, LLI n,
          vector<bool> &used, set<pair<LLI,LLI> > &result);

void rec1(const vector<LLI> &v,
          LLI sum, LLI n,
          vector<bool> &used, set<pair<LLI,LLI> > &result){
  int k = -1;
  REP(j,SZ(v)) if(!used[j]){ k = j; break; }
  if(k == -1){
    result.insert(make_pair(n,sum));
    return;
  }
  vector<LLI> path;
  path.push_back(v[k]);
  used[k] = true;
  rec2(k+1,v,v[k],sum,n,used,result);
  used[k] = false;
}

void rec2(LLI i, const vector<LLI> &v,
          LLI sum, LLI mul, LLI n,
          vector<bool> &used, set<pair<LLI,LLI> > &result){
  rec1(v,sum+mul,n,used,result);

  FOR(j,i,SZ(v)){
    if(used[j]) continue;
    used[j] = true;
    rec2(j+1,v,mul*v[j],sum,n,used,result);
    used[j] = false;
  }

}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  vector<set<pair<LLI,LLI> > > dp(100000);


  set<LLI> s;
  LLI end = 12001;
  //LLI end = 13;
  for(LLI i=2; i < end; i++){
    for(LLI j = i+1; j < 100000; j++){
      if(dp[j].size() == 0){
        vector<LLI> v = fact(j);
        vector<bool> used(v.size());
        set<pair<LLI,LLI> > result;
        rec1(v,0,0,used,result);
        dp[j] = result;
      }
      set<pair<LLI,LLI> > &list = dp[j];
      EACH(k,list){
        //cout << i << " " << j << " " << list[k].first
        //<< " " << list[k].second << endl;
        if(k->first <= i){
          if((i - k->first + k->second) == j){
            cout << i << " " << j << endl;
            s.insert(j);
            goto success;
          }
        }
      }
    }
    cout << "nothing" << endl;
    return 0;
  success:;
  }

  LLI sum = 0;
  EACH(i,s){
    sum += *i;
  }
  cout << sum << endl;
  return 0;
}
