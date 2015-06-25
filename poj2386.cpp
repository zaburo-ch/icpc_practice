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
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

char m[100][100];
int N,M;

const int dx[] = {-1,0,1,-1,1,-1,0,1};
const int dy[] = {-1,-1,-1,0,0,1,1,1};

void dfs(int y,int x){
    m[y][x] = '.';
    for(int i=0;i<8;i++){
        int nextx = x + dx[i], nexty = y + dy[i];
        if(0<=nextx && nextx<M && 0<=nexty && nexty<N){
            if(m[nexty][nextx]=='W'){
                dfs(nexty,nextx);
            }
        }
    }
}

void print_mat(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main(){
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> m[i][j];
        }
    }
    //cout << "before" << endl;
    //print_mat();

    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(m[i][j]=='W'){
                ans++;
                dfs(i,j);
                //cout << "ans:" << ans << endl;
                //print_mat();
            }
        }
    }

    cout << ans << endl;


    return 0;
}