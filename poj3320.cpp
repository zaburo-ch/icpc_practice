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

int p;
int a[1000000];

int main(){
  scanf("%d",&p);
  for(int i=0;i<p;i++){
    scanf("%d",&a[i]);
  }

  set<int> all;
  for(int i=0;i<p;i++){
    all.insert(a[i]);
  }
  int n = all.size();

  map<int,int> count;
  int res = p;
  int t=0,s=0;
  int sum=0;
  while(1){
    while(t<p && sum<n){
      if(count[a[t++]]++==0){
        sum++;
      }
    }
    if(sum<n)break;
    res = min(res,t-s);
    if(--count[a[s++]]==0){
      sum--;
    }
  }
  cout << res << endl;
}