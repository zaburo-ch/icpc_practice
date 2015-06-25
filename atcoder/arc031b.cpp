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

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

string s[10];
bool ans = false;

void dfs(int y,int x,int n){
  // s : 見た陸
  // n : 陸n(0or1)に隣接する海
  // b : 埋め立てるべきところ
  s[y][x] = 's';
  for(int i=0;i<4;i++){
    int nextx = x+dx[i], nexty = y+dy[i];
    if(nextx>=0&&nextx<10&&nexty>=0&&nexty<10){
      if(s[nexty][nextx]=='o'){
        dfs(nexty,nextx,n);
      }else{
        if(n==0){
          if(s[nexty][nextx]=='x'){
            s[nexty][nextx] = '0'+n;
          }
        }else{
          if(s[nexty][nextx]=='0'+n-1){
            s[nexty][nextx] = '0'+n;
          }
        }
      }
    }
  }
}

void printAll(){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      printf("%c",s[i][j]);
    }
    printf("\n");
  }
}

int main(){
  for(int i=0;i<10;i++){
    cin >> s[i];
  }

  int c = 0;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(s[i][j]=='o'){
        if(c==4){
          cout << "NO" << endl;
          return 0;
        }else{
          dfs(i,j,c);
          c++;
        }
      }
    }
  }

  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(s[i][j]=='0'+c-1){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}