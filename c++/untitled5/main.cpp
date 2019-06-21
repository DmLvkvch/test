#include <assert.h>
#include <iostream>
#include <assert.h>
#include <algorithm> // std::copy
#include <cstddef> // size_t
using namespace std;

#include <string.h>
using namespace std;
class RGBToHex
{
    string s;
  public:
  void hex(int r  ){
      int y = r;
      while(r){
      int x = r%16;
      r/=16;
      if(x>0 && x<10){
        s+="0"+to_string(x);
      }
      else if(x == 10)
      s+="A";
      else if(x == 11)
      s+="B";
      else if(x == 12)
      s+="C";
      else if(x == 13)
      s+="D";
      else if(x == 14)
      s+="E";
      else if(x == 15)
      s+="F";
      else if(r%16 == 0)
          s+=to_string(y/16)+"0";
  }
  }
  string rgb(int r, int g, int b){

  hex(r);
  hex(g);
  hex(b);
  return s;
  }
};

int main()
{
    RGBToHex a;
    cout<<a.rgb(148,0,211);
    cout << endl;

    return 0;
}
