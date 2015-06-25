#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> P;
vector<int> e[100000];
int ans,x,y;
P opt[100000];

void dfs(int v,int p){
    printf("v:%d p:%d\n",v,p);
    P fr=P(0,v),sd=P(0,v);
    for(int i=0;i<e[v].size();i++){
        int u=e[v][i];
        if(u==p)continue;
        dfs(u,v);
        if(opt[u].first+1>fr.first){
            sd=fr;
            fr=P(opt[u].first+1,opt[u].second);
        }
        else if(opt[u].first+1>sd.first)sd=P(opt[u].first+1,opt[u].second);
    }
    if(fr.first+sd.first>ans){
        x=fr.second;y=sd.second;
        ans=fr.first+sd.first;
    }
    opt[v]=fr;
    printf("opt[%d]:%d,%d\n",v,opt[v].first,opt[v].second);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    ans=0;x=0;y=0;
    dfs(0,-1);
    printf("%d %d\n",x+1,y+1);
    return 0;
}