#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int sumRow(int n);
int sumCol(int n);
int check();
void changeRow(int n);
void changeCol(int n);

int senbei[10][10000];
int r,c;

int main(){
  while(1){
    cin >> r >> c;
    if(r==0&&c==0) return 0;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin >> senbei[i][j];
      }
    }

    int before = -1;
    while(1){
      int max = 0;
      int isR = 1;
      int pos = -1;
      for(int i=0;i<r;i++){
        int temp=sumRow(i);
        if(temp>max && 2*temp>=c && i!=before){
          max = temp;
          pos = i;
        }
      }
      for(int i=0;i<c;i++){
        int temp=sumCol(i);
        if(temp>max && 2*temp>=r && i!=before){
          max = temp;
          pos = i;
          isR = 0;
        }
      }
      if(pos>=0){
        if(isR){
          changeRow(pos);
        }else{
          changeCol(pos);
        }
        before=pos;
      }else{
        break;
      }
    }
    cout << check() << endl;
  }
}

int sumRow(int n){
  int sum=0;
  for(int i=0;i<c;i++) sum+=senbei[n][i];
  return sum;
}

int sumCol(int n){
  int sum=0;
  for(int i=0;i<r;i++) sum+=senbei[i][n];
  return sum;
}

int check(){
  int sum = 0;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(!senbei[i][j]){
        sum++;
      }
    }
  }
  return sum;
}

//横ひっくり返し
void changeRow(int n){
  for(int i=0;i<c;i++){
    senbei[n][i] = !senbei[n][i];
  }
}

//縦
void changeCol(int n){
  for(int i=0;i<r;i++){
    senbei[i][n] = !senbei[i][n];
  }
}