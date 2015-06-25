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
    int d,o,y,x,l,r;
    bool operator<(const State& right) const{
        return d == right.d ? o < right.o : d > right.d;
    }
};

const int dx[] = {-1,1,0};
const int dy[] = {0,0,1};
int field[10][10];
int d[51][10][10][10][10];

int main(){
    while(1){
        int W,H;
        scanf("%d%d",&W,&H);
        if(!W)break;

        int f,m,o;
        scanf("%d%d%d",&f,&m,&o);
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                scanf("%d",&field[i][j]);
            }
        }

        for(int i=0;i<51;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        fill(d[i][j][k][l],d[i][j][k][l]+10,INF);
                    }
                }
            }
        }

        priority_queue<State> que;
        for(int i=0;i<W;i++){
            int no = o-1, nd = 0;
            if(no<=0) continue;
            if(field[0][i]<0) nd -= field[0][i];
            else no = min(m, no+field[0][i]);
            d[no][0][i][i][i] = nd;
            que.push((State){nd,no,0,i,i,i});
        }

        int ans = -1;
        while(que.size()){
            State p = que.top(); que.pop();
            if(d[p.o][p.y][p.x][p.l][p.r]<p.d) continue;
            if(p.d>f)break;
            if(p.y==H-1){
                ans = p.d;
                break;
            }

            for(int i=0;i<3;i++){
                int nx = p.x + dx[i], ny = p.y + dy[i];
                if(nx<0||W<=nx||ny<0||H<=ny) continue;
                int nl = min(p.l, nx), nr = max(p.r, nx);
                int no = p.o - 1;
                if(no <= 0) continue;
                int nd = p.d;
                if(i==2){
                    nl = nx; nr = nx;
                }
                if(i==2 || nx < p.l || p.r < nx){
                    if(field[ny][nx]<0) nd -= field[ny][nx];
                    else no = min(m, no+field[ny][nx]);
                }
                if(d[no][ny][nx][nl][nr] > nd){
                    d[no][ny][nx][nl][nr] = nd;
                    que.push((State){nd, no, ny, nx, nl, nr});
                }
            }
        }
        if(ans==-1) cout << "NA" << endl;
        else cout << ans << endl;
    }

    return 0;
}
