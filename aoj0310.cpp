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


//TLE

int p[300][300];
int yoko[300][300];
int tate[300][300];


int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&p[i][j]);
            yoko[i][j] = p[i][j];
            if(j!=0) yoko[i][j] += yoko[i][j-1];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tate[j][i] = p[j][i];
            if(j!=0) tate[j][i] += tate[j-1][i];
        }
    }

    int ans = -INF;
    for(int h=0;h<N;h++){
        for(int i=0;i<N;i++){
            for(int j=0;j+h<N;j++){
                for(int k=0;k+i<N;k++){
                    int frame = 0;
                    if (h==0){
                        frame = yoko[j][k+i];
                        if(k>0) frame -= yoko[j][k-1];
                    }else if(i==0){
                        frame = tate[j+h][k];
                        if(j>0) frame -= yoko[j-1][k];
                    }else{
                        frame = yoko[j][k+i]+yoko[j+h][k+i]+tate[j+h][k]+tate[j+h][k+i] -p[j][k]-p[j+h][k]-p[j][k+i]-p[j+h][k+i];
                        //printf("%d %d %d %d %d %d %d %d\n",yoko[j][k+i],yoko[j+h][k+i],tate[j+h][k],tate[j+h][k+i],p[j][k],p[j+h][k],p[j][k+i],p[j+h][k+i]);
                        if(k>0) frame -= yoko[j][k-1] + yoko[j+h][k-1];
                        if(j>0) frame -= tate[j-1][k] + tate[j-1][k+i];
                    }
                    //printf("%d %d %d %d\n",i,j,k,frame);
                    ans = max(ans, frame);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}