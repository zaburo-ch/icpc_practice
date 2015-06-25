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
  struct node *parent;
  int num;
};

vector<node> T;
int main(){
  //while(1){
    int n,q;
    scanf("%d%d",&n,&q);
    if(!n&&!q){
      return 0;
    }

    node root;
    root.marked = true;
    root.parent = 0;
    root.num = 1;
    T.push_back(&root);
    for(int i=2;i<n+1;i++){
      int parent;
      cin >> parent;
      node child = new node;
      child.marked = false;
      child.parent = T[parent-1];
      child.num = i;
      cout << &child << endl;
      T.push_back(&child);
    }

    for(int i=0;i<n;i++){
      if()
      cout << (*T[i]).num << ":" << (*T[i]).marked << endl;
    }
/*
    int sum = 0;
    for(int i=0;i<q;i++){
      char q;
      int v;
      cin >> q >> v;
      if(q=='M'){
        node n = *T[v-1];
        n.marked = true;
      }
      if(q=='Q'){
        node parent = *((*T[v-1]).parent);
        while(!parent.marked){
          parent = *(parent.parent);
        }
        sum += parent.num;
      }
    }
    for(int i=0;i<T.size();i++){
      cout << "num:" << (*T[i]).num << ",marked:" << (*T[i]).marked << endl;
    }
    cout << sum << endl;
    */
  //}
}