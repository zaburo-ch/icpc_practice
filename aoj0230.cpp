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
    int d,t,s;
    bool operator<( const State& right ) const {
        return d > right.d;
    }
};

int bldg[2][100];
int d[2][100];
int main(){

    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;

        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&bldg[i][j]);
                d[i][j] = INF;
            }
        }

        priority_queue<State> que;
        d[0][0] = 0; d[1][0] = 0;
        que.push((State){0,0,0});
        que.push((State){0,0,1});
        int ans = -1;
        while(que.size()){
            State p = que.top(); que.pop();
            if(d[p.s][p.t] < p.d) continue;
            if(p.t==n-1){
                ans = p.d;
                break;
            }
            if(bldg[p.s][p.t]==0 || (bldg[p.s][p.t]==1&&bldg[p.s][p.t+1]!=1)){
                int nextd = d[p.s][p.t]+1;
                for(int i=1;i<=2&&p.t+i<n;i++){
                    if(bldg[p.s^1][p.t+i]==2){
                        int k = p.t+i-1;
                        while(bldg[p.s^1][k]==2) k--;
                        if(d[p.s^1][k]>nextd){
                            d[p.s^1][k] = nextd;
                            que.push((State){nextd,k,p.s^1});
                        }
                    }else{
                        if(d[p.s^1][p.t+i]>nextd){
                            d[p.s^1][p.t+i] = nextd;
                            que.push((State){nextd,p.t+i,p.s^1});
                        }
                    }
                }
            }else if(bldg[p.s][p.t]==1){
                for(int k=p.t+1;k<n;k++){
                    if(k+1==n || bldg[p.s][k+1]!=1){
                        if(d[p.s][k]>d[p.s][p.t]){
                            d[p.s][k] = d[p.s][p.t];
                            que.push((State){d[p.s][p.t],k,p.s});
                        }
                        break;
                    }
                }
            }
        }
        if(ans == -1) cout << "NA" << endl;
        else cout << ans << endl;
    }

    return 0;
}
