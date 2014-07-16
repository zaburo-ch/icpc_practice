#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
typedef pair<int,int> P;
typedef pair<double,int> Pdi;
#define N 10000
struct fence{
  int to;
  double cost;
};

//2点間の距離を求める
double distance(int x1,int y1,int x2,int y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
  int n,m;
  P piles[N];
  vector<fence> fences[N];
  double costsum = 0;

  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    piles[i] = P(x,y);
  }
  for(int i=0;i<m;i++){
    int p,q;
    scanf("%d%d",&p,&q);
    p--;q--;
    double c = distance(piles[p].first,piles[p].second,piles[q].first,piles[q].second);
    fences[p].push_back((fence){q,c});
    fences[q].push_back((fence){p,c});
    costsum += c;
  }

  double sum = 0;
  bool used[N];
  fill(used,used+n,false);

  priority_queue<Pdi> que;
  for(int i=0;i<n;i++){
    if(!used[i]){
      que.push(Pdi(0,i));
      while(que.size()){
        Pdi p = que.top(); que.pop();
        int pos = p.second;
        if(used[pos]) continue;
        used[pos] = true;
        sum += p.first;
        for(int j=0;j<fences[pos].size();j++){
          que.push(Pdi(fences[pos][j].cost,fences[pos][j].to));
        }
      }
    }
  }

  printf("%.3f\n",costsum-sum);


  return 0;
}