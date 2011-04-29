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
#include <limits>
#include <fstream>

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





int main(int argc, char *argv[]){
  ios::sync_with_stdio(false); 
  ifstream ifs("roman.txt");
  string line;
  int diff = 0;
  while(getline(ifs,line)){
    if(line[line.size()-1] == '\r') line.erase(line.size()-1,1);
    string orig = line;
    size_t siz = line.size();
    
    while(1){
      int n = 1;
      size_t i;
      if((i = line.find("CM")) != string::npos){
        line.replace(i,2,"DCCCC"); n--;
      }
      if((i = line.find("CD")) != string::npos){
        line.replace(i,2,"CCCC"); n--;
      }
      if((i = line.find("XC")) != string::npos){
        line.replace(i,2,"LXXXX"); n--;
      }
      if((i = line.find("XL")) != string::npos){
        line.replace(i,2,"XXXX"); n--;
      }
      if((i = line.find("IX")) != string::npos){
        line.replace(i,2,"VIIII"); n--;
      }
      if((i = line.find("IV")) != string::npos){
        line.replace(i,2,"IIII"); n--;
      }
      if(n == 1) break;
    }
    int sum = 0;
    for(size_t i = 0; i < line.size(); i++){
      if(line[i] == 'M') sum += 1000;
      if(line[i] == 'D') sum += 500;
      if(line[i] == 'C') sum += 100;
      if(line[i] == 'L') sum += 50;
      if(line[i] == 'X') sum += 10;
      if(line[i] == 'V') sum += 5;
      if(line[i] == 'I') sum += 1;
    }
    int res = 0;
    res += (sum / 1000);
    sum %= 1000;
    if(sum >= 900){
      res += 2;
      sum -= 900;
    }else if(sum >= 500){
      res += 1;
      sum -= 500;
    }else if(sum >= 400){
      res += 2;
      sum -= 400;
    }
    res += (sum / 100);
    sum %= 100;
    if(sum >= 90){
      res += 2;
      sum -= 90;
    }else if(sum >= 50){
      res += 1;
      sum -= 50;
    }else if(sum >= 40){
      res += 2;
      sum -= 40;
    }
    res += (sum / 10);
    sum %= 10;
    if(sum >= 9){
      res += 2;
      sum -= 9;
    }else if(sum >= 5){
      res += 1;
      sum -= 5;
    }else if(sum >= 4){
      res += 2;
      sum -= 4;
    }
    res += sum;
    diff += siz - res;
    cout << orig << " " << sum << " " << (siz - res) << endl;
  }
  cout << diff << endl;
  return 0;
}
