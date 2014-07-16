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

int n;
vector<int> rows[350];
int dp[350][350];

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++){
      int temp;
      scanf("%d",&temp);
      rows[i].push_back(temp);
    }
  }

  for(int j=0;j<n;j++){
    dp[n-1][j] = rows[n-1][j];
  }
  for(int i=n-2;i>=0;i--){
    for(int j=0;j<i+1;j++){
      dp[i][j] = rows[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}