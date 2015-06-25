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

int bit[1<<17],n;

void init(int n_){
  n = 1;
  while(n < n_) n*=2;
  for(int i=1;i<=n;i++) bit[i] = 0;
}

int sum(int i){
  int s = 0;
  while(i>0){
    s += bit[i];
    i -= i&-i;
  }
  return s;
}

void add(int i,int x){
  while(i<=n){
    bit[i] += x;
    i += i&-i;
  }
}

int main(){
  int N;
  scanf("%d",&N);

  init(N);
  long long int ans = 0;
  for(int i=0;i<N;i++){
    int b;
    scanf("%d",&b);
    int l = sum(N)-sum(b);
    int r = N-b-l;
    ans += min(l,r);
    add(b,1);
  }

  printf("%lld\n",ans);
  return 0;
}