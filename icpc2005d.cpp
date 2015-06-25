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
const int INF = ~(1<<31) / 2;

struct edge{int to,cost;};

int t[8];
vector<vector<edge> > g;
double dp[1<<8][30];

int main(){
    while(1){
        int n, m, p, a, b;
        scanf("%d %d %d %d %d",&n, &m, &p, &a, &b);
        if (n==0)break;
        a--;b--;

        g.clear();
        g.resize(m);
        for(int i=0;i<n;i++){
            scanf("%d", &t[i]);
        }
        for(int i=0;i<p;i++){
            int x,y,z;
            scanf("%d %d %d", &x, &y, &z);
            x--;y--;
            g[x].push_back((edge){y,z});
            g[y].push_back((edge){x,z});
        }

        for(int i=0;i<1<<n;i++)for(int j=0;j<m;j++)dp[i][j] = 10000;
        dp[(1<<n)-1][a] = 0;

        for(int i=(1<<n)-1;i>=0;i--){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if (dp[i][j]<10000 && i&(1<<k)){
                        int used = i&(~(1<<k));
                        for(int l=0;l<g[j].size();l++){
                            double d_next = dp[i][j] + (double)g[j][l].cost / t[k];
                            //printf("%d -> %d : %lf\n", j, g[j][l].to, d_next);
                            dp[used][g[j][l].to] = min(d_next, dp[used][g[j][l].to]);
                        }
                    }
                }
            }
        }

        double ans = 10000;
        for(int i=(1<<n)-1;i>=0;i--)ans = min(ans,dp[i][b]);
        if(ans >= 9000) printf("Impossible\n");
        else printf("%.3lf\n",ans);
    }
    return 0;
}