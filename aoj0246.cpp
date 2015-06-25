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

int n;
int m[100];

int main(){
    while(cin >> n, n){
        for(int i=0;i<n;i++){
            scanf("%d",&m[i]);
        }
        //i番目のまんじゅうまで使って、余ってる重さの合計がj
        int dp[101][10];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][j]
            for(int j=0;j<10;j++){
                dp[i][j]
                if(j-m[i-1]<0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][10+j-m[i-1]]+1);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-m[i-1]]);
                }
            }
        }
    }

    return 0;
}
