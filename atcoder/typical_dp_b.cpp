#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1) /2;
const int MAX_AB = 1000;


int A, B;
int a[MAX_AB], b[MAX_AB];
int dp[MAX_AB+1][MAX_AB+1];

// 1 <= a_i, b_i <= A
int dfs(int a_i, int b_i){
    if (dp[a_i][b_i]>=0) return dp[a_i][b_i];
    if ((A+B-a_i-b_i)%2==0){
        //sunuke's turn
        if (a_i == 0){
            dp[a_i][b_i] = b[B-b_i]+dfs(a_i, b_i-1);
        }else if (b_i == 0){
            dp[a_i][b_i] = a[A-a_i]+dfs(a_i-1, b_i);
        }else{
            dp[a_i][b_i] = max(a[A-a_i]+dfs(a_i-1, b_i), b[B-b_i]+dfs(a_i, b_i-1));
        }
    }else{
        //sumeke's turn
        if (a_i == 0){
            dp[a_i][b_i] = dfs(a_i, b_i-1);
        }else if (b_i == 0){
            dp[a_i][b_i] = dfs(a_i-1, b_i);
        }else{
            dp[a_i][b_i] = min(dfs(a_i-1, b_i), dfs(a_i, b_i-1));
        }
    }
    return dp[a_i][b_i];
}

int main(){
    scanf("%d %d", &A, &B);
    for(int i=0;i<A;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<B;i++){
        scanf("%d", &b[i]);
    }

    for(int i=0;i<=A;i++)for(int j=0;j<=B;j++) dp[i][j] = -1;
    dp[0][0] = 0;

    cout << dfs(A, B) << endl;

    return 0;
}