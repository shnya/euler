#ifndef EULER_HPP
#define EULER_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

namespace euler {
  class BigInt {
    typedef unsigned short US;
    typedef unsigned int UI;
    typedef std::vector<US> Digits;
    // N must be (N <= std::numeric_limits<unsigned short>::max()).
    // N must be 10^k for operator<<.
    const static UI N = 10000;
    bool is_minus;
    Digits digits;

    int nth(size_t n) const {
      if(n < digits.size())
        return digits[n];
      else
        return 0;
    }

    static void lshift(BigInt &x, int n){
      Digits &x_digits = x.digits;
      for(int i = 0; i < n; i++){
        x_digits.insert(x_digits.begin(),0);
      }
    }

    static void rshift(BigInt &x, int n){
      Digits &x_digits = x.digits;
      for(int i = 0; i < n; i++){
        x_digits.erase(x_digits.begin());
      }
    }

    BigInt& subtractor(const BigInt *x, const BigInt *y){
      bool carry = false;
      size_t size = x->digitnum();
      digits.resize(size,0);
      for(size_t i = 0; i < size; i++){
        UI n = 0;
        if(x->nth(i) > y->nth(i)){
          n = x->nth(i) - y->nth(i);
          if(carry){
            n--;
            carry = false;
          }
        }else if(y->nth(i) > x->nth(i)){
          n = N - (y->nth(i) - x->nth(i));
          if(carry){
            n--;
          }
          carry = true;
        }else{
          if(carry){
            n = N-1;
          }else{
            n = 0;
          }
        }
        digits[i] = n;
      }
      while(digits.size() != 0 && digits.back() == 0)
        digits.pop_back();

      return *this;
    }

    BigInt& adder(const BigInt &x){
      size_t size = std::max(x.digitnum(),digitnum());
      digits.resize(size,0);
      UI carry = 0;
      for(size_t i = 0; i < size; i++){
        UI n = carry + x.nth(i) + this->nth(i);
        digits[i] = n % N;
        carry = n / N;
      }
      if(carry)
        digits.push_back(carry);
      return *this;
    }

    BigInt& multiplier(const BigInt &y){
      Digits res(digitnum() + y.digitnum() + 1,0);
      size_t xsize = digitnum(), ysize = y.digitnum();
      for(size_t i = 0; i < xsize; ++i){
        UI carry = 0;
        for(size_t j = 0; j < ysize; ++j){
          UI n = nth(i) * y.nth(j) + carry;
          if(n >= N){
            carry = n / N;
            n %= N;
          }else{
            carry = 0;
          }
          n += res[i+j];
          if(n > N - 1){
            carry++;
            n -= N;
          }
          res[i+j] = n;
        }
        size_t j = ysize;
        while(carry != 0){
          UI n = carry + res[i+j];
          carry = n / N;
          if(n >= N){
            n %= N;
          }
          res[i+j] = n;
          j++;
        }
        res[i+ysize] += carry;
      }
      digits = res;
      while(digits.size() != 0 && digits.back() == 0)
        digits.pop_back();
      return *this;
    }

    BigInt& divider(const BigInt &yy){
      BigInt y = yy, x = *this;
      int count = 0;
      if(y == 0){
        is_minus = false;
        digits.clear();
        return *this;
      }else if(y == 1){
        return *this;
      }

      while(x >= y){
        count++;
        lshift(y,1);
      }
      if(count == 0){
        is_minus = false;
        digits.clear();
        return *this;
      }
      rshift(y,1);
      count--;
      Digits res_d;
      for(int i = count; i >= 0; i--){
        int div;
        size_t xsize = x.digitnum();
        size_t ysize = y.digitnum();
        if(xsize > 1 && xsize != ysize){
          div = (x.nth(xsize-1) * N + x.nth(xsize-2)) / y.nth(ysize-1);
        }else{
          div = x.nth(xsize-1) / y.nth(ysize-1);
        }
        x -= (y * div);
        while(div > 0){
          if(x >= 0)
            break;
          x += y;
          --div;
        }
        res_d.push_back(div);
        rshift(y,1);
      }
      reverse(res_d.begin(),res_d.end());
      digits = res_d;

      while(digits.size() != 0 && digits.back() == 0)
        digits.pop_back();
      return *this;
    }

    // x > y = 1
    // x < y = -1
    // x == y = 0
    int flg_compare(const BigInt &y) const {
      if(is_minus && !y.is_minus) return -1;  // x = -1, y =  1  => x < y = -1
      if(!is_minus && y.is_minus) return 1;   // x =  1, y = -1  => x > y =  1
      return 0;
    }

