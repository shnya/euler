/* g++ -ftemplate-depth-10000 -DTARGET=600851475143 */

typedef unsigned long size_t;

template<int n>
struct Answer_Is_ {};

template<size_t n, size_t i, size_t div, size_t answer>
struct _MaxPrime {
  typedef typename _MaxPrime<n,i+1,n%(i+1),answer>::type type;
};

template<size_t n, size_t i, size_t answer>
struct _MaxPrime<n,i,0,answer> {
  typedef typename _MaxPrime<n/i,i,(n/i)%i,n>::type type;
};

template<size_t i, size_t answer>
struct _MaxPrime<1,i,1,answer> {
  typedef Answer_Is_<answer> type;
};

template<size_t n>
struct MaxPrime{
  typedef typename _MaxPrime<n,1,1,false>::type type;
};

int main(int argc, char *argv[])
{
  MaxPrime<TARGET>::type a = 0;
  return 0;
}
