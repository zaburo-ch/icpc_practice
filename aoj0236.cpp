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

int field[7][7];
int space_sum;
int W, H;
int sy, sx;

void print_field(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            printf("%2d",field[i][j]);
        }
        cout << endl;
    }
}

int get_dim(int y, int x){
    int dim = 0;
    for(int k=0;k<4;k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx<0||W<=nx||ny<0||H<=ny)continue;
        if(field[ny][nx]==0) dim++;
    }
    return dim;
}

bool dfs(int y, int x, int d_sum){
    //cout << y << " " << x << endl;
    //print_field();
    if(d_sum==space_sum){
        if(abs(sy-y)+abs(sx-x)==1)return true;
    }else{
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(field[i][j]) continue;
                if(abs(sy-i)+abs(sx-j)==1||abs(y-i)+abs(x-j)==1) continue;
                if(get_dim(i, j)==1) return false;
            }
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx<0||W<=nx||ny<0||H<=ny)continue;
            if(field[ny][nx]==0){
                field[ny][nx] = 1;
                if (dfs(ny, nx, d_sum+1)) return true;
                field[ny][nx] = 0;
            }
        }
    }
    return false;
}

int main(){
    while(cin >> W >> H, W){
        space_sum = 0;
        sy = -1; sx = -1;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                scanf("%d",&field[i][j]);
                //if(field[i][j]==0) space_sum++;
                space_sum += !field[i][j];
                if(sy<0&&!field[i][j]){
                    sy = i; sx = j;
                }
            }
        }
        if(sy>=0) field[sy][sx] = 1;
        if(space_sum<4||space_sum%2==1||!dfs(sy, sx, 1)){
            cout << "No" << endl;
            continue;
        }else{
            cout << "Yes" << endl;
        }
    }

    return 0;
}
