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
#include <cassert>


using namespace std;


namespace MP{
  const int N = 10000;
  typedef vector<int> mp_digit;

  mp_digit mp(int n){
    mp_digit res;
    while(1){
      res.push_back(n % N);
      n /= N;
      if(n == 0) break;
    }
    return res;
  }

  string mp_str(const mp_digit &v){
    string str;
    for(int i = 0; i < int(v.size()); i++){
      int n = v[i];
      for(int j = 0; j < log10(N); j++){
        str += (n % 10) + '0';
        n /= 10;
      }
    }
    reverse(str.begin(), str.end());
    return str;
  }

  const mp_digit mp_plus(const mp_digit &v1, const mp_digit &v2){
    if(v1.size() > v2.size())
      return mp_plus(v2, v1);

    mp_digit res;
    int carry = 0;
    for(int i = 0; i < int(v1.size()); i++){
      int n = carry + v1[i] + v2[i];
      res.push_back(n % N);
      carry = n / N;
    }
    for(int i = v1.size(); i < int(v2.size()); i++){
      int n = carry + v2[i];
      res.push_back(n % N);
      carry = n / N;
    }
    while(1){
      if(carry == 0) break;
      res.push_back(carry % N);
      carry = carry / N;
    }
    return res;
  }

  const mp_digit mp_shift(const mp_digit &v1, int n){
    mp_digit res;
    for(int i = 0; i < n; i++){
      res.push_back(0);
    }
    for(int i = 0; i < int(v1.size()); i++){
      res.push_back(v1[i]);
    }
    return res;
  }


  const mp_digit mp_mul(const mp_digit &v1, const mp_digit &v2){
    mp_digit res(v1.size() + v2.size() - 1, 0);
    for(int i = 0; i < int(v1.size()); i++){
      for(int j = 0; j < int(v2.size()); j++){
        res[i+j] += v1[i] * v2[j];
      }
    }
    for(int i = 0; i < int(res.size()) -1; i++){
      res[i+1] += res[i] / N;
      res[i] %= N;
    }
    while(res.back() >= N){
      res.push_back(res.back() / N);
      res[res.size()-2] %= N;
    }
    return res;
  }
}

using namespace MP;

int main(int argc, char *argv[]){
  ios::sync_with_stdio(false);
  mp_digit res = mp(1024);
  for(int i = 0; i < 90; i++){
    res = mp_mul(res, mp(1024));
  }
  mp_digit res2 = res;
  for(int i = 0; i < 9; i++){
    res2 = mp_mul(res2, res);
  }
  string s = mp_str(res2);
  cout << s << endl;
  int result = 0;
  for(int i = 0; i < int(s.size()); i++){
    result += s[i] - '0';
  }


  cout << result  << endl;
  return 0;
}
