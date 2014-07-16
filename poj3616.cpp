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

typedef struct{
  int s,t,v;
} interval;

bool cmp(const interval& a,const interval& b){
  return a.t < b.t;
}

interval in[1001];
int n,m,r;
long long int dp[2000001];

int main(){

  scanf("%d%d%d",&n,&m,&r);
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&in[i].s,&in[i].t,&in[i].v);
    in[i].t+=r;
  }
  in[m].t = n+r+1;
  sort(in,in+m,cmp);

  memset(dp,0,sizeof(dp));
  for(int i=0;i<m;i++){
    dp[in[i].t] = max(dp[in[i].t],max(dp[in[i].t-1],dp[in[i].s]+in[i].v));
    for(int j=in[i].t+1;j<in[i+1].t;j++){
      dp[j] = dp[in[i].t];
    }
  }

  cout << dp[n+r] << endl;
  return 0;
}