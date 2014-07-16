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

struct fence{
  int u,v;
  double cost;
};

//union-find木
#define N 10000
int par[N];
int urank[N];
void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    urank[i] = 0;
  }
}
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}
void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y)return;

  if(urank[x]<urank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(urank[x]==urank[y])urank[x]++;
  }
}
bool same(int x,int y){
  return find(x)==find(y);
}

//2点間の距離を求める
double distance(int x1,int y1,int x2,int y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

//fenceはcostの大きさで降順ソートしたいので不等号はこの向き
bool cmp(const fence &a,const fence &b){
  return a.cost > b.cost;
}

int main(){
  int n,m;
  P piles[N];
  vector<fence> fences;

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
    fences.push_back((fence){p,q,c});
  }

  double sum = 0;
  init(n);
  sort(fences.begin(),fences.end(),cmp);
  for(int i=0;i<m;i++){
    int u = fences[i].u;
    int v = fences[i].v;
    if(same(u,v)){
      sum += fences[i].cost;
    }else{
      unite(u,v);
    }
  }

  printf("%.3f\n",sum);


  return 0;
}