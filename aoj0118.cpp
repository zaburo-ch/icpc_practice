#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int H,W;
char map[100][100];

void grouping(int h,int w,char f);

int main(){
  while(1){
    cin >> H >> W;
    if(H==0&&W==0)break;

    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        cin >> map[i][j];
      }
    }
    int x=0;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(map[i][j]!='.'){
          x++;
          grouping(i,j,map[i][j]);
        }
      }
    }
    cout << x << endl;
  }
}

void grouping(int h,int w,char f){
  map[h][w] = '.';
  if(h-1>=0&&map[h-1][w]==f){
    grouping(h-1,w,f);
  }
  if(h+1<H&&map[h+1][w]==f){
    grouping(h+1,w,f);
  }
  if(w-1>=0&&map[h][w-1]==f){
    grouping(h,w-1,f);
  }
  if(w+1<W&&map[h][w+1]==f){
    grouping(h,w+1,f);
  }
}