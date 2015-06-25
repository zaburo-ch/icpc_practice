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
const int INF = (int)((unsigned int)-1>>1);

const int MAX_N = 1000000;
const int MAX_XY = 1001;
//const int MAX_N = 49;
//const int MAX_XY = 7;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
const int dx_cave[] = {-1,0,1};

int n, m;
bool is_prime[MAX_N+1];
int cave[MAX_XY][MAX_XY];
P ans;
P dp[MAX_XY][MAX_XY];

void dfs(int y, int x, P p){
    if(dp[y][x] > p) return;
    else dp[y][x] = p;

    if (is_prime[cave[y][x]]) p = P(p.first+1, cave[y][x]);
    bool is_leaf = true;
    for(int i=0;i<3;i++){
        int nextx = x+dx_cave[i], nexty = y+1;
        if (0<=nextx && nextx<MAX_XY && 0<=nexty && nexty<MAX_XY && cave[nexty][nextx]<=n ){
            dfs(nexty, nextx, p);
            is_leaf = false;
        }
    }
    if(is_leaf){
        if (ans < p){
            ans = p;
        }
    }
}


int main(){
    P point[MAX_N+1];
    int r = 1, n1 = 1, count = 0, dire = 0;
    int x = MAX_XY/2, y = MAX_XY/2;
    while(n1 <= MAX_N){
        cave[y][x] = n1;
        point[n1] = P(y,x);
        n1++;
        x += dx[dire]; y+= dy[dire];
        count++;
        if (r == count){
            count = 0;
            dire++;
            if(dire==4) dire = 0;
            if(dire==0 || dire==2) r++;
        }
    }

    fill(is_prime,is_prime+MAX_N+1,true);
    is_prime[1] = false;
    for(int i=2;i<=MAX_N;i++){
        if(is_prime[i]){
            for(int j=2;j*i<=MAX_N;j++){
                is_prime[j*i] = false;
            }
        }
    }

    while(1){
        cin >> m >> n;
        if (m==0)break;
        ans = P(0,0);
        for(int i=0;i<MAX_XY;i++)for(int j=0;j<MAX_XY;j++)dp[i][j] = P(-1,-1);
        dfs(point[n].first, point[n].second, ans);
        printf("%d %d\n",ans.first,ans.second);
    }
    /*
    for(int i=0;i<MAX_XY;i++){
        for(int j=0;j<MAX_XY;j++){
            printf("%2d ",cave[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}