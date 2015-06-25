#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

typedef struct{
  int first;
  int second;
}cow;

bool cmp(const cow &a, const cow &b)
{
  if (a.first == b.first)
  {
    return a.second > b.second;
  }
  return a.first < b.first;
}

int n,t;
cow cows[25000];

int main(){
  scanf("%d%d",&n,&t);
  for(int i=0;i<n;i++){
    scanf("%d%d",&cows[i].first,&cows[i].second);
  }
  sort(cows,cows+n,cmp);

  int sum = 0;
  int start=1;
  cow maxd;
  int rFlag = 0;
  for(int i=0;i<n;i++){
    if(cows[i].first<=start){
      rFlag = 1;
      if(cows[i].second>=t){
        cout << sum+1 << endl;
        return 0;
      }
    }else{
      if(rFlag){
        start = cows[i-1].second;
        sum++;
        i--;
      }else{
        cout << -1 << endl;
        return 0;
      }
    }
  }
}