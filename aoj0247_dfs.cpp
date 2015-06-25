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
typedef vector<vec> mat;
typedef pair<int,int> P;
struct edge{int to,cost;};

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

char field[12][12];
int ifield[12][12];
int W,H;

struct State{
    int d,y,x;
    vec ice;
};

string state2str(State& s){
    string ret = "";
    ret.push_back(s.d+'0');
    ret.push_back(s.y+'0');
    ret.push_back(s.x+'0');
    for(int i=0;i<s.ice.size();i++){
        ret.push_back(s.ice[i]+'0');
    }
    return ret;
}

int lump_ice_num;
int ice_num[12*12];
int dfs(int y, int x){
    int ret = 1;
    ifield[y][x] = lump_ice_num;
    field[y][x] = '.';
    for(int i=0;i<4;i++){
        int ny = y+dy[i], nx = x+dx[i];
        if(ny<0||H<=ny||nx<0||W<=nx)continue;
        if(field[ny][nx]=='X'){
            ret += dfs(ny, nx);
        }
    }
    return ret;
}

bool visited[12][12];
int visited_ice[12*12];
int ans;
int sy, sx, gy, gx;
void dfs2(int y, int x, int py, int px, int d){
    //printf("%d %d\n",y,x);
    if(y==gy&&x==gx){
        ans = min(d, ans);
        return;
    }
    if(d + abs(gy-y) + abs(gx-x) >= ans) return;
    for(int i=0;i<4;i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny<0||H<=ny||nx<0||W<=nx)continue;
        if(ny==py&&nx==px)continue;
        if(visited[ny][nx]) return;
    }
    visited[y][x] = true;
    for(int i=0;i<4;i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny<0||H<=ny||nx<0||W<=nx)continue;
        //printf("y=%d x=%d ny=%d nx=%d\n", y, x, ny, nx);
        if(visited[ny][nx])continue;
        if(ifield[ny][nx]==-2)continue;
        if(ifield[ny][nx]>=0){
            int ice_i = ifield[ny][nx];
            if(ice_num[ice_i]/2 < visited_ice[ice_i]+1) continue;
            visited_ice[ice_i]++;
            dfs2(ny, nx, y, x, d+1);
            visited_ice[ice_i]--;
        }else{
            dfs2(ny, nx, y, x, d+1);
        }
    }
    visited[y][x] = false;
}

int main(){
    while(cin >> W >> H, W){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin >> field[i][j];
                if(field[i][j]=='.'){
                    ifield[i][j] = -1;
                }else if(field[i][j]=='#'){
                    ifield[i][j] = -2;
                }else if(field[i][j]=='S'){
                    ifield[i][j] = -1;
                    sy = i; sx = j;
                }else if(field[i][j]=='G'){
                    ifield[i][j] = -1;
                    gy = i; gx = j;
                }
            }
        }

        lump_ice_num = 0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(field[i][j]=='X'){
                    ice_num[lump_ice_num] = dfs(i,j);
                    lump_ice_num++;
                }
            }
        }

        ans = INF;
        memset(visited, 0, sizeof(visited));
        memset(visited_ice, 0, sizeof(visited_ice));
        dfs2(sy, sx, -1, -1, 0);
        cout << ans << endl;
    }

    return 0;
}
