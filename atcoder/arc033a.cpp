#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;

int main(){
  int n;
  cin >> n;
  int r = 0;
  for(int i=0;i<n;i++){
    r+=n-i;
  }
  cout << r << endl;
}