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
  int q;
  set<int> s;
  cin >> q;
  for(int i=0;i<q;i++){
    int t,x;
    scanf("%d %d",&t,&x);
    if(t==1){
      s.insert(x);
    }else{
      set<int>::iterator it = s.begin();
      advance(it,x-1);
      printf("%d\n",*it);
      s.erase(it);
    }
  }
}