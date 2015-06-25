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

#define MAX_N 1000000
int dp[20][MAX_N+1];
int n;

int main(){
  scanf("%d",&n);

  int p=0;
  while(1<<p < n){
    p++;
  }

  for(int i=0;i<=n;i++){
    dp[0][i] = 1;
  }

  for(int i=1;i<p;i++){
    int pp = 1 << i;
    for(int j=0;j<=n;j++){
      dp[i][j] = 0;
      for(int k=0;k<=j/pp;k++){
        dp[i][j] += dp[i-1][j-k*pp];
      }
    }
  }
  cout << dp[p-1][n] << endl;

  return 0;
}