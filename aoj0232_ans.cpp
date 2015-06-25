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
const double EPS = 1e-5;
typedef vector<int> vec;
typedef pair<int,int> P;
struct edge{int to,cost;};

const int MAX_J = 5001;

int X,Y,Z;
double dp[51][MAX_J];
int V[4];
int event[51], event_A[51];

int main(){
    while(1){
        scanf("%d%d%d",&X,&Y,&Z);
        if(!X)break;

        for(int i = 0; i < X; i++){
            scanf("%d",&V[i]);
        }
        fill(event, event+Y+1, 0);
        for(int i=0;i<Z;i++){
            int N,E,A;
            scanf("%d%d%d",&N,&E,&A);
            event[N] = E;
            event_A[N] = A;
        }
        for(int i=0;i<Y+1;i++){
            for(int j=0;j<MAX_J;j++){
                dp[i][j] = 0;
            }
        }

        dp[0][0] = 1;
        for(int i=0;i<Y;i++){
            for(int j=0;j<MAX_J;j++){
                for(int k=0;k<X;k++){
                    int ni = min(Y, i + V[k]), nj = j;
                    if(event[ni] == 2) nj += event_A[ni];
                    else if(event[ni] == 3) nj = max(0, j-event_A[ni]);
                    else if(event[ni] == 1) ni = min(Y, ni + event_A[ni]);
                    dp[ni][nj] += dp[i][j] / X;
                }
            }
        }
        double ans = 0;
        for(int j=1;j<MAX_J;j++){
            ans += j*dp[Y][j];
        }
        printf("%d\n", (int)(ans+EPS));
    }
    return 0;
}