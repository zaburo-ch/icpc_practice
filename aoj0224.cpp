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

struct State{
    int d,m,n;
    bool operator<( const State& right ) const {
        return d > right.d;
    }
};

int d[1<<6][108];
int cake[6];
int m,n,k,di;

int str2index(string& str){
    if(str[0]=='H'){
        return 0;
    }else if(str[0]=='D'){
        return 1;
    }else if(str[0]=='C'){
        return (int)(str[1]-'1'+2);
    }else{
        int p = 1, ret = 0;
        for(int i=str.size()-1;i>=1;i--){
            ret += (str[i]-'0')*p;
            p *=10;
        }
        return ret+1+m;
    }
}

int main(){
    while(1){
        scanf("%d%d%d%d",&m,&n,&k,&di);
        if(!n)break;

        vector<vector<edge> > g(n+m+2);
        for(int i=0;i<m;i++){
            scanf("%d",&cake[i]);
        }
        for(int i=0;i<di;i++){
            string a,b;
            int c;
            cin >> a >> b >> c;
            int a_i = str2index(a), b_i = str2index(b);
            g[a_i].push_back((edge){b_i,c});
            g[b_i].push_back((edge){a_i,c});
        }

        for(int i=0;i<(1<<m);i++){
            for(int j=0;j<n+m+2;j++){
                d[i][j] = INF;
            }
        }


        d[(1<<m)-1][0] = 0;
        priority_queue<State> que;
        que.push((State){0,(1<<m)-1,0});

        while(que.size()){
            State p = que.top(); que.pop();
            //printf("p.d=%d p.m=%d p.n=%d\n",p.d,p.m,p.n);
            if(d[p.m][p.n] < p.d) continue;
            for(int i=0;i<g[p.n].size();i++){
                int next_d = p.d+g[p.n][i].cost*k;
                if(2<=g[p.n][i].to&&g[p.n][i].to<m+2){
                    int m_i = g[p.n][i].to - 2;
                    if((p.m>>m_i)&1){
                        next_d -= cake[m_i];
                        int next_m = p.m^(1<<m_i);
                        if(next_d < d[next_m][g[p.n][i].to]){
                            d[next_m][g[p.n][i].to] = next_d;
                            que.push((State){next_d,next_m,g[p.n][i].to});
                        }
                    }
                }else{
                    if(next_d < d[p.m][g[p.n][i].to]){
                        d[p.m][g[p.n][i].to] = next_d;
                        que.push((State){next_d,p.m,g[p.n][i].to});
                    }
                }
            }
        }

        int ans = INF;
        for(int i=(1<<m)-1;i>=0;i--) ans = min(ans, d[i][1]);
        cout << ans << endl;
    }

    return 0;
}
