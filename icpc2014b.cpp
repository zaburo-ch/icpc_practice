#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef pair<int,int> P;
#define H 10

int paz[H][5];
int h;
int ans;

void del();

void down(){
  for(int j=0;j<5;j++){
    for(int i=h-1;i>=0;i--){
      if(paz[i][j]!=0) continue;
      for(int k=i;k>0;k--){
        if(paz[k][j]==-1) break;
        paz[k][j] = paz[k-1][j];
      }
      paz[0][j] = -1;
      i++;
    }
  }
  del();
}

void mout(){
  for(int i=0;i<h;i++){
    for(int j=0;j<5;j++){
      printf("%2d",paz[i][j]);
    }
    cout << endl;
  }
  cout << endl;
}

void del(){
  int before = ans;
  for(int i=0;i<h;i++){
    int start = 0;
    int target = 0;
    int sum = 0;
    for(int j=0;j<5;j++){
      if(paz[i][j]!=target){
        if(sum<3){
          target = paz[i][j];
          sum = 1;
          start = j;
        }else{
          break;
        }
      }else{
        sum++;
      }
    }
    if(sum<3||target==-1)continue;
    for(int j=0;j<sum;j++){
      paz[i][start+j] = 0;
    }
    ans += target*sum;
  }
  if(before!=ans){
    down();
  }
}


int main(){
  while(cin >> h,h){

    for(int i=0;i<h;i++){
      for(int j=0;j<5;j++){
        scanf("%d",&paz[i][j]);
      }
    }
    ans = 0;
    del();
    cout << ans << endl;
  }

  return 0;
}