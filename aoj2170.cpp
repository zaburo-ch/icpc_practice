#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;


struct node{
  bool marked;
  int parent;
  int num;
};

int main(){
  while(1){
    vector<node> T;
    int n,q;
    scanf("%d%d",&n,&q);
    if(n==0&&q==0){
      return 0;
    }

    T.push_back((node){true,0,1});
    for(int i=2;i<=n;i++){
      int parent;
      cin >> parent;
      T.push_back((node){false,parent-1,i});
    }

    int sum = 0;
    for(int i=0;i<q;i++){
      char q;
      int v;
      cin >> q >> v;
      if(q=='M'){
        T[v-1].marked = true;
      }else{
        node n = T[v-1];
        while(!n.marked){
          n = T[n.parent];
        }
        sum += n.num;
      }
    }
    cout << sum << endl;

  }
}