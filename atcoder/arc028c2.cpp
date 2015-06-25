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

const int MAX_N = 100000;
int dp[MAX_N];
vector<int> edges[MAX_N];

int dfs(int n){
  if(dp[n]>0) return dp[n];
  int num = 1;
  for(int i=0;i<edges[n].size();i++){
    if(n<edges[n][i]){
      num += dfs(edges[n][i]);
    }
  }
  return dp[n] = num;
}

int main(){
  int N;
  scanf("%d",&N);

  for(int i=1;i<N;i++){
    int p;
    scanf("%d",&p);
    edges[p].push_back(i);
    edges[i].push_back(p);
  }

  dfs(0);
  for(int i=0;i<N;i++){
    int ans = 0;
    for(int j=0;j<edges[i].size();j++){
      if(i<edges[i][j]){
        ans = max(ans,dp[edges[i][j]]);
      }else{
        ans = max(ans,N-dp[i]);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}