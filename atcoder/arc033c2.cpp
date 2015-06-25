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

const int MAX_N = 1<<18;
const int MAX_X = 200000;

int n,dat[2*MAX_N-1];

void init(){
  n = MAX_N;
  for(int i=0;i<MAX_N;i++) dat[i] = 0;
}

void add(int k){
  k += n-1;
  dat[k]++;
  while(k>0){
    k = (k-1)/2;
    dat[k]++;
  }
}

void remove(int k){
  k += n-1;
  dat[k]--;
  while(k>0){
    k = (k-1)/2;
    dat[k]--;
  }
}

/*
int sum(int a, int b, int k, int l, int r){
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b){
    return dat[k];
  }else{
    int vl = sum(a,b,k*2+1,l,(l+r)/2);
    int vr = sum(a,b,k*2+2,(l+r)/2,r);
    return vl+vr;
  }
}
*/

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
  int q;
  scanf("%d",&q);
  init();
  for(int i=0;i<q;i++){
    int t,x;
    scanf("%d%d",&t,&x);
    if(t==1){
      add(x-1);
    }else{
      int y = find(x);
      printf("%d\n",y);
      remove(y-1);
    }
  }
}