#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int senbei[10][10000];
int r,c;
int rowFlag[10];
int Max;

int countSum(){
  int sum=0;
  for(int i=0;i<c;i++){
    int colSum = 0;
    for(int j=0;j<r;j++){
      if(senbei[j][i]==!rowFlag[j]){
        colSum++;
      }
    }
    sum += max(colSum,r-colSum);
  }
  return sum;
}

int main(){
  while(1){
    cin >> r >> c;
    if(r==0&&c==0) return 0;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin >> senbei[i][j];
      }
    }
    Max = 0;
    for(int i=0;i<1<<r;i++){
      for(int j=0;j<r;j++){
        rowFlag[j] = i >> j & 1;
      }
      int sum = countSum();
      if(Max<sum){
        Max = sum;
      }
    }
    cout << Max << endl;
  }
}