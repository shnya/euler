#include <iostream>
using namespace std;

typedef long long int LLI;


LLI gcd(LLI a, LLI b){
  if(a % b == 0){
    return b;
  }else{
    gcd(b, a % b);
  }
}

LLI lcm(LLI a, LLI b){
  return a * b / gcd(a,b);
}


int main(int argc, char *argv[])
{
  LLI a = 1;
  for(LLI i = 1; i <= 20; i++){
    a = lcm(a,i);
    cout << a << endl;
  }
  for(LLI i = 1; i <= 20; i++){
    cout << a % i << endl;
  }
  cout << a << endl;
  return 0;
}
