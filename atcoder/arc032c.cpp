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

struct work{int start,end,id;};

P dp[1000001];
vector<work> works;

bool cmpWork(const work& left, const work& right ) {
    return left.start < right.start;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    works.push_back((work){a,b,i+1});
  }

  sort(works.begin(),works.end(),cmpWork);

  int i = works.size()-1;
  dp[1000000] = P(0,-1);

  for(int j=1000000-1;j>=0;j--){
    P p = dp[j+1];
    while(i>=0&&works[i].start==j){
      if(p.second==-1){
        p.first = 1;
        p.second = i;
      }else if( dp[works[i].end].first+1>p.first
                  || (dp[works[i].end].first+1==p.first&&works[p.second].id>works[i].id) ){
        //仕事iの終了時刻(works[i].end)後の最大数+1が大きければこれを使う
        p.first = dp[works[i].end].first+1;
        p.second = i;
      }
      i--;
    }
    dp[j] = p;
  }

  printf("%d\n",dp[0].first);
  i = dp[0].second;
  printf("%d",works[i].id);
  while(dp[works[i].end].second>i){
    i = dp[works[i].end].second;
    printf(" %d",works[i].id);
  }
  printf("\n");
  return 0;
}