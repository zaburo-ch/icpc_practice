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
const long long int MAX_N = 2000;

const long long int prime = 1000000007;

long long int calc(long long int a, int b){
    C(a+b-1, b-1);
}

int main(){
    int N;
    cin >> N;

    long long int A[2000];
    for (int i = 0; i < N; ++i){
        scanf("%lld", &A[i]);
    }

    long long int pascal[2000][2000];
    for(int i=0;i<2000;i++){
        for(int j=0;j<i+1;j++){
            if (j==0 || j==i){
                pascal[i][j] = 1;
            }else{
                pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) % prime;
            }
        }
    }

    long long int prev = A[0];
    int count = 0;
    long long int ans = 1;
    for(int i=1;i<N;i++){
        if (A[i] == -1){
            count++;
        }else{
            if (count>0){
                ans *= pascal[n+count-1][count-1]

                int n = A[i] - prev + 1;

                ans *= n;
                count = 0;
            }
            prev = A[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}