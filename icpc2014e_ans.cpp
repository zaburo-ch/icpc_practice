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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1) / 2;
const int MAX_N = 800;

struct edge{int to,cost;};

int n;
vector<vector<edge> > g;
vector<bool> is_node;

P dfs(int v, int par, int cost){
    P p = P(cost,v);
    for(int i=0;i<g[v].size();i++){
        edge e = g[v][i];
        if (e.to == par || !is_node[e.to])continue;
        p = max(p, dfs(e.to, v, cost+e.cost));
    }
    return p;
}

int main(){
    while(1){
        cin >> n;
        if (n==0) break;

        g.clear();
        g.resize(n);
        is_node.clear();
        is_node.resize(n);

        vector<int> p(n);
        vector<int> d(n);
        int cost_sum = 0;
        for(int i=0;i<n-1;i++){
            scanf("%d", &p[i]);
        }
        for(int i=0;i<n-1;i++){
            scanf("%d", &d[i]);
            cost_sum += d[i];
        }
        for(int i=0;i<n-1;i++){
            g[p[i]-1].push_back((edge){i+1,d[i]});
            g[i+1].push_back((edge){p[i]-1,d[i]});
        }

        int inner_sum = cost_sum;
        for(int i=0;i<n;i++){
            if(g[i].size()==1){
                inner_sum -= g[i][0].cost;
                is_node[i] = false;
            }else{
                is_node[i] = true;
            }
        }

        int longest_path = 0;
        for(int i=0;i<n;i++){
            if(is_node[i]){
                longest_path = dfs(dfs(i,-1,0).second,-1,0).first;
                break;
            }
        }

        cout << cost_sum+2*inner_sum-longest_path << endl;
    }
    return 0;
}

