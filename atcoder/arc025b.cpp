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


int main(){
    int H,W;
    int C[100][100];

    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int temp;
            cin >> temp;
            C[i][j] = ( -1+2*((i+j)%2) ) * temp;
        }
    }

    int p_sum[100][100];
    for(int i=0;i<H;i++){
        p_sum[i][0] = C[i][0];
        for(int j=1;j<W;j++){
            p_sum[i][j] = p_sum[i][j-1] + C[i][j];
        }
    }

    int ans = 0;
    for(int k=1;k<=H;k++){
        for(int l=1;l<=W;l++){
            if(ans >= k*l) continue;
            bool ans_change = false;
            for(int i=0;i<H-k+1;i++){
                for(int j=0;j<W-l+1;j++){
                    int sum = 0;
                    for(int m=i;m<i+k;m++){
                        if(j){
                            sum += p_sum[m][j+l-1] - p_sum[m][j-1];
                        }else{
                            sum += p_sum[m][l-1];
                        }
                    }
                    //printf("%d %d %d %d %d\n",k,l,i,j,sum);
                    if(sum == 0){
                        ans = k*l;
                        ans_change = true;
                    }
                }
                if(ans_change) break;
            }
        }
    }
    cout << ans << endl;
}