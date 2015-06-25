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
//typedef vector<int> vec;
typedef vector<char> vec;
typedef vector<vec> mat;
typedef pair<int,int> P;
struct edge{int to,cost;};

struct State{
    int t,get,y,x;
};
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

bool visited[100][(1<<10)][20][20];

int main(){
    int w, h;
    while(cin >> w >> h, w){
        mat field(h, vec(w));
        int sx,sy;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> field[i][j];
                if(field[i][j]=='P'){
                    sx = j; sy = i;
                }
            }
        }

        int de_sum[(1<<10)];
        fill(de_sum, de_sum+(1<<10), 0);
        int n;
        cin >> n;
        int st_i[10], et_i[10];
        fill(st_i,st_i+10,INF);
        fill(et_i,et_i+10,-INF);
        for(int i=0;i<n;i++){
            int go, de, st, et;
            scanf("%d%d%d%d", &go, &de, &st, &et);
            st_i[go] = st; et_i[go] = et;
            for(int j=1;j<(1<<10);j++){
                if((j>>go)&1){
                    de_sum[j] += de;
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        queue<State> que;
        que.push((State){0,0,sy,sx});
        int ans = 0;
        while(que.size()){
            State p = que.front(); que.pop();
            //printf("p.t=%d p.get=%d p.y=%d p.x=%d\n",p.t,p.get,p.y,p.x);
            for(int j=0;j<4;j++){
                int ny = p.y + dy[j], nx = p.x + dx[j];
                if(ny<0||h<=ny||nx<0||w<=nx)continue;
                if('0'<=field[ny][nx]&&field[ny][nx]<='9'){
                    int g_i = field[ny][nx] - '0';
                    if(st_i[g_i] <= p.t && p.t < et_i[g_i]){
                        p.get |= (1<<g_i);
                    }
                }
            }
            if(visited[p.t][p.get][p.y][p.x]) continue;
            visited[p.t][p.get][p.y][p.x] = true;
            ans = max(ans, de_sum[p.get]);
            for(int i=0;i<4;i++){
                int ny = p.y + dy[i], nx = p.x + dx[i];
                if(ny<0||h<=ny||nx<0||w<=nx) continue;
                if(field[ny][nx]=='.'||field[ny][nx]=='P'){
                    if(p.t+1<100&&!visited[p.t+1][p.get][ny][nx]){
                        que.push((State){p.t+1, p.get, ny, nx});
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
