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

const int ALPH = 26;
const int PREFIX = 26;

bool used[ALPH];
bool isnum[ALPH];

int par[ALPH+1];
int urank[ALPH+1];
void init(int n){
  for(int i=0;i<n;i++){
    par[i] = i;
    urank[i] = 0;
  }
}
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}
void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y)return;

  if(urank[x]<urank[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(urank[x]==urank[y])urank[x]++;
  }
}
bool same(int x,int y){
  return find(x)==find(y);
}


int main(){
  int N;
  scanf("%d",&N);

  init(ALPH+1);
  fill(used,used+ALPH,false);
  fill(isnum,isnum+ALPH,false);

  string s1,s2;
  cin >> s1 >> s2;

  if('A'<=s1[0]&&s1[0]<='Z') unite(PREFIX,s1[0]-'A');
  if('A'<=s2[0]&&s2[0]<='Z') unite(PREFIX,s2[0]-'A');

  for(int i=0;i<N;i++){
    if('0'<=s1[i]&&s1[i]<='9'){
      if('A'<=s2[i]&&s2[i]<='Z'){
        used[s2[i]-'A'] = true;
        isnum[s2[i]-'A'] = true;
      }
    }else{
      used[s1[i]-'A'] = true;
      if('0'<=s2[i]&&s2[i]<='9'){
        isnum[s1[i]-'A'] = true;
      }else{
        used[s2[i]-'A'] = true;
        unite(s1[i]-'A',s2[i]-'A');
      }
    }
  }

  bool counted[ALPH];
  fill(counted,counted+ALPH,false);
  long long int ans = 1;
  for(int i=0;i<ALPH;i++){
    if(used[i]&&!counted[find(i)]){
      counted[par[i]] = true;
      bool isOne = false;
      for(int j=0;j<ALPH;j++){
        if(used[j]&&isnum[j]&&same(i,j)){
          isOne = true;
          break;
        }
      }
      if(!isOne){
        if(same(PREFIX,i)) ans *= 9;
        else ans *= 10;
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}