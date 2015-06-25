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

const int dx[] = {-1,0,0,0,1};
const int dy[] = {0,-1,0,1,0};
int n,m;
int isFliped[15][15];
int tile[15][15];
int ans[15][15];

int check(int x,int y){
  int c = tile[x][y];
  for(int i=0;i<5;i++){
    int nextx = x + dx[i];
    int nexty = y + dy[i];
    if(nextx>=0&&nextx<m&&nexty>=0&&nexty<n){
      c += isFliped[nextx][nexty];
    }
  }
  return c%2;
}

int calc(){
  int res = 0;
  for(int i=1;i<m;i++){
    for(int j=0;j<n;j++){
      if(check(i-1,j)){
        res++;
        isFliped[i][j] = 1;
      }
    }
  }

  for(int i=0;i<n;i++){
    if(check(m-1,i)){
      return -1;
    }
    res += isFliped[0][i];
  }

  return res;
}

int main(){
  scanf("%d%d",&m,&n);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&tile[i][j]);
    }
  }

  int res = INF;
  for(int i=0;i<1<<n;i++){
    memset(isFliped,0,sizeof(isFliped));
    for(int j=0;j<n;j++){
      isFliped[0][n-j-1] = i >> j & 1;
    }
    int num = calc();
    if(num>0&&num<res){
      res = num;
      memcpy(ans,isFliped,sizeof(isFliped));
    }
  }

  if(res==INF){
    cout << "IMPOSSIBLE" << endl;
  }else{
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        printf("%d%c",ans[i][j],j+1==n ? '\n':' ');
      }
    }
  }
  return 0;
}