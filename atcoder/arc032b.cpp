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

//union-find木
#define N 100000
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

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  init(n);

  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    unite(a-1,b-1);
  }

  int ans = 0;
  for(int i=0;i<n;i++){
    if(par[i]==i) ans++;
  }

  printf("%d\n",ans-1);
  return 0;
}