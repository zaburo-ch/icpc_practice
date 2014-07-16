#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 200
#define M 10000
#define R 1000
#define INF 1000000

int main(){
  while(1){
    int n,m,r;
    int sea[N][N];
    int land[N][N];
    int dp[R][N];
    int z[R];

    scanf("%d%d",&n,&m);
    if(!n&&!m)break;

    //陸路と海路を別々に全点対最短路を求める
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j){
          sea[i][j] = 0;
          land[i][j] = 0;
        }else{
          sea[i][j] = INF;
          land[i][j] = INF;
        }
      }
    }
    for(int i=0;i<m;i++){
      int x,y,t;
      char s;
      scanf("%d %d %d %c",&x,&y,&t,&s);
      if(s=='S'){
        sea[x-1][y-1] = t;
        sea[y-1][x-1] = t;
      }else{
        land[x-1][y-1] = t;
        land[y-1][x-1] = t;
      }
    }
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          sea[i][j] = min(sea[i][j],sea[i][k]+sea[k][j]);
          land[i][j] = min(land[i][j],land[i][k]+land[k][j]);
        }
      }
    }

    scanf("%d",&r);
    for(int i=0;i<r;i++){
      scanf("%d",&z[i]);
      z[i]--;
    }

    //dp[i][j]をjに船をおいてz[i]まで進んだ時にかかる最短の時間
    for(int i=0;i<n;i++){
      dp[0][i] = sea[z[0]][i] + land[i][z[0]];
      for(int j=1;j<r;j++){
        dp[j][i] = INF;
      }
    }
    for(int i=1;i<r;i++){
      for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
          dp[i][j] = min(
            dp[i][j],
            dp[i-1][k]+land[z[i-1]][k]+sea[k][j]+land[j][z[i]] );
          if(k==j) dp[i][j] = min(dp[i][j],dp[i-1][j]+land[z[i-1]][z[i]]);
        }
      }
    }

    int ans = INF;
    for(int i=0;i<n;i++){
      ans = min(ans,dp[r-1][i]);
    }
    cout << ans << endl;
  }
  return 0;
}