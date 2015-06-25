#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define N 24

char d[1<<N];
int x[N],y[N],r[N],c[N];
int n;
int over[N];

bool pailed(int a,int b){
  int d2 = (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
  int r2 = (r[a]+r[b])*(r[a]+r[b]);
  return d2 < r2;
}

int dfs(int i){
  if(d[i]!=-1) return d[i];
  d[i] = 0;
  for(int j=0;j<n-1;j++){
    //jがないorjの上に円盤がある
    if(!(i>>j&1)||over[j]&i) continue;
    for(int k=j+1;k<n;k++){
      //kがないorkの上に円盤があるor色が違う
      if(!(i>>k&1)||over[k]&i||c[k]!=c[j]) continue;
      d[i] = max( (int)d[i],2 + dfs((~(1<<j))&(~(1<<k))&i) );
    }
  }
  return d[i];
}

int main(){
  while(cin >> n,n){
    fill(over,over+n,0);

    for(int i=0;i<n;i++){
      scanf("%d%d%d%d",&x[i],&y[i],&r[i],&c[i]);
    }
    for(int i=n-1;i>=0;i--){
      for(int j=i-1;j>=0;j--){
        if(pailed(i,j)){
          over[i] |= 1<<j;
        }
      }
    }

    fill(d,d+(1<<n),-1);
    cout << (int)dfs((1<<n)-1) << endl;
  }
}