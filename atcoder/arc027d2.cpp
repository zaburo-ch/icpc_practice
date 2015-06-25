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

const int MAX_N = 500;
const long long int m = 1000000007;

int N,D;
int h[MAX_N];
long long int dp[MAX_N]; //s,t;

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&h[i]);
  }
  /*
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      dp[i][j] = -1;
  */
  //dp[i] : iへの行き方の数　自分から自分を含む
  dp[0] = 1;
  for(int i=1;i<N;i++){
    dp[i] = 1;
    for(int j=1;j<=10&&i-j>=0;j++){
      if(h[i-j]>=j){
        //i-jからjに直接移動できる
        dp[i] += dp[i-j];
        dp[i] %= m;
      }
    }
  }
  for(int i=0;i<N;i++) cout << dp[i] << endl;

  scanf("%d",&D);
  for(int i=0;i<D;i++){
    int s,t;
    scanf("%d%d",&s,&t);
    long long int ans = dp[t-1]
    printf("%lld\n",dp[t-1]/dp[s-1]);
  }
  return 0;
}