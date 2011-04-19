#include<iostream>

class Frac {
public:
  typedef long long int LLI;
private:
  LLI n,d;
public:
  static LLI _gcd(LLI m, LLI n){
    LLI temp;
    while(m % n != 0){
      temp = n;
      n = m % n;
      m = temp;
    }
    return n;
  }

  static LLI _lcm (LLI m, LLI n){
    return m * n / _gcd(m,n);
  }

private:
  void divided(){
    LLI m = _gcd(n,d);
    if(d < 0){
      d = -d;
      n = -n;
    }
    n /= m;
    d /= m;
  }

public:
  Frac(LLI _n = 0, LLI _d = 1) : n(_n), d(_d){
    divided();
  };
  friend Frac operator+(const Frac &a, const Frac &b);
  friend Frac operator-(const Frac &a, const Frac &b);
  friend Frac operator*(const Frac &a, const Frac &b);
  friend Frac operator/(const Frac &a, const Frac &b);
  friend std::ostream& operator<<(std::ostream &o, const Frac &a);
};

Frac operator+(const Frac &a, const Frac &b){
  Frac::LLI m = Frac::_lcm(a.d,b.d);
  return Frac((a.n * (m / a.d)) + (b.n * (m / b.d)), m);

}

Frac operator-(const Frac &a, const Frac &b){
  Frac::LLI m = Frac::_lcm(a.d,b.d);
  return Frac((a.n * (m / a.d)) - (b.n * (m / b.d)), m);
}

Frac operator*(const Frac &a, const Frac &b){
  return Frac(a.n * b.n, a.d * b.d);
}

Frac operator/(const Frac &a, const Frac &b){
  return Frac(a.n * b.d, a.d * b.n);
}

std::ostream& operator<<(std::ostream &o, const Frac &a){
  o << a.n << "/" << a.d;   return o;
}

using namespace std;

int main(int argc, char *argv[]){
  Frac a(1,2);

  for(int i = 0; i < 1000; i++){
    cout << 1 + a << endl;
    a = 2 + (1 / a);
  }

  return 0;
}
