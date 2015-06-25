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

string field[60];
int d[30][30];
int main(){
    int W,H;
    while(cin >> W >> H, W){
        for(int i=0;i<2*H-1;i++){
            string line;
            getline(cin, line);
            if(line.size()==0){
                i--;
                continue;
            }
            if(line.size()<2*W-1){
                line.push_back(' ');
            }
            field[i] = line;
        }

        for(int i=0;i<H;i++)for(int j=0;j<W;j++)d[i][j] = INF;
        d[0][0] = 1;
        queue<P> que;
        que.push(P(0, 0));
        while(que.size()){
            P p = que.front(); que.pop();
            int y = p.first, x = p.second;
            if(y==H-1&&x==W-1){
                break;
            }
            for(int i=0;i<4;i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny<0||H<=ny||nx<0||W<=nx)continue;
                if(field[2*y+dy[i]][2*x+dx[i]]=='0' && d[ny][nx] > d[y][x]+1){
                    d[ny][nx] = d[y][x]+1;
                    que.push(P(ny, nx));
                }
            }
        }
        if(d[H-1][W-1]==INF) cout << 0 << endl;
        else cout << d[H-1][W-1] << endl;
    }

    return 0;
}
