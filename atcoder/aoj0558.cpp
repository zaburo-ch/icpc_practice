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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1);
const int MAX_N = 100;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int H, W, N;
P s;
P c[9];
bool map_mat[1000][1000];

struct state{
    int d,to,y,x;
};

int main(){
    scanf("%d %d %d", &H, &W, &N);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char ch;
            cin >> ch;
            if (ch == 'S'){
                s = P(i,j);
            }else if ('1' <= ch && ch <= '9'){
                c[(int)(ch-'1')] = P(i,j);
            }
            if (ch == 'X'){
                map_mat[i][j] = false;
            }else{
                map_mat[i][j] = true;
            }
        }
    }

    queue<state> que;
    que.push((state){0, 0, s.first, s.second});
    bool itta[1000][1000];
    for(int i=0;i<H;i++)for(int j=0;j<W;j++) itta[i][j] = false;
    itta[0][0] = true;

    while(que.size()){
        state q = que.front(); que.pop();
        //printf("%d %d %d %d\n",q.d,q.to,q.y,q.x);
        if (c[q.to].second == q.x && c[q.to].first == q.y){
            q.to += 1;
            while(que.size()) que.pop();
            if (q.to == N){
                printf("%d\n", q.d);
                break;
            }else{
                for(int i=0;i<H;i++)for(int j=0;j<W;j++) itta[i][j] = false;
                itta[q.y][q.x] = true;
            }
        }
        for(int i=0;i<4;i++){
            int nextx = q.x+dx[i], nexty = q.y+dy[i];
            if(0<=nextx && nextx<W && 0<=nexty && nexty<H && map_mat[nexty][nextx] && !itta[nexty][nextx]){
                itta[nexty][nextx] = true;
                que.push((state){q.d+1, q.to, nexty, nextx});
            }
        }
    }

    return 0;
}