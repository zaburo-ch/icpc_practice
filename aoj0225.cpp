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
#include <complex>
using namespace std;

const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
struct edge{int to,cost;};


string str[10000];
vector<vec> g;
vector<bool> visited;
vec node_dim;

int dfs(int v){
    int count = 1;
    visited[v] = true;
    for(int i=0;i<g[v].size();i++){
        if(visited[g[v][i]]) continue;
        count += dfs(g[v][i]);
    }
    return count;
}

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;

        g.assign(26, vec());
        node_dim.assign(26, 0);
        set<int> use_alph;
        for(int i=0;i<n;i++){
            string str;
            cin >> str;
            int a = str[0]-'a', b = str[str.size()-1]-'a';
            g[a].push_back(b);
            g[b].push_back(a);
            node_dim[a]++;
            node_dim[b]--;
            if(!use_alph.count(a))use_alph.insert(a);
            if(!use_alph.count(b))use_alph.insert(b);
        }

        bool is_euler = true;
        for(int i=0;i<26;i++){
            if(node_dim[i]){
                is_euler = false;
                break;
            }
        }

        visited.assign(26,false);
        if(is_euler && dfs(0)==use_alph.size()){
            cout << "OK" << endl;
        }else{
            cout << "NG" << endl;
        }
    }

    return 0;
}
