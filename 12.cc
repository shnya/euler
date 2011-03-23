#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>



using namespace std;


//4  |1 2 4
//8  |1 2 4 8
//12 |1 2 3 4 12
//7  |1 7
//2  |1 2


//(n * (n + 1)) / 2
map<int,int> m;


int fact(int l, bool verbose = false){
  m.clear();
  int nmax = sqrt(l);
  for(int i = 2; i < nmax+1; i++){
    if(l % i == 0){
      l /= i;
      m[i]++;
      nmax = sqrt(l);
      i = 1;
    }
    if(l == 1) break;
  }
  if(l != 1) m[l]++;
  int res = 1;
  for(typeof(m.begin()) itr = m.begin();
      itr != m.end(); ++itr){
    if(verbose) cout << itr->first << "\t" << itr->second << endl;
    res *= (itr->second + 1);
  }
  return res;
}



int main(int argc, char *argv[])
{

  int res = 0;
  int cul = 0;
  //fact(28,true);
  for(int i = 1; i < 100000; i++){
    cul += i;
    int res1 = fact(cul);
    //cout << cul << "\t" << res1 << endl;
    if(res1 > 500){
      fact(cul,true);
      res = cul;
      break;
    }
  }
  cout << res << endl;

  return 0;
}
