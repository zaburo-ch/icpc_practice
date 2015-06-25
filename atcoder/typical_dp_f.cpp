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
const int MAX_N = 1000000;
const long long int P = 1000000007;

int N, K;
//int dp[2][MAX_K];

//i番目の駅に止まり、i+1番目に止まらないような電車の止まり方の場合の数をdp[i]とする。
int dp[MAX_N]

int main(){
    cin >> N >> K;
    int cur = 0, next = 1;
    dp[0][0] = 1;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<K;j++) dp[next][j] = 1;
        for(int j=0;j<K;j++){
            if(j+1<K) dp[next][j+1] *= dp[cur][j];
            dp[next][0] *= dp[cur][j];
        }
    }




    return 0;
}