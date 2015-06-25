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


int main(){
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int cum_sum[26][100000];

    // input: make cumulative sum array
    for(int i=0;i<N;i++){
        if (i){
            for(int j=0;j<26;j++){
                cum_sum[j][i] = cum_sum[j][i-1];
            }
        }else{
            for(int j=0;j<26;j++){
                cum_sum[j][0] = 0;
            }
        }
        cum_sum[(int)(S[i]-'a')][i]++;
    }
    for(int i=0;i<N-2*K+1;i++){
        for(int j=i+K;j<N-K+1;j++){
            bool match_all = true;
            for(int k=0;k<26;k++){
                int right = cum_sum[k][j+K-1]-cum_sum[k][j-1];
                int left = cum_sum[k][i+K-1];
                if (i) left -= cum_sum[k][i-1];
                if (left != right){
                    match_all = false;
                    break;
                }
            }
            if(match_all){
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}