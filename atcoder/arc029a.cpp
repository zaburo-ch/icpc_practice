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

int t[4];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&t[i]);
  }

  if(N==1){
    printf("%d\n",t[0]);
  }else if(N==2){
    printf("%d\n",max(t[0],t[1]));
  }else if(N==3){
    int ans;
    ans = max(t[0],t[1]+t[2]);
    ans = min(ans,max(t[1],t[2]+t[0]));
    ans = min(ans,max(t[2],t[1]+t[0]));
    printf("%d\n",ans);
  }else{
    int ans;
    ans = max(t[0],t[1]+t[2]+t[3]);
    ans = min(ans,max(t[1],t[2]+t[3]+t[0]));
    ans = min(ans,max(t[2],t[3]+t[0]+t[1]));
    ans = min(ans,max(t[3],t[0]+t[1]+t[2]));

    ans = min(ans,max(t[0]+t[1],t[2]+t[3]));
    ans = min(ans,max(t[1]+t[2],t[3]+t[0]));
    ans = min(ans,max(t[2]+t[3],t[0]+t[1]));
    ans = min(ans,max(t[3]+t[0],t[1]+t[2]));
    ans = min(ans,max(t[0]+t[2],t[1]+t[3]));
    ans = min(ans,max(t[1]+t[3],t[0]+t[2]));

    printf("%d\n",ans);
  }

  return 0;
}