    // abs(x) > abs(y) = 1
    // abs(x) < abs(y) = -1
    // abs(x) == abs(y) = 0
    int digit_compare(const BigInt &y) const {
      if(digitnum() < y.digitnum()){
        return -1;
      }else if(digitnum() > y.digitnum()){
        return 1;
      }
      const Digits& x_digits = digits;
      const Digits& y_digits = y.digits;
      Digits::const_reverse_iterator xi = x_digits.rbegin();
      Digits::const_reverse_iterator yi = y_digits.rbegin();
      for(; xi != x_digits.rend() && yi != y_digits.rend(); ++xi,++yi){
        if(*xi < *yi){
          return -1;
        }else if(*xi > *yi){
          return 1;
        }
      }
      return 0;
    }

  public:
    BigInt(long n = 0) : is_minus(false) {
      if(n < 0){
        is_minus = true;
        n = -n;
      }
      while(n != 0){
        digits.push_back(n % N);
        n /= N;
      }
    }

    BigInt& operator+=(const BigInt &y){
      if(is_minus ^ y.is_minus){
        if(digit_compare(y) >= 0){ // abs(x) >= abs(y)
          return subtractor(this, &y);
        }else{ // abs(x) < abs(y)
          is_minus = !is_minus;
          return subtractor(&y,this);
        }
      }
      return adder(y);
    }

    BigInt& operator-=(const BigInt &y){
      bool y_is_minus = !y.is_minus;
      if(is_minus ^ y_is_minus){
        if(digit_compare(y) >= 0){  
          return subtractor(this, &y);
        }else{
          is_minus = !is_minus;
          return subtractor(&y,this);
        }
      }
      return adder(y);
    }

    BigInt& operator-(void){
      is_minus = !is_minus;
      return *this;
    }

    BigInt& operator*=(const BigInt &y){
      is_minus ^= y.is_minus;
      return multiplier(y);
    }

    BigInt& operator/=(const BigInt &y){
      is_minus ^= y.is_minus;
      return divider(y);
    }

    BigInt& operator%=(const BigInt &y){
      return *this -= *this / y * y;
    }

    BigInt& operator=(const BigInt &x){
      if(&x == this) return *this;
      is_minus = x.is_minus;
      digits = x.digits;
      return *this;
    }

    size_t digitnum(void) const {
      return digits.size();
    }

    const Digits& data(void) const {
      return digits;
    }

    bool flg(void) const {
      return is_minus;
    }

