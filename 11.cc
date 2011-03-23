#include <iostream>
#include <vector>
#include <cassert>


using namespace std;


int main(int argc, char *argv[])
{
  vector<vector<int> > grid;

  for(int i = 0;i < 20; i++){
    vector<int> v;
    for(int j = 0; j < 20; j++){
      int k;
      cin >> k;
      v.push_back(k);
    }
    grid.push_back(v);
    assert(v.size() == 20);
  }
  assert(grid.size() == 20);

  int res = 0;
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      int hor=1,ver=1,dia=1,dia2=1;
      for(int k = 0; k < 4; k++){
        if(j + k >= 20){
          hor = 0; break;
        }
        hor *= grid[i][j+k];
      }
      for(int k = 0; k < 4; k++){
        if(i + k >= 20){
          ver = 0; break;
        }
        ver *= grid[i+k][j];
      }
      for(int k = 0; k < 4; k++){
        if(j +k >= 20 || i +k >= 20){
          dia = 0; break;
        }
        dia *= grid[i+k][j+k];
      }
      for(int k = 0; k < 4; k++){
        if(j - k < 0 || i +k >= 20){
          dia = 0; break;
        }
        dia2 *= grid[i+k][j-k];
      }
      res = max(res,max(hor,max(ver,max(dia,dia2)))); 
    }
  }

  cout << res << endl;

  return 0;
}
