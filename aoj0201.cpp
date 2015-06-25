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


int n,m;
string name[100];
int cost[100];
map<string, int> nametoi;
vector<vector<int> > g;

int dfs(int v){
    //printf("%d %d\n",v,cost[v]);
    if(g[v].size()!=0){
        int wrought_c = 0;
        for(int i=0;i<g[v].size();i++){
            wrought_c += dfs(g[v][i]);
        }
        cost[v] = min(cost[v],wrought_c);
    }
    return cost[v];
}

int main(){
    while(1){
        scanf("%d", &n);
        if(n==0)break;
        g.clear();
        g.resize(n);
        for(int i=0;i<n;i++){
            cin >> name[i] >> cost[i];
            nametoi[name[i]] = i;
        }

        scanf("%d",&m);
        for(int i=0;i<m;i++){
            string target;
            int e_num;
            cin >> target >> e_num;

            int target_i = nametoi[target];
            for(int j=0;j<e_num;j++){
                string e;
                cin >> e;
                g[target_i].push_back(nametoi[e]);
            }
        }
        string str;
        cin >> str;
        cout << dfs(nametoi[str]) << endl;
    }
    return 0;
}
