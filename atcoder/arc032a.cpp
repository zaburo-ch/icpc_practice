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
  int n;
  scanf("%d",&n);
  if(n==1){
    printf("BOWWOW\n");
    return 0;
  }

  n = n*(n+1)/2;
  int i=2;
  while(i*i<=n){
    if(n%i==0){
      printf("BOWWOW\n");
      return 0;
    }
    i++;
  }
  printf("WANWAN\n");
  return 0;
}