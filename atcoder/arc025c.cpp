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
    int N, M, R, T;
    int adj_mat[10][10];

    scanf("%d %d %d %d", &N, &M, &R, &T);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) adj_mat[i][j] = INF;
    for(int i=0;i<M;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        adj_mat[a-1][b-1] = c;
        adj_mat[b-1][a-1] = c;
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k]+adj_mat[k][j]);
            }
        }
    }
    int count = 0;
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int c=0;c<N;c++){
                if (adj_mat[b][a]*T > adj_mat[c][a]*R){
                    count++;
                }
            }
        }
    }
    printf("%d\n",count);

    return 0;
}