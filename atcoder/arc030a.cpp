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
  int n,k;
  scanf("%d%d",&n,&k);
  if(n>=2*k){
    printf("%s\n","YES");
  }else{
    printf("%s\n","NO");
  }
  return 0;
}