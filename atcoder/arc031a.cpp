#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;

int main(){
  string s;
  cin >> s;

  int l = s.size();
  for(int i=0;i<l/2;i++){
    if(s[i]!=s[l-i-1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}