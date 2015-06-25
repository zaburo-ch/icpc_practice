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

void add(int k,int v){
  k += n-1;
  dat[k]+=v;
  while(k>0){
    k = (k-1)/2;
    dat[k]+=v;
  }
}

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

int main(){
  int q;
  scanf("%d",&q);
  init();
  for(int i=0;i<q;i++){
    int t,x;
    scanf("%d%d",&t,&x);
    if(t==1){
      add(x-1,1);
    }else{
      int l = 0, r = MAX_X;
      while(l<r){
        int mid = (l+r)/2;
        int s = sum(0,mid,0,0,n);
        if(s>=x){
          r = mid;
        }else{
          l = mid+1;
        }
      }
      printf("%d\n",l);
      add(l-1,-1);
    }
  }
}