#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <utility>
#include <set>
using namespace std;

bool kaku[501][501];
int mapp[1001][1001];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int r,c;
bool pos=false;



void check(int x,int y){
    bool sidefree=false;
    int touitu;
    if(x==r&&y==c){
        for(int i=0;i<4;i++){
            if(kaku[x+1+dx[i]][y+1+dy[i]]&&mapp[2*x-1+dx[i]][2*y-1+dy[i]]==0){
                pos=true;
                return;
            }
        }
    }
    if(kaku[x+1][y+1]) return;
    for(int i=0;i<4;i++){
        if(kaku[x+1+dx[i]][y+1+dy[i]]){
            if(sidefree){
                if(touitu!=mapp[2*x-1+dx[i]][2*y-1+dy[i]]){
                    kaku[x+1][y+1]=true;
                    for(int i=0;i<4;i++){
                        check(x+dx[i],y+dy[i]);
                    }
                }
            }
            else{
                touitu=mapp[2*x+dx[i]][2*y+dy[i]];
                sidefree=true;
            }
        }
    }
}

int main(){

    int h,w;

    while(1){
        cin>>h>>w>>r>>c;
        if(h==0&&w==0&&r==0&&c==0) break;

        for(int i=0;i<w+1;i++) {
            kaku[i][0]=true;
            kaku[i][h+1]=true;
        }
        for(int i=0;i<h+1;i++){
            kaku[0][i]=true;
            kaku[w+1][i]=true;
        }
            for(int j=1;j<=h;j++){
                for(int i=0;i<=w;i++){
                    kaku[i][j]=false;
                }
            }
        for(int j=0;j<h;j++){
            for(int i=0;i<w;i++){
                    cin>>mapp[2*i+1][2*j];
                }
            for(int i=0;i<w;i++){
                    cin>>mapp[2*i][2*j+1];
            }
            cin>>mapp[0][2*j];
        }

        check(0,0);
        check(w-1,0);
        check(0,h-1);
        check(w-1,h-1);

        if(pos)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}