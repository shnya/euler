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


#include <fstream>

template<class T> std::ostream &operator<<(std::ostream &o,const std::vector<T> &v)
{ o << "["; for(std::size_t i=0;i<v.size();i++) o << v[i] << (i < v.size()-1 ? ",":""); return o << "]"; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::pair<T,U> &v)
{ return o << v.first << ":" << v.second; }
template<class T,class U> std::ostream &operator<<(std::ostream &o,const std::map<T,U> &v)
{ o << "{"; typename std::map<T,U>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }
template<class T> std::ostream &operator<<(std::ostream &o,const std::set<T> &v)
{ o << "{"; typename std::set<T>::const_iterator i=v.begin(),j=i;++j;for(;i!=v.end();++i,++j) o << *i << (j!=v.end()? ",":""); return o << "}"; }


std::vector<std::string>
split(const std::string &str, const std::string &delim){
  std::vector<std::string> res;
  size_t current = 0, found, delimlen = delim.size();
  while((found = str.find(delim, current)) != std::string::npos){
    res.push_back(string(str, current, found - current));
    current = found + delimlen;
  }
  res.push_back(std::string(str, current, str.size() - current));
  return res;
}

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  ifstream ifs("words098.txt");
  string line;
  getline(ifs,line);
  vector<string> words_orig = split(line,",");
  vector<string> words,sorted;
  REP(i,SZ(words_orig)){
    string s = words_orig[i].substr(1,words_orig[i].size()-2);
    words.push_back(s);
    sort(s.begin(),s.end());
    sorted.push_back(s);
  }

  vector<pair<string,string> > pairs;
  FOR(i,0,SZ(words)){
    FOR(j,i+1,SZ(words)){
      if(sorted[i] == sorted[j] && words[i] != words[j]){
        pairs.push_back(make_pair(words[i],words[j]));
      }
    }
  }

  vector<LLI> squares;
  FOR(i,1,100001){
    squares.push_back(i*i);
  }

  vector<pair<pair<string,string>, pair<LLI,LLI> > > res;
  LLI maxn = 0;
  REP(l,SZ(pairs)){
    //cout << pairs[l].first << " " << pairs[l].second << endl;
    string &s1 = pairs[l].first;
    string &s2 = pairs[l].second;
    LLI siz = s1.size();
    LLI end = 1; REP(i,siz) end *= 10;
    for(int i = 0; squares[i] < end; i++){
      if(squares[i] < end / 10) continue;
      LLI n = squares[i];
      size_t j = siz-1;
      map<char,int> cmap;
      LLI b = 0;
      while(n != 0){
        char c = s1[j];
        int a = n % 10;
        EACH(k,cmap){
          if(k->first == c && a != k->second){
            goto fail;
          }
          if(k->second == a && c != k->first){
            goto fail;
          }
        }
        cmap[c] = a;
        n /= 10;
        j--;
      }
      if(cmap[s2[0]] == 0) goto fail;
      for(int k = 0; k < siz; k++){
        b *= 10;
        b += cmap[s2[k]];
      }
      //cout << b << endl;
      //cout << end << endl;
      for(int k = 0; squares[k] < end; k++){
        if(squares[k] == b){
          maxn = max(maxn,max(squares[i],b));
          res.push_back(make_pair(make_pair(s1,s2),make_pair(squares[i],b)));
          break;
        }
      }
    fail:;
    }
  }

  cout << res << endl;
  cout << maxn << endl;

  return 0;
}
