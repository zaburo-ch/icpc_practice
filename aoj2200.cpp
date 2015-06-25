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
//way:S->0,L->1;
struct road{int to,cost;};
struct situ{
  int dist,pos,boat;
  situ(int a,int b,int c){
    dist = a;pos = b;boat = c;
  }
};
bool operator < (const situ &a,const situ &b){
  return a.dist > b.dist;
}

int main(){
  int n,m,r;
  vector<road> sea[N];
  vector<road> land[N];
  int z[R];
  int d[N];

  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    int x,y,t;
    char s;
    scanf("%d %d %d %c",&x,&y,&t,&s);
    if(s=='S'){
      sea[x-1].push_back((road){y-1,t});
      sea[y-1].push_back((road){x-1,t});
    }else{
      land[x-1].push_back((road){y-1,t});
      land[y-1].push_back((road){x-1,t});
    }
  }
  scanf("%d",&r);
  for(int i=0;i<n;i++){
    scanf("%d",&z[i]);
  }

  fill(d,d+n,INF);
  priority_queue<situ> que;
  que.push(situ(0,z[0],z[0]);
  d[z[0]] = 0;
  while(que.size()){
    situ q = que.top(); q.pop();
    int pos = q.pos;

    if(d[pos]<q.dist) break;
    for(int i=0;i<land[pos].size();i++){
      int to = land[pos][i].to;
      int co = d[pos] + land[pos][i].cost;
      if(d[to]>co){
        d[to] = co;
        que.push(situ(d[to],to,))
      }
    }
  }

  return 0;
}