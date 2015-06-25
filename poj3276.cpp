#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int n;
int isBack[5000];
int isChanged[5000];

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    char temp;
    cin >> temp;
    if(temp=='B'){
      isBack[i] = 1;
    }else{
      isBack[i] = 0;
    }
  }


  int ansK=1,ansM=n;
  for(int k=1;k<=n;k++){
    fill(isChanged,isChanged+n,0);
    bool isFound = true;
    int sum=0,res = 0;
    for(int i=0;i<n-k+1;i++){
      if((isBack[i]+sum)%2!=0){
        res++;
        isChanged[i] = 1;
      }
      sum+=isChanged[i];
      if(i-k+1>=0){
        sum -= isChanged[i-k+1];
      }
    }

    for(int i=n-k+1;i<n;i++){
      if((isBack[i]+sum)%2!=0){
        isFound = false;
        break;
      }
      if(i-k+1>=0){
        sum -= isChanged[i-k+1];
      }
    }
    //cout << "k:" << k << ",res:"<< res << endl;
    if(isFound && res<ansM){
      ansM = res;
      ansK = k;
    }
  }
  cout << ansM << " " << ansK << endl;
}