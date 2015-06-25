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

const int MAX_N = 1<<17;
const int MAX_X = 100000;

int n,dat[2*MAX_N-1];
int oldToRank[MAX_X];

void init(int n_){
  n = 1;
  while(n < n_) n*=2;
  for(int i=0;i<2*n-1;i++) dat[i] = 0;
}

void add(int k,int v){
  k += n-1;
  dat[k]+=v;
  while(k>0){
    k = (k-1)/2;
    dat[k]+=v;
  }
}

int find(int x){
  int y = 0;
  int i=18;
  while(y-(n-1)<0){
    if(dat[2*y+1]>=x){
      y = 2*y+1;
    }else{
      x-=dat[2*y+1];
      y = 2*y+2;
    }
    i--;
  }
  return y-(n-1)+1;
}

int main(){
  int N,K;
  scanf("%d%d",&N,&K);

  init(N);
  for(int i=0;i<N;i++){
    int temp;
    scanf("%d",&temp);
    add(temp-1,1);
    oldToRank[temp-1] = i+1;
    if(i>=K-1) printf("%d\n",oldToRank[find(K)-1]);
  }
  return 0;
}