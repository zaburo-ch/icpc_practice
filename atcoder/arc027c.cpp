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
typedef pair<int,long long int> Topping;

Topping T[300];
long long int dp[300][301][301];
int X,Y,N;

long long int memodfs(int n,int x,int y){
  //cout << n << " " << x << " " << y << endl;
  if(n==N||x==0) return 0;
  if(dp[n][x][y]>=0) return dp[n][x][y];
  long long int toru=0,toranai;
  toranai = memodfs(n+1,x,y);
  if(x+y>=T[n].first){
    if(y>=T[n].first-1){
      toru = T[n].second + memodfs(n+1,x-1,y-T[n].first+1);
    }else{
      toru = T[n].second + memodfs(n+1,x-T[n].first+y,0);
    }
  }
  if(toru<toranai){
    return dp[n][x][y] = toranai;
  }else{
    return dp[n][x][y] = toru;
  }
}

int main(){
  scanf("%d%d%d",&X,&Y,&N);
  for(int i=0;i<N;i++){
    int t;
    long long int h;
    scanf("%d%lld",&t,&h);
    T[i] = Topping(t,h);
  }

  for(int i=0;i<N;i++)
    for(int j=0;j<=X;j++)
      for(int k=0;k<=Y;k++)
        dp[i][j][k] = -1;

  long long int ans = memodfs(0,X,Y);
  printf("%lld\n",ans);
  return 0;
}