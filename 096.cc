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


bool check(int i, int j, int n, const vector<vector<int> > &v){
  REP(k,9) if(v[i][k] == n) return false;
  REP(k,9) if(v[k][j] == n) return false;
  FOR(k,i/3*3,i/3*3+3) FOR(l,j/3*3,j/3*3+3)
    if(v[k][l] == n) return false;
  return true;
}

int sum;

void rec(int i, int j, vector<vector<int> > &v){
  if(j == 9){
    rec(i+1,0,v);
    return;
  }
  if(i == 9){
    cout << v << endl;
    sum += v[0][0] * 100 + v[0][1] * 10 + v[0][2];
    return;
  }
  if(v[i][j] != 0){
    rec(i,j+1,v);
    return;
  }
  for(int k = 1; k <= 9; k++){
    if(check(i,j,k,v)){
      //cout << "i=" << i << " j=" << j << " k=" << k << endl;
      v[i][j] = k;
      rec(i,j+1,v);
      v[i][j] = 0;
    }
  }
}

#include <fstream>


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  ifstream ifs("sudoku.txt");
  sum = 0;
  REP(i,50){
    string line;
    getline(ifs,line);
    vector<vector<int> > v;
    REP(j,9){
      getline(ifs,line);
      vector<int> v2(9);
      REP(k,9){
        v2[k] = line[k] - '0';
      }
      v.push_back(v2);
    }
    //cout << v << endl;
    rec(0,0,v);
  }
  cout << sum << endl;

  return 0;
}
