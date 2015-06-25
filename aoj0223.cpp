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

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

struct node{
    int d,tx,ty,kx,ky;
};

int d[50][50][50][50];
int field[50][50];

int main(){
    while(1){
        int X,Y;
        scanf("%d%d",&X,&Y);
        if(!X)break;

        int tx,ty,kx,ky;
        scanf("%d%d%d%d",&tx,&ty,&kx,&ky);
        tx--;ty--;kx--;ky--;

        for(int i=0;i<Y;i++){
            for(int j=0;j<X;j++){
                scanf("%d",&field[i][j]);
            }
        }

        for(int i=0;i<X;i++){
            for(int j=0;j<Y;j++){
                for(int k=0;k<X;k++){
                    for(int l=0;l<Y;l++){
                        d[i][j][k][l] = INF;
                    }
                }
            }
        }

        queue<node> que;
        d[tx][ty][kx][ky] = 0;
        que.push((node){0,tx,ty,kx,ky});
        bool not_reach = true;
        while(que.size()){
            node p = que.front(); que.pop();
            if(p.d>=100)break;
            if(p.tx==p.kx&&p.ty==p.ky){
                printf("%d\n",p.d);
                not_reach = false;
                break;
            }
            for(int i=0;i<4;i++){
                int n_tx = p.tx+dx[i], n_ty = p.ty+dy[i];
                int n_kx = p.kx-dx[i], n_ky = p.ky-dy[i];
                if(n_tx<0||X<=n_tx||n_ty<0||Y<=n_ty||field[n_ty][n_tx]){
                    n_tx = p.tx; n_ty = p.ty;
                }
                if(n_kx<0||X<=n_kx||n_ky<0||Y<=n_ky||field[n_ky][n_kx]){
                    n_kx = p.kx; n_ky = p.ky;
                }
                if(d[n_tx][n_ty][n_kx][n_ky]>p.d+1){
                    d[n_tx][n_ty][n_kx][n_ky] = p.d+1;
                    que.push((node){p.d+1,n_tx,n_ty,n_kx,n_ky});
                }
            }
        }
        if(not_reach)printf("NA\n");
    }
    return 0;
}
