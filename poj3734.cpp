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
const int INF = ~(1<<31) / 2;

const int M = 10007;

typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size(),0));

    for(int i=0;i<C.size();i++){
        for(int j=0;j<C[0].size();j++){
            for(int k=0;k<B.size();k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= M;
            }
        }
    }
    return C;
}

mat pow(mat &A, int n){
    mat B(A.size(), vec(A.size(),0));
    for(int i=0;i<A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        mat A(3, vec(3));
        A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
        A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;
        A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;
        A = pow(A, N);
        printf("%d\n", A[0][0]);
    }

    return 0;
}