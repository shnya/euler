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



const string maps[] = {
  "GO",
  "A1",
  "CC1",
  "A2",
  "T1",
  "R1",
  "B1",
  "CH1",
  "B2",
  "B3",
  "JAIL",
  "C1",
  "U1",
  "C2",
  "C3",
  "R2",
  "D1",
  "CC2",
  "D2",
  "D3",
  "FP",
  "E1",
  "CH2",
  "E2",
  "E3",
  "R3",
  "F1",
  "F2",
  "U2",
  "F3",
  "G2J",
  "G1",
  "G2",
  "CC3",
  "G3",
  "R4",
  "CH3",
  "H1",
  "T2",
  "H2"
};

deque<int> cc_card(16,-1), ch_card(16,-1);

int move(int n){
  if(maps[n].substr(0,2) == "CH"){
    int card = cc_card.front();
    cc_card.pop_front();
    cc_card.push_back(card);
    if(card == 1){
      return 0;
    }else if(card == 2){
      return 10;
    }else if(card == 3){
      return 11;
    }else if(card == 4){
      return 24;
    }else if(card == 5){
      return 39;
    }else if(card == 6){
      return 5;
    }else if(card == 7 || card == 8){
      for(int i = 0; i < 40; i++){
        int n2 = (n + i) % 40;
        if(maps[n2].substr(0,1) == "R")
          return n2;
      }
    }else if(card == 9){
      for(int i = 0; i < 40; i++){
        int n2 = (n + i) % 40;
        if(maps[n2].substr(0,1) == "U")
          return n2;
      }
    }else if(card == 10){
      n -= 3;
      if(n < 0) n = 40 - n;
      return n;
    }else{
      return n;
    }
  }else if(maps[n].substr(0,2) == "CC"){
    int card = ch_card.front();
    ch_card.pop_front();
    ch_card.push_back(card);
    if(card == 1){
      return 0;
    }else if(card == 2){
      return 10;
    }else {
      return n;
    }
  }else if(maps[n] == "G2J"){
    return 10;
  }
  return n;
}


int main(int argc, char *argv[]){
  ios::sync_with_stdio(false); 
  int N = 40;
  srand((unsigned int)time(0));
  vector<long double> prob(N,0.0);
  for(int i = 0; i < 2; i++) cc_card[i] = i+1;
  for(int i = 0; i < 10; i++) ch_card[i] = i+1;
  random_shuffle(cc_card.begin(),cc_card.end());
  random_shuffle(ch_card.begin(),ch_card.end());
  prob[0] = 1.0;
  for(int i = 0; i < 500000; i++){
    vector<long double> next_prob(N,0.0);
    for(int j = 0; j < N; j++){
      for(int k = 1; k <= 6; k++){
        int n = (j + k) % 40;
        n = move(n);
        next_prob[n] += prob[j] * (1.0/6);
        //cout << n << " " << next_prob[n] << endl;
      }
    }
    prob = next_prob;
  }
  vector<pair<long double, int> > v;
  for(int i = 0; i < 40; i++){
    //cout << i << " " << maps[i] << " " << prob[i] << endl;
    v.push_back(make_pair(prob[i],i));
  }
  sort(v.begin(),v.end(),greater<pair<long double,int> >());
  for(int i = 0; i < 40; i++){
    cout << v[i].second << " " << maps[v[i].second] << " "
         << v[i].first << endl;
  }
  return 0;
}
