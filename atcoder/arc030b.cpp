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

bool path[100][100];
bool h[100];
int n,x;
int cost;

bool dfs(int now,int post){
  bool needHere = h[now];
  for(int i=0;i<n;i++){
    if(i!=post&&path[now][i]){
      bool needGo = dfs(i,now);
      if(needGo){
        cost+=2;
      }
      needHere = needHere||needGo;
    }
  }
  return needHere;
}

int main(){
  for(int i=0;i<100;i++)for(int j=0;j<100;j++) path[i][j]=false;
  scanf("%d%d",&n,&x);
  for(int i=0;i<n;i++){
    int temp;
    scanf("%d",&temp);
    h[i] = temp==1;
  }
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    path[a-1][b-1] = true;
    path[b-1][a-1] = true;
  }
  cost = 0;
  dfs(x-1,x-1);
  printf("%d\n",cost);
  return 0;
}