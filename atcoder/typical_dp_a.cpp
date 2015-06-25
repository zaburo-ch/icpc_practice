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
const int MAX_N = 100;
const int MAX_P = 100;

int main(){
    int N;
    int p[MAX_N];

    int p_sum = 0;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &p[i]);
        p_sum += p[i];
    }

    bool dp[MAX_N*MAX_P+1] = {0};
    dp[0] = true;
    for(int i=0;i<N;i++){
        for(int j=p_sum-p[i];j>=0;j--){
            if(dp[j]){
                dp[j+p[i]] = true;
            }
        }
    }

    int count = 0;
    for(int j=0;j<=p_sum;j++){
        if(dp[j]){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}