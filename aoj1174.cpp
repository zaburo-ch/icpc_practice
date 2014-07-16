#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int panel[6][8][8];
int h,w,c;
int counting;
int maximum;
int ans;

void roll(int num,int x,int y,int a){
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};

    int b=panel[num][y][x];
    panel[num][y][x]=a;
    if(a==0) counting++;
    for(int i=0;i<4;i++){
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        if(nextx>=0&&nextx<w&&nexty>=0&&nexty<h&&panel[num][nexty][nextx]==b)
            roll(num,nextx,nexty,a);
    }
}

void cpyArray(int num){
    for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
            panel[num+1][j][k] = panel[num][j][k];
        }
    }
}

void change(int num){
    if(num==4){
        if(panel[num][0][0]==c) return;
        cpyArray(num);
        roll(num+1,0,0,c);
        counting = 0;
        roll(num+1,0,0,0);
        if(ans<counting){
            ans = counting;
        }
        return;
    }
    for(int i=1;i<7;i++){
        if(panel[num][0][0]==i)continue;
        cpyArray(num);
        roll(num+1,0,0,i);
        change(num+1);
    }
}

int main(){
    int i,j,k;
    int numsame;

    while(1){
        cin>>h>>w>>c;
        if(h==0&&w==0&&c==0)break;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                cin>>panel[0][i][j];
            }
        }
        maximum=1;
        ans = 0;
        change(0);

        cout<< ans <<endl;

    }

    return 0;
}