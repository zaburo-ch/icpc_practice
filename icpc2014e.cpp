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
vector<bool> used;
int dp[MAX_N][MAX_N];

bool cmp( const edge& left, const edge& right ) {
    if (g[left.to].size()==1){
        return true;
    }else if (g[right.to].size()==1){
        return false;
    }else{
        return left.cost < right.cost;
    }
}

bool check(){
    for(int i=0;i<n;i++){
        if(!used[i]) return false;
    }
    return true;
}

void fill_used(int v, int par){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        edge e = g[v][i];
        if (e.to == par)continue;
        fill_used(e.to, v);
    }
}

int dfs(int v, int par){
    //printf("v:%d par:%d\n",v,par);
    used[v] = true;
    if(par != -1 && dp[v][par] != -1){
        fill_used(v,par);
        return dp[v][par];
    }
    bool has_child = false;
    int cost = 0;
    int par_cost;
    for(int i=0;i<g[v].size();i++){
        edge e = g[v][i];
        if (e.to == par){
            par_cost = e.cost;
            continue;
        }
        has_child = true;
        cost += dfs(e.to, v);
    }
    if (has_child && par != -1){
        cost += par_cost;
        if (!check()){
            cost += par_cost;
        }
    }
    if(par != -1) dp[v][par] = cost;
    //printf("cost:%d\n",cost);
    return cost;
}


int main(){
    while(1){
        cin >> n;
        if (n==0) break;

        g.clear();
        g.resize(n);
        used.clear();
        used.resize(n);

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
        for(int i=0;i<n;i++){
            sort(g[i].begin(), g[i].end(), cmp);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = -1;
            }
        }

        int ans = INF;
        //cout << cost_sum << endl;
        for(int i=0;i<n;i++){
            fill(used.begin(), used.end(), false);
            int c = dfs(i,-1);
            ans = min(ans,cost_sum+c);
        }
        cout << ans << endl;
    }
    return 0;
}

