#include <iostream>
#include <vector>
using namespace std;

int n,m;
char map[100][100];

void solve();
void grouping(int y,int x);
int main(){

  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> map[i][j];
    }
  }

  solve();
}

void solve(){
  int x = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]=='W'){
        x++;
        grouping(i,j);
      }
    }
  }
  cout << x << endl;
}

void grouping(int y,int x){
  map[y][x] = '.';
  for(int dy=-1;dy<=1;dy++){
    for(int dx=-1;dx<=1;dx++){
      if( y+dy>=0 && y+dy<n && x+dx>=0 && x+dx<m && map[y+dy][x+dx]=='W'){
        grouping(y+dy,x+dx);
      }
    }
  }
}

/*
void grouping(int y,int x){
  map[y][x] = '.';
  if(x-1>=0){
    if(y-1>=0&&map[y-1][x-1]=='W'){
      grouping(y-1,x-1);
    }
    if(y+1<n&&map[y+1][x-1]=='W'){
      grouping(y+1,x-1);
    }
    if(map[y][x-1]=='W'){
      grouping(y,x-1);
    }
  }
  if(x+1<m){
    if(y-1>=0&&map[y-1][x+1]=='W'){
      grouping(y-1,x+1);
    }
    if(y+1<n&&map[y+1][x+1]=='W'){
      grouping(y+1,x+1);
    }
    if(map[y][x+1]=='W'){
      grouping(y,x+1);
    }
  }
  if(y-1>=0&&map[y-1][x]=='W'){
      grouping(y-1,x);
  }
  if(y+1<n&&map[y+1][x]=='W'){
    grouping(y+1,x);
  }
}
*/