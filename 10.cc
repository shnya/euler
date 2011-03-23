#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

typedef long long int LLI;

int milion2 = 2000000;
int tbl[3000000];

void est(){
  int n = sizeof(tbl) / sizeof(tbl[0]);
  memset(tbl, 0, sizeof tbl);
  tbl[0] = 1;
  tbl[1] = 1;
  for(int i = 2; i < n; i++){
    if(tbl[i] == 0){
      for(int j = 2; j * i < n; j++){
        tbl[j * i] = 1;
      }
    }
  }
}


int main(int argc, char *argv[])
{
  LLI sum = 0;
  est();
  for(int i = 1; i < milion2; i++){
    if(tbl[i] == 0){
      sum+=i;
      //if(i > 1900000)
        //cout << i << endl;
    }
  }
  cout << sum << endl;
  return 0;
}


