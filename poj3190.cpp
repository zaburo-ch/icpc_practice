#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;



int main(){
  int n;
  P in[50000],out[50000];
  int ans[50000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    in[i] = P(a,i);
    out[i] = P(b,i);
  }

  sort(in,in+n);
  sort(out,out+n);

  queue<int> koya;
  int koyasum=0;
  int i=0,j=0;
  while(i<n){
    if(in[i].first<=out[j].first){
      if(koya.size()){
        ans[in[i].second] = koya.front(); koya.pop();
      }else{
        ans[in[i].second] = ++koyasum;
      }
      i++;
    }else{
      koya.push(ans[out[j].second]);
      j++;
    }
  }
  cout << koyasum << endl;
  for(int i=0;i<n;i++){
    cout << ans[i] << endl;
  }
}