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
typedef pair<int,int> P;
const int INF = 1<<29;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int field[100][100];

int w,h;
int xs,ys,xg,yg;

bool dfs(int y,int x){
    if(field[y][x]==0) return false;
    if(y==yg && x==xg) return true;
    int c = field[y][x];
    field[y][x] = 0;
    for(int i=0;i<4;i++){
        int nextx = x+dx[i], nexty = y+dy[i];
        if(0<=nextx&&nextx<w&&0<=nexty&&nexty<h && c==field[nexty][nextx]){
            if(dfs(nexty,nextx)) return true;
        }
    }
    return false;
}

int main(){
    while(1){
        scanf("%d%d",&w,&h);
        if(w==0)break;

        scanf("%d%d%d%d",&xs,&ys,&xg,&yg);
        xs--;ys--;xg--;yg--;

        int n;
        scanf("%d",&n);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                field[i][j] = 0;
            }
        }
        for(int k=0;k<n;k++){
            int c,d,x,y;
            scanf("%d%d%d%d",&c,&d,&x,&y);
            x--;y--;
            int tate=2,yoko=4;
            if(d) swap(tate,yoko);
            for(int i=y;i<y+tate;i++){
                for(int j=x;j<x+yoko;j++){
                    field[i][j] = c;
                }
            }
        }
        /*
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                printf("%2d",field[i][j]);
            }
            printf("\n");
        }
        */


        if(dfs(ys,xs))cout << "OK" << endl;
        else cout << "NG" << endl;
    }

    return 0;
}
