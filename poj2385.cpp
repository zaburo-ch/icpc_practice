#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int t,w;
int a[1000];

int dp[1000][31][2];

int main(){
  scanf("%d%d",&t,&w);
  for(int i=0;i<t;i++){
    scanf("%d",&a[i]);
  }

  memset(dp,0,sizeof(dp));
  //t=0
  for(int i=0;i<=w;i++){
    dp[0][i][a[i]-1]++;
  }

  for(int i=1;i<t;i++){
    for(int j=0;j<=w;j++){
      if(j==0){
        dp[i][0][0] = dp[i-1][0][0];
        dp[i][0][1] = dp[i-1][0][1];
      }else{
        dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j-1][1]);
        dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0]);
      }
      dp[i][j][a[i]-1]++;
    }
  }

  cout << max(dp[t-1][w][0],dp[t-1][w][1]) << endl;
  return 0;
}