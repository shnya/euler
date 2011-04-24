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

template<class T>ostream &operator<<(ostream &o,const vector<T> &v)
{o<<"[";for(int i=0;i<SZ(v);i++)o<<v[i]<<(i<SZ(v)-1?",":""); return o<<"]";}
template<class T,class U>ostream &operator<<(ostream &o,const pair<T,U> &v)
{return o<<v.first<<":"<<v.second<<"";}
template<class T,class U>ostream &operator<<(ostream &o,const map<T,U> &v)
{o<<"{";typename map<T,U>::const_iterator i,j;i=j=v.begin();++j;for(;i!=v.end();++j,++i)o<<*i<<(j!=v.end()?",":""); return o<<"}";}
template<class T>ostream &operator<<(ostream &o,const set<T> &v)
{o<<"{";typename set<T>::const_iterator i,j;i=j=v.begin();++j;for(;i!=v.end();++j,++i)o<<*i<<(j!=v.end()?",":""); return o<<"}";}

int main(int argc, char *argv[]){
  vector<bool> v(20000000,false);
  //memset(a,0,sizeof a);
  //vector<int> v2(3001);
  //FOR(i,1,SZ(v2)) v2[i] = i * i;
  vector<int> v2(100,3);
  cout << v2 << endl;
  map<string,int> m;
  m["aaa"] = 3;
  m["bbb"] = 2;
  cout << m << endl;

  return 0;
  FOR(i,1,3000){
    int n = i * i;
    FOR(j,i,3000){
      v[n + j*j] = 1;
    }
  }
  int j = 0;
  REP(i,SZ(v)){
    if(v[i]) j++;
    if(j == 1000000){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
