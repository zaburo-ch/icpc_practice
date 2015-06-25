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
long long int dp[MAX_N][MAX_N]; //s,t;


long long int memodfs(int now,int to){
  if(now==to) return 1;
  if(dp[now][to]>=0) return dp[now][to];
  long long int c = 0;
  for(int i=1;i<=h[now];i++){
    if(now+i<=to){
      c += memodfs(now+i,to);
      c %= m;
    }
  }
  return dp[now][to] = c;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&h[i]);
  }
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      dp[i][j] = -1;

  scanf("%d",&D);
  for(int i=0;i<D;i++){
    int s,t;
    scanf("%d%d",&s,&t);
    printf("%lld\n",memodfs(s-1,t-1));
  }
  return 0;
}