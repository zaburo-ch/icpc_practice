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

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

char c[500][500];
bool ans;
int H,W;


void dfs(int y,int x){
    for(int i=0;i<4;i++){
        int nextx = x + dx[i], nexty = y + dy[i];
        //cout << c[nexty][nextx] << endl;
        if (0<=nextx&&nextx<W&&0<=nexty&&nexty<H){
            if (c[nexty][nextx]=='.'){
                c[nexty][nextx] = '#';
                dfs(nexty, nextx);
            }else if(c[nexty][nextx]=='g'){
                ans = true;
                return;
            }
        }
    }
    return;
}

int main(){
    cin >> H >> W;
    int sx,sy;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> c[i][j];
            if(c[i][j]=='s'){
                sx = j;
                sy = i;
            }
        }
    }
    ans = false;
    dfs(sy,sx);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

