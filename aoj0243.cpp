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
typedef pair<int,int> P;
struct edge{int to,cost;};


typedef vector<char> vec;
typedef vector<vec> mat;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int X, Y;

struct State{
    int d,pn;
    char c;
    mat f;
    bool operator<(const State& right) const{
        return d == right.d ? pn < right.pn : d > right.d;
    }
};

int paint(int y, int x, char c, char nc, mat& f){
    f[y][x] = nc;
    int ret = 1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||X<=nx||ny<0||Y<=ny||f[ny][nx]!=c) continue;
        ret += paint(ny, nx, c, nc, f);
    }
    return ret;
}

const char color[] = {'R','G','B'};
int dfs(int pn, mat& f){
    int turn = 100;
    for(int i=0;i<3;i++){
        if(f[0][0]==color[i])continue;
        mat nf = f;
        int npn = paint(0,0,f[0][0],color[i],nf);
        if(npn==X*Y) return 0;
        if(npn<=pn) continue;
        else turn = min(turn, 1+dfs(npn, nf));
    }
    return turn;
}

int main(){
    while(cin >> X >> Y, X){
        mat field(Y, vec(X));
        for(int i=0;i<Y;i++){
            for(int j=0;j<X;j++){
                cin >> field[i][j];
            }
        }
        priority_queue<State> que;
        //int d[100][100];
        //for(int i=0;i<100;i++)fill(d[i],d[i]+100,INF);
        int d[101];fill(d,d+101,INF);
        d[0] = 0;
        que.push((State){0,0,field[0][0],field});
        bool ans_found = false;
        while(que.size()){
            State p = que.top(); que.pop();
            if(d[p.pn]<p.d) continue;
            for(int i=0;i<3;i++){
                if(p.c==color[i])continue;
                mat nf = p.f;
                int npn = paint(0,0,p.f[0][0],color[i],nf);
                if(npn == X*Y){
                    ans_found = true;
                    break;
                }
                if(npn <= p.pn) continue;
                if(d[npn]<p.d+1) continue;
                d[npn] = p.d+1;
                que.push((State){p.d+1,npn,color[i],nf});
            }
            if(ans_found){
                cout << p.d << endl;
                break;
            }
        }
    }

    return 0;
}
