#include <iostream>
#include <complex>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<string, int> P;

struct edge{
    string str;
    int to;
};

vector<edge> G[40];
vector<edge> rG[40];
vector<int> vs;
bool used[40];
int cmp[40];
int n;

void add_edge(int from, int to, string& str){
    G[from].push_back((edge){str,to});
    rG[to].push_back((edge){str,from});
}

void dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i].to]) dfs(G[v][i].to);
    }
}

void rdfs(int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(!used[rG[v][i].to])rdfs(rG[v][i].to,k);
    }
}

int succ(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<n;v++){
        if(!used[v])dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}

int main(){
    int a, s, g;
    while(cin >> n >> a >> s >> g, n){

        for(int i=0;i<n;i++){
            G[i].clear();
            rG[i].clear();
        }

        for(int i=0;i<a;i++){
            string str;
            int x, y;
            cin >> x >> y >> str;
            add_edge(x, y, str);
        }
        succ();

        for(int i=0;i<n;i++){
            if(G[i].size()==0) continue;
            string min_str = "-";
            int min_j = -1;
            for(int j=0;j<G[i].size();j++){
                if(cmp[G[i][j].to] == cmp[i]){
                    if(min_str=="-" || min_str > G[i][j].str){
                        min_str = G[i][j].str;
                    }
                }
            }
            if(min_str == "-"){
                cout << "aiueo "<< endl;
                continue;
            }else{
                cout << min_str << endl;
            }
            for(int j=0;j<G[i].size();j++){
                if(min_str < G[i][j].str){
                    G[i].erase(G[i].begin()+j);
                    j--;
                }
            }
        }


        priority_queue<P> que;
        vector<string> d(n, "-");
        d[s] = "";
        que.push(P("", s));
        while(que.size()){
            P p = que.top(); que.pop();
            int pn = p.second;
            string& ps = p.first;
            if(d[pn]!="-"&&d[pn]<ps) continue;
            if(pn == g){
                break;
            }
            for(int i=0;i<G[pn].size();i++){
                int nn = G[pn][i].to;
                string ns = ps + G[pn][i].str;
                if(d[nn]=="-" || d[nn] > ns){
                    d[nn] = ns;
                    que.push(P(ns, nn));
                }
            }
        }
        if(d[g] == "-") cout << "NO" << endl;
        else cout << d[g] << endl;

    }
    return 0;
}