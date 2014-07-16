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

struct cmp{
  bool operator()(const P &a,const P &b){
    return a.second > b.second;
  }
};

int c,l;
vector<P> cows;
vector<int> spf;
priority_queue<P,vector<P>,cmp> que;


int main(){
  scanf("%d%d",&c,&l);
  for(int i=0;i<c;i++){
    int mi,ma;
    scanf("%d%d",&mi,&ma);
    cows.push_back(P(mi,ma));
  }
  for(int i=0;i<l;i++){
    int sp,co;
    scanf("%d%d",&sp,&co);
    for(int j=0;j<co;j++){
      spf.push_back(sp);
    }
  }

  sort(cows.begin(),cows.end());
  sort(spf.begin(),spf.end());

  int j=0,sum=0;
  for(int i=0;i<spf.size();i++){
    for(;j<c;j++){
      if(cows[j].first<=spf[i]){
        que.push(cows[j]);
      }else{
        break;
      }
    }
    while(que.size()){
      P p = que.top(); que.pop();
      if(spf[i]<=p.second){
        sum++;
        break;
      }
    }
  }
  cout << sum << endl;
}