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

const int MAX_N = 100000;

vector<int> edges[MAX_N];
int dfs(int now,int post){
  int num = 1;
  for(int i=0;i<edges[now].size();i++){
    if(edges[now][i]==post)continue;
    num += dfs(edges[now][i],now);
  }
  return num;
}

int main(){
  int N;
  scanf("%d",&N);

  for(int i=1;i<N;i++){
    int p;
    scanf("%d",&p);
    edges[p].push_back(i);
    edges[i].push_back(p);
  }

  for(int i=0;i<N;i++){
    int ans = 0;
    for(int j=0;j<edges[i].size();j++){
      ans = max(ans,dfs(edges[i][j],i));
    }
    printf("%d\n",ans);
  }
  return 0;
}