#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

//union-find木
int const N = 100000;
int par[N];
int urank[N];
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
    int n,q;
    cin >> n >> q;
    init(n);
    for(int i=0;i<q;i++){
        int p,a,b;
        cin >> p >> a >> b;
        if(p){
            if(same(a,b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            unite(a,b);
        }
    }


    return 0;
}

