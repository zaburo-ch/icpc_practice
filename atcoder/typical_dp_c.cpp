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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1) /2;
const int MAX_K = 10;
const int MAX_N = 1<<MAX_K;

int K;
int R[MAX_N];
double dp[MAX_K][MAX_N];


double p(int i_win, int i_lose){
    return (double)1/(pow(10, (double)(R[i_lose]-R[i_win])/400)+1);
}

/*
double dfs(int k, int r){
    if(dp[k][r]>-0.5) return dp[k][r];
    int k2 = 1 << (k+1);
    int rs = r / k2 * k2;
    int k2p = 1 << k;
    int rsp = r / k2p * k2p;
    dp[k][r] = 0;
    for(int i=0;i<k2;i++){
        if (rsp <= rs+i && rs+i < rsp + k2p) continue;
        dp[k][r] += p(r, rs+i) * dfs(k-1, rs+i);
    }
    dp[k][r] *= dfs(k-1, r);
    return dp[k][r];
}
*/

int main(){
    scanf("%d", &K);
    for(int i=0;i<(1<<K);i++){
        scanf("%d", &R[i]);
    }

    /*
    for(int j=1;j<K;j++){
        for(int i=0;i<(1<<K);i++){
            dp[j][i] = -1;
        }
    }
    */

    for(int i=0;i+1<(1<<K);i+=2){
        dp[0][i] = p(i, i+1);
        dp[0][i+1] = p(i+1, i);
    }

    for(int k=1;k<K;k++){
        for(int r=0;r<(1<<K);r++){
            int k2 = 1 << (k+1);
            int rs = r / k2 * k2;
            int k2p = 1 << k;
            int rsp = r / k2p * k2p;
            dp[k][r] = 0;
            for(int i=0;i<k2;i++){
                if (rsp <= rs+i && rs+i < rsp + k2p) continue;
                dp[k][r] += p(r, rs+i) * dp[k-1][rs+i];
            }
            dp[k][r] *= dp[k-1][r];
        }
    }

    /*
    for(int i=0;i<(1<<K);i++){
        printf("%.9lf\n", dfs(K-1, i));
    }
    */
    for(int i=0;i<(1<<K);i++){
        printf("%.9lf\n", dp[K-1][i]);
    }
    return 0;
}