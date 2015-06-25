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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1);
const int MAX_N = 100;

double dp[2][201][101][101];

int main(){
    int N;
    long long int D;
    scanf("%d %lld", &N, &D);

    int c[3] = {0};
    while(D%2==0){
        c[0]++;
        D /= 2;
    }
    while(D%3==0){
        c[1]++;
        D /= 3;
    }
    while(D%5==0){
        c[2]++;
        D /= 5;
    }
    if(D!=1){
        printf("%.9lf\n", 0.0);
    }else{
        dp[0][0][0][0] = 1;
        int cur = 0, next = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<=2*i+2;j++)for(int k=0;k<=i+1;k++)for(int l=0;l<=i+1;l++) dp[next][j][k][l] = 0;
            for(int j=0;j<=2*i;j++){
                for(int k=0;k<=i;k++){
                    for(int l=0;l<=i;l++){
                        dp[next][j][k][l] += dp[cur][j][k][l];
                        dp[next][j+1][k][l] += dp[cur][j][k][l];
                        dp[next][j][k+1][l] += dp[cur][j][k][l];
                        dp[next][j+2][k][l] += dp[cur][j][k][l];
                        dp[next][j][k][l+1] += dp[cur][j][k][l];
                        dp[next][j+1][k+1][l] += dp[cur][j][k][l];
                    }
                }
            }
            swap(cur,next);
        }
        double ans = 0;
        for(int j=c[0];j<=2*N;j++){
            for(int k=c[1];k<=N;k++){
                for(int l=c[2];l<=N;l++){
                    ans += dp[cur][j][k][l];
                }
            }
        }
        for(int i=0;i<N;i++) ans /= 6;
        printf("%.9lf\n", ans);
    }
    return 0;
}