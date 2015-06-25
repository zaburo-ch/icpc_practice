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
  int Na,Nb;
  set<int> s;
  cin >> Na >> Nb;
  for(int i=0;i<Na+Nb;i++){
    int temp;
    cin >> temp;
    s.insert(temp);
  }

  printf("%.7f\n",(double)(Na+Nb-s.size())/s.size());
}