    friend bool operator==(const BigInt &x, const BigInt &y);
    friend bool operator!=(const BigInt &x, const BigInt &y);
    friend bool operator>(const BigInt &x, const BigInt &y);
    friend bool operator>=(const BigInt &x, const BigInt &y);
    friend bool operator<(const BigInt &x, const BigInt &y);
    friend bool operator<=(const BigInt &x, const BigInt &y);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);
    friend BigInt operator*(const BigInt &x, const BigInt &y);
    friend BigInt operator/(const BigInt &x, const BigInt &y);
    friend std::ostream& operator<<(std::ostream &o, const BigInt &x);
  };

  BigInt operator+(const BigInt &x, const BigInt &y){
    BigInt res(x);
    res += y;
    return res;
  }

  BigInt operator-(const BigInt &x, const BigInt &y){
    BigInt res(x);
    res -= y;
    return res;
  }

  BigInt operator*(const BigInt &x, const BigInt &y){
    BigInt res(x);
    res *= y;
    return res;
  }

  BigInt operator/(const BigInt &x, const BigInt &y){
    BigInt res(x);
    res /= y;
    return res;
  }

  BigInt operator%(const BigInt &x, const BigInt &y){
    BigInt res(x);
    res %= y;
    return res;
  }

  bool operator==(const BigInt &x, const BigInt &y){
    return x.flg_compare(y) == 0 && x.digit_compare(y) == 0;
  }

  bool operator!=(const BigInt &x, const BigInt &y){
    if(x == y)
      return false;
    else
      return true;
  }

  bool operator>(const BigInt &x, const BigInt &y){
    int flg_compare = x.flg_compare(y);
    int digit_compare = x.digit_compare(y);
    if(x.is_minus) digit_compare = -digit_compare;
    return x.flg_compare(y) > 0 ||
      (flg_compare == 0 && digit_compare > 0);
  }

  bool operator>=(const BigInt &x, const BigInt &y){
    int flg_compare = x.flg_compare(y);
    int digit_compare = x.digit_compare(y);
    if(x.is_minus) digit_compare = -digit_compare;
    return flg_compare < 0 ||
      (flg_compare == 0 && x.digit_compare(y) >= 0);
  }

  bool operator<(const BigInt &x, const BigInt &y){
    if(y > x)
      return true;
    else
      return false;
  }

  bool operator<=(const BigInt &x, const BigInt &y){
    if(y >= x)
      return true;
    else
      return false;
  }


  std::ostream& operator<<(std::ostream &o, const BigInt &x){
    /*
    // for N != 10^{n}
    BigInt k = x;
    vector<int> v;
    while(k != 0){
    v.push_back((k % 10).nth(0));
    k /= 10;
    }
    while(v.size() != 0 && v.back() == 0)
    v.pop_back();
    */
    if(x == 0) return o << "0";
    std::ostringstream os;
    const BigInt::Digits digits = x.data();
    for(size_t i = 0; i < digits.size(); i++){
      BigInt::UI k = digits[i];
      for(BigInt::UI j = 1; j < BigInt::N; j *= 10){
        os << (k % 10);
        k /= 10;
      }
    }
    std::string s(os.str());
    reverse(s.begin(),s.end());
    size_t pos = 0;
    for(size_t i = 0; i < s.size(); i++){
      if(s[i] == '0')
        pos++;
      else
        break;
    }
    return o << (x.is_minus ? "-" : "") << s.substr(pos);
  }

  BigInt pow(const BigInt &xx, unsigned long n){
    BigInt x(xx);
    BigInt res(1);
    while(n != 0){
      if(n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }

  BigInt fact(unsigned long n){
    BigInt x(1);
    for(unsigned long i = 2; i < n; i++){
      x *= i;
    }
    return x;
  }

  class Frac {
    BigInt n,d;
    static BigInt _gcd(BigInt _m, BigInt _n){
      if(_m < 0) _m = -_m;
      if(_n < 0) _n = -_n;
      BigInt temp;
      while(_m % _n != 0){
        temp = _n;
        _n = _m % _n;
        _m = temp;
      }
      return _n;
    }

    static BigInt _lcm (BigInt k, BigInt l){
      if(k < 0) k = -k;
      if(l < 0) l = -l;
      return k * l / _gcd(k,l);
    }

    void divided(){
      BigInt m = _gcd(n,d);
      if(d < 0){
        d = -d;
        n = -n;
      }
      n /= m;
      d /= m;
    }

  public:
    Frac(BigInt _n = 0, BigInt _d = 1) : n(_n), d(_d){
      divided();
    };

    Frac& operator=(const Frac &f){
      if(&f == this) return *this;
      n = f.n;
      d = f.d;
      return *this;
    }

    Frac& operator+=(const Frac &f){
      BigInt m = _lcm(d,f.d);
      n = n * (m / d) + f.n * (m / f.d);
      d = m;
      divided();
      return *this;
    }
    Frac& operator-=(const Frac &f){
      BigInt m = _lcm(d,f.d);
      n = n * (m / d) - f.n * (m / f.d);
      d = m;
      divided();
      return *this;
    }

    Frac& operator*=(const Frac &f){
      n *= f.n;
      d *= f.d;
      divided();
      return *this;
    }

    Frac& operator/=(const Frac &f){
      n *= f.d;
      d *= f.n;
      divided();
      return *this;
    }

    friend bool operator==(const Frac &x, const Frac &y);
    friend bool operator!=(const Frac &x, const Frac &y);
    friend bool operator>(const Frac &x, const Frac &y);
    friend bool operator>=(const Frac &x, const Frac &y);
    friend bool operator<(const Frac &x, const Frac &y);
    friend bool operator<=(const Frac &x, const Frac &y);
    friend Frac operator+(const Frac &a, const Frac &b);
    friend Frac operator-(const Frac &a, const Frac &b);
    friend Frac operator*(const Frac &a, const Frac &b);
    friend Frac operator/(const Frac &a, const Frac &b);
    friend std::ostream& operator<<(std::ostream &o, const Frac &a);
  };

  Frac operator+(const Frac &a, const Frac &b){
    Frac res(a);
    res += b;
    return res;
  }

  Frac operator-(const Frac &a, const Frac &b){
    Frac res(a);
    res -= b;
    return res;
  }

  Frac operator*(const Frac &a, const Frac &b){
    Frac res(a);
    res *= b;
    return res;
  }

  Frac operator/(const Frac &a, const Frac &b){
    Frac res(a);
    res /= b;
    return res;
  }

  bool operator==(const Frac &x, const Frac &y){
    if(x.n == y.n && x.d == y.d)
      return true;
    else
      return false;
  }

  bool operator!=(const Frac &x, const Frac &y){
    if(x == y)
      return false;
    else
      return true;
  }

  bool operator>(const Frac &x, const Frac &y){
    Frac sub = x - y;
    if(sub.n > 0)
      return true;
    else
      return false;
  }

  bool operator>=(const Frac &x, const Frac &y){
    if(x == y || x > y)
      return true;
    else
      return false;
  }

  bool operator<(const Frac &x, const Frac &y){
    if(y > x)
      return true;
    else
      return false;
  }

  bool operator<=(const Frac &x, const Frac &y){
    if(x == y || y > x)
      return true;
    else
      return false;
  }


  std::ostream& operator<<(std::ostream &o, const Frac &a){
    return o << a.n << "/" << a.d;
  }
}

#endif /* EULER_HPP */
