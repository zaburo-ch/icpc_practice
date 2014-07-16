#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_N 10000
#define INF 1000000
struct road{int to,dist,cost;};
typedef pair<int,int> P;

int main(){
  while(1){
    int n,m;
    vector<road> roads[MAX_N];
    int dist[MAX_N];
    road pre[MAX_N];

    scanf("%d%d",&n,&m);
    if(!n&&!m)break;

    for(int i=0;i<m;i++){
      int u,v,d,c;
      scanf("%d%d%d%d",&u,&v,&d,&c);
      roads[u-1].push_back((road){v-1,d,c});
      roads[v-1].push_back((road){u-1,d,c});
    }

    fill(dist,dist+n,INF);
    priority_queue<P, vector<P>, greater<P> > que;
    dist[0] = 0;
    que.push(P(0,0));
    while(que.size()){
      P p = que.top(); que.pop();
      int d = p.first;
      int pos = p.second;
      //cout << pos+1 << endl;
      if(d>dist[pos]) continue;
      for(int i=0;i<roads[pos].size();i++){
        int to = roads[pos][i].to;
        int co = roads[pos][i].dist + dist[pos];
        //cout << pos+1 <<"->" << to+1<< endl;
        if(dist[to]>co){
          pre[to] = roads[pos][i];
          dist[to] = co;
          que.push(P(dist[to],to));
        }else if(dist[to]==co){
          if(pre[to].cost>roads[pos][i].cost){
            pre[to] = roads[pos][i];
          }
        }
      }
    }

    int sum=0;
    for(int i=1;i<n;i++){
      sum += pre[n-i].cost;
    }
    cout << sum << endl;
  }
}