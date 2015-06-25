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


int field[10][10];
int ans[10][10];
int kukaku[15];
P start[15];
int X,Y,n;

void copy_field(){
    for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            ans[i][j] = field[i][j];
        }
    }
}

void print_field(){
    for(int i=0;i<Y;i++){
        cout << ans[i][0];
        for(int j=1;j<X;j++){
            printf(" %d",ans[i][j]);
        }
        printf("\n");
    }
}

int  dfs(int n_i){
    if(n_i == n){
        copy_field();
        return 1;
    }
    int p = 0;
    for(int tate=1;tate<=kukaku[n_i];tate++){
        if (kukaku[n_i]%tate)continue;
        int yoko = kukaku[n_i] / tate;
        //printf("tate=%d yoko=%d\n",tate,yoko);
        for(int y=start[n_i].first-tate+1; y<=start[n_i].first; y++){
            for(int x=start[n_i].second-yoko+1; x<=start[n_i].second; x++){
                //printf("n_i=%d x=%d y=%d\n",n_i,x,y);
                if(!(0<=y&&y+tate-1<Y&&0<=x&&x+yoko-1<X)) continue;
                bool can_paint = true;
                for(int i=0;i<tate;i++){
                    for(int j=0;j<yoko;j++){
                        if(field[y+i][x+j]==0||field[y+i][x+j]==n_i+1){
                            field[y+i][x+j] = n_i+1;
                        }else{
                            can_paint = false;
                            break;
                        }
                    }
                }
                //printf("can_paint=%d\n",can_paint);
                if(can_paint){
                    p += dfs(n_i+1);
                    if(p>1) return p;
                }
                for(int i=0;i<tate;i++){
                    for(int j=0;j<yoko;j++){
                        if(field[y+i][x+j]==n_i+1){
                            field[y+i][x+j] = 0;
                        }
                    }
                }
                field[start[n_i].first][start[n_i].second] = n_i+1;
            }
        }
    }
    return p;
}


int main(){
    while(1){
        scanf("%d%d%d",&X,&Y,&n);
        if(!X)break;

        for(int i=0;i<n;i++){
            int d;
            scanf("%d",&d);
            scanf("%d",&kukaku[d-1]);
        }

        for(int i=0;i<Y;i++){
            for(int j=0;j<X;j++){
                scanf("%d",&field[i][j]);
                if(field[i][j]>0){
                    start[field[i][j]-1] = P(i,j);
                }
            }
        }
        if(dfs(0)==1){
            print_field();
        }else{
            printf("NA\n");
        }

        //break;
    }

    return 0;
}
