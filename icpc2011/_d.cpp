#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node{
  int x,y,r,c;
  vector<int> parent;
  vector<int> child;
};
node tree[24];
int n;
vector<int> root;
int counter;
int ans;

bool pailed(int a,int b){
  int d2 = (tree[a].x-tree[b].x)*(tree[a].x-tree[b].x)+(tree[a].y-tree[b].y)*(tree[a].y-tree[b].y);
  int r2 = (tree[a].r+tree[b].r)*(tree[a].r+tree[b].r);
  return d2 < r2;
}

void dfs(){
  for(int i=0;i<root.size();i++){
    for(int j=i+1;j<root.size();j++){
      if(tree[root[i]].c==tree[root[j]].c){
      cout << i << " " << j << endl;
        int push_num = 0;
        int nodea = root[i];
        int nodeb = root[j];
        root.erase(root.begin()+i,root.begin()+i+1);
        root.erase(root.begin()+j-1,root.begin()+j);
        for(int k=0;k<tree[nodea].child.size();k++){
          if(tree[tree[nodea].child[k]].parent.size()==1){
            root.push_back(tree[nodea].child[k]);
            push_num++;
            tree[tree[nodea].child[k]].parent.pop_back();
          }else{
            vector<int>::iterator it = find(tree[tree[nodea].child[k]].parent.begin(),tree[tree[nodea].child[k]].parent.end(),nodea);
            tree[tree[nodea].child[k]].parent.erase(it,it+1);
          }
        }
        for(int k=0;k<tree[nodeb].child.size();k++){
          if(tree[tree[nodeb].child[k]].parent.size()==1){
            tree[tree[nodeb].child[k]].parent.pop_back();
            root.push_back(tree[nodeb].child[k]);
            push_num++;
          }else{
            vector<int>::iterator it = find(tree[tree[nodeb].child[k]].parent.begin(),tree[tree[nodeb].child[k]].parent.end(),nodeb);
            tree[tree[nodeb].child[k]].parent.erase(it,it+1);
          }
        }
        counter+=2;
        dfs();
        if(ans<counter){
          ans = counter;
        }
        counter-=2;

        //もとに戻す
        for(int k=0;k<push_num;k++){
          root.pop_back();
        }
        root.insert(root.begin()+i,nodea);
        root.insert(root.begin()+j,nodeb);

        for(int k=0;k<tree[nodea].child.size();k++){
          tree[tree[nodea].child[k]].parent.push_back(nodea);
        }
        for(int k=0;k<tree[nodea].child.size();k++){
          tree[tree[nodeb].child[k]].parent.push_back(nodeb);
        }
      }
    }
  }
}

int main(){
  while(cin >> n,n){
    for(int i=0;i<n;i++){
      int x,y,r,c;
      scanf("%d%d%d%d",&x,&y,&r,&c);
      tree[i] = (node){x,y,r,c};
    }
    for(int i=n-1;i>=0;i--){
      for(int j=i-1;j>=0;j--){
        if(pailed(i,j)){
          tree[i].parent.push_back(j);
          tree[j].child.push_back(i);
        }
      }
      if(tree[i].parent.size()==0){
        root.push_back(i);
      }
    }

    ans = 0;
    counter = 0;
    dfs();

    cout << ans << endl;
  }
}