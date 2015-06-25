#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int n,m,sx,sy,gx,gy;
char map[100][100];
int d[100][100];

int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> map[i][j];
      d[i][j] = INF;
      if(map[i][j]=='S'){
        sx = i; sy = j;
      }else if(map[i][j]=='G'){
        gx = i; gy = j;
      }
    }
  }

  queue<P> que;
  que.push(P(sx,sy));
  d[sx][sy] = 0;

  while(que.size()){
    P p = que.front(); que.pop();
    int x = p.first, y = p.second;

    if(x==gx&&y==gy)break;

    if(x-1>=0 && map[x-1][y]!='#' && d[x-1][y]==INF){
      d[x-1][y] = d[x][y] + 1;
      que.push(P(x-1,y));
    }
    if(x+1<n && map[x+1][y]!='#' && d[x+1][y]==INF){
      d[x+1][y] = d[x][y] + 1;
      que.push(P(x+1,y));
    }
    if(y-1>=0 && map[x][y-1]!='#' && d[x][y-1]==INF){
      d[x][y-1] = d[x][y] + 1;
      que.push(P(x,y-1));
    }
    if(y+1<m && map[x][y+1]!='#' && d[x][y+1]==INF){
      d[x][y+1] = d[x][y] + 1;
      que.push(P(x,y+1));
    }
  }

  cout << d[gx][gy] << endl;
}