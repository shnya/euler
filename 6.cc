#include <iostream>
#include <cstring>

using namespace std;

typedef long long int LLI;

int tbl[1234567];

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
  int c = 0;
  est();
  for(int i = 1; i < sizeof(tbl)/sizeof(tbl[0]); i++){
    if(tbl[i] == 0) c++;
    if(c == 10001){
      cout << i << endl;
      break;
    }
  }

  return 0;
}
