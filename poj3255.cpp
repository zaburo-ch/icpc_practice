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

struct edge {int to,cost;};
vector<edge> g[5000];
int n,r;
int d[5000];
int d2[5000];

int main(){
  cin >> n >> r;
  for(int i=0;i<r;i++){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    g[x-1].push_back((edge){y-1,z});
    g[y-1].push_back((edge){x-1,z});
  }

  fill(d,d+n,INF);
  fill(d2,d2+n,INF);

  priority_queue<P, vector<P> , greater<P> > que;
  que.push(P(0,0));
  while(que.size()){
    P p = que.top(); que.pop();
    int dist = p.first;
    int pos = p.second;
    if(d2[pos]<dist) continue;
    for(int i=0;i<g[pos].size();i++){
      int to = g[pos][i].to;
      int cost = g[pos][i].cost;
      int next = dist + cost;
      if(d[to]>next){
        swap(d[to],next);
        que.push(P(d[to],to));
      }
      if(d2[to] > next && d[to] < next){
        d2[to] = next;
        que.push(P(next,to));
      }
    }
  }
  printf("%d\n",d2[n-1]);
  return 0;
}