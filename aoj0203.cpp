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
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

int field[15][15];
int dp[15][15];

int main(){
    while(1){
        int X,Y;
        scanf("%d %d",&X,&Y);
        if(X==0)break;
        for(int i=0;i<Y;i++){
            for(int j=0;j<X;j++){
                scanf("%d",&field[i][j]);
            }
        }

        for(int j=0;j<X;j++){
            dp[Y-1][j] = field[Y-1][j] == 1 ? 0 : 1;
        }

        for(int i=Y-2;i>=0;i--){
            for(int j=0;j<X;j++){
                if(field[i][j]==1){
                    dp[i][j] = 0;
                }else if(field[i][j]==2){
                    dp[i][j] = i+2<Y ? dp[i+2][j] : 1;
                }else{
                    dp[i][j] = 0;
                    if(j-1>=0 && field[i+1][j-1]==0){
                        dp[i][j] += dp[i+1][j-1];
                    }
                    if(j+1<X && field[i+1][j+1]==0){
                        dp[i][j] += dp[i+1][j+1];
                    }
                    if(field[i+1][j]!=1){
                        dp[i][j] += dp[i+1][j];
                    }
                }
            }
        }
        int ans = 0;
        for(int j=0;j<X;j++){
            ans += dp[0][j];
        }
        printf("%d\n",ans);
    }

    return 0;
}
