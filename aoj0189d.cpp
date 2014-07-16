#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int,int> P;

#define INF 1000000
struct road{int to,cost;};

int main(){
  while(1){
    vector<road> roads[10];
    int d[10];
    int n,m;

    cin >> n;
    if(!n)break;
    m = 0;
    for(int i=0;i<n;i++){
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if(m<x||m<y){
        m = max(x,y);
      }
      roads[x].push_back((road){y,z});
      roads[y].push_back((road){x,z});
    }
    m++;

    int minIndex;
    int mini = INF;
    for(int i=0;i<m;i++){
      priority_queue<P, vector<P>, greater<P> > que;
      que.push(P(0,i));
      fill(d,d+m,INF);
      d[i] = 0;
      while(que.size()){
        P p = que.top(); que.pop();
        int dist = p.first;
        int pos = p.second;
        if(d[pos]<dist) continue;
        for(int j=0;j<roads[pos].size();j++){
          int to = roads[pos][j].to;
          int cost = roads[pos][j].cost;
          if(d[to]>d[pos]+cost){
            d[to] = d[pos] + cost;
            que.push(P(d[to],to));
          }
        }
      }
      int sum = 0;
      for(int j=0;j<m;j++){
        //printf("%3d%c",d[j],j==m-1?'\n':' ');
        sum += d[j];
      }
      if(mini>sum){
        mini = sum;
        minIndex = i;
      }
    }
    cout << minIndex << " " << mini << endl;
  }
}