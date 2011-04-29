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

template<class T> std::ostream &operator<<(std::ostream &o,const std::vector<T> &v)
{ o << "["; for(std::size_t i=0;i<v.size();i++) o << v[i] << (i < v.size()-1 ? ",":""); return o << "]"; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::pair<T,U> &v)
{ return o << v.first << ":" << v.second; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::map<T,U> &v)
{ o << "{"; typename std::map<T,U>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }
template<class T> std::ostream &operator<<(std::ostream &o,const std::set<T> &v)
{ o << "{"; typename std::set<T>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }


void combi(size_t i , int r, const vector<int> &v,
           vector<int> path, vector<vector<int> > &result){
  if(r == 0){
    sort(path.begin(),path.end());
    result.push_back(path);
    return;
  }
  if(i == v.size()){
    return;
  }
  path.push_back(v[i]);
  combi(i+1,r-1,v,path,result);
  path.pop_back();
  combi(i+1,r,v,path,result);
}

bool check1(const vector<int> &v, int n){
  REP(i,SZ(v)) if(v[i] == n) return true;
  return false;
}

bool check2(const vector<int> &v1, const vector<int> &v2,
            int n1, int n2){
  if(check1(v1,n1)){
    if(check1(v2,n2)){
      return true;
    }
  }
  if(check1(v2,n1)){
    if(check1(v1,n2)){
      return true;
    }
  }
  return false;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  int tmpar[] = {0,1,2,3,4,5,6,7,8,9};
  vector<int> vvv(tmpar,tmpar+10);
  //cout << vvv << endl;
  vector<vector<int> > combia;
  combi(0,6,vvv,vector<int>(), combia);
  vector<vector<int> > combib(combia);
  set<pair<vector<int>,vector<int> > > res;
  set<vector<int> > res2;
  cout << combia << endl;
  for(vector<vector<int> >::iterator itr = combia.begin();
      itr != combia.end(); ++itr){
    vector<int> v1(*itr);
    if(check1(v1,6) && !check1(v1,9)) v1.push_back(9);
    if(check1(v1,9) && !check1(v1,6)) v1.push_back(6);
    sort(v1.begin(),v1.end());
    for(vector<vector<int> >::iterator jtr = combib.begin();
        jtr != combib.end(); ++jtr){
      vector<int> v2(*jtr);
      if(check1(v2,6) && !check1(v2,9)) v2.push_back(9);
      if(check1(v2,9) && !check1(v2,6)) v2.push_back(6);
      sort(v2.begin(),v2.end());
      if(check2(v1,v2,0,1) &&
         check2(v1,v2,0,4) &&
         check2(v1,v2,0,9) &&
         check2(v1,v2,1,6) &&
         check2(v1,v2,2,5) &&
         check2(v1,v2,3,6) &&
         check2(v1,v2,4,9) &&
         check2(v1,v2,6,4) &&
         check2(v1,v2,8,1)){
        res.insert(make_pair(*itr,*jtr));
        cout << *itr << *jtr << endl;
      }
    }
  }
  cout << res.size()/2 << endl;
  cout << res2.size() << endl;



  return 0;
}
