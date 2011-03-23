#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include <cassert>


using namespace std;



int main(int argc, char *argv[])
{
  ifstream ifs("13.txt");

  vector<string> v;
  for(int i = 0; i < 100; i++){
    string line;
    getline(ifs, line);
    v.push_back(line);
    assert(line.size() == 50);
  }
  assert(v.size() == 100);

  int carry = 0;
  string res;
  for(int i = 49; i >= 0; --i){
    for(int j = 0; j < 100; j++){
      carry += v[j][i] - '0';
    }
    res.push_back((carry % 10) + '0');
    carry /= 10;
    //cout << carry << endl;
  }
  reverse(res.begin(),res.end());
  ostringstream oss;
  oss << carry;
  //cout << carry;
  res = oss.str() + res;
  cout << res.substr(0,10) << endl;

  return 0;
}



