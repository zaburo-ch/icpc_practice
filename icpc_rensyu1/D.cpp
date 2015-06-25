#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int counting;
char cp[10][60];
int ip[10][60];
int w,h;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct node{
    bool exist;
    bool chilexi;
    double mass;
    double center;
    double xl;
    double xr;
    int parent;
};

struct node tree[150];


void cdfs(int x,int y){
    ip[x][y]=counting;
    int nx,ny;
    for(int i=0;i<4;i++){
        nx=x+dx[i];ny=y+dy[i];
        if(nx>=0&&nx<w&&ny>=0&&ny<h) cdfs(nx,ny);
    }
}

void idfs(int a,int x,int y){
    int nx,ny;
    tree[a].center=(tree[a].center*(double)tree[a].mass+(double)x+0.5)/(double)(tree[a].mass+1);
    tree[a].mass+=1;
    tree[a].xl=min(tree[a].xl,(double)x);
    tree[a].xr=max(tree[a].xl,(double)x+1);
    if(y<h-1&&ip[x][y+1]!=-1&&ip[x][y+1]!=ip[x][y]) {
        tree[a].parent=ip[x][y+1];
        tree[ip[x][y+1]].chilexi=true;
    }
    ip[x][y]=-1;
    for(int i=0;i<4;i++){
        nx=x+dx[i];ny=y+dy[i];
        if(nx>=0&&nx<w&&ny>=0&&ny<h) idfs(a,nx,ny);
    }
}

int main(){

    queue<int> q;
    int t;
    bool stable;

    while(1){
        cin>>w>>h;
        counting=0;
        stable=true;
        if(w==0&&h==0) break;

        for(int i=0;i<150;i++){
            tree[i].exist=false;
            tree[i].chilexi=false;
        }

        for(int j=0;j<h;j++){
            for(int i=0;i<w;i++){
                cin>>cp[i][j];
                ip[i][j]=-1;
            }
        }
        for(int j=0;j<h;j++){
            for(int i=0;i<w;i++){
                if(ip[i][j]==-1&&cp[i][j]!='.'){
                    cdfs(i,j);
                    counting++;
                }
            }
        }
        counting=0;
        for(int j=0;j<h;j++){
            for(int i=0;i<w;i++){
                if(ip[i][j]==counting){
                    tree[counting].exist=true;
                    tree[counting].mass=0.0;
                    tree[counting].center=(double)i+0.5;
                    tree[counting].xl=(double)i;
                    tree[counting].xr=(double)i+1;
                    idfs(counting,i,j);
                }
            }
        }

        for(int i=0;i<150;i++){
            if(!tree[i].chilexi&&tree[i].exist) q.push(i);
        }

        while(q.size()){
            t=q.front();q.pop();
            tree[t].exist=false;
            if(tree[t].center<=tree[t].xl||tree[t].center>=tree[t].xr) {
                stable=false;
                break;
            }
            tree[tree[t].parent].center = (tree[tree[t].parent].center*(double)tree[tree[t].parent].mass+tree[t].center*(double)tree[t].mass)/(double)(tree[tree[t].parent].mass+tree[t].mass);
            tree[tree[t].parent].mass+=tree[t].mass;
            q.push(tree[t].parent);
        }

        if(stable)cout<<"STABLE"<<endl;
        else cout<<"UNSTABLE"<<endl;

    }

    return 0;
}