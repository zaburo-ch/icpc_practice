#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int i = 1;
  int noti = ~(1<<10);
  int not2 = ~(1<<5);
  cout << i << endl;
  for(int j=31;j>=0;j--){
    cout << (i>>j&1);
  }
  cout << endl;

  cout << noti << "&" << not2 << endl;
  for(int j=31;j>=0;j--){
    cout << ((noti&not2)>>j&1);
  }
  cout << endl;
}