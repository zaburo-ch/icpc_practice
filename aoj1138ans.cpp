#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

double cost[30][256];
int n,m,p,a,b;
int t[8];
int map[30][30];

int main(){
  while(1){
    cin >> n >> m >> p >> a >> b;
    if(!n&&!m&&!p&&!a&&!b) break;
    for(int i=0;i<n;i++){
      scanf("%d",&t[i]);
    }
    a--;
    b--;
    memset(map,0,sizeof(map));
    for(int i=0;i<p;i++){
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      map[x-1][y-1] = z;
      map[y-1][x-1] = z;
    }

    for(int i=0;i<m;i++){
      for(int j=0;j<1<<n;j++){
        if(i==a){
          cost[a][j] = 0;
        }else{
          cost[i][j] = INF;
        }
      }
    }

    queue<P> que;
    que.push(P(a,(1<<n)-1));
    while(que.size()){
      P pa = que.front(); que.pop();
      int pos = pa.first;
      int ticket = pa.second;
      for(int i=0;i<m;i++){
        if(map[pos][i]!=0){
          for(int j=0;j<n;j++){
            if(ticket>>j&1){
              int next = ticket-(1<<j);
              if(cost[i][next]>cost[pos][ticket]+((double)map[pos][i]/t[j])){
                cost[i][next]=cost[pos][ticket]+((double)map[pos][i]/t[j]);
                que.push(P(i,next));
              }
            }
          }
        }
      }
    }

    double ans = INF;
    for(int i=0;i<1<<n;i++){
      if(ans>cost[b][i]){
        ans = cost[b][i];
      }
    }
    if(ans!=INF){
      printf("%lf\n",ans);
    }else{
      printf("Impossible\n");
    }

  }
  return 0;
}