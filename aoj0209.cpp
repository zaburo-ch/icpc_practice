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
typedef pair<int,int> P;
const int INF = 1<<29;

int view[100][100];
int photo[4][50][50];

int main(){
    while(1){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0)break;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&view[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&photo[0][i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                photo[1][j][m-1-i] = photo[0][i][j];
                photo[2][m-1-i][m-1-j] = photo[0][i][j];
                photo[3][m-1-j][i] = photo[0][i][j];
            }
        }

        int ansx = 0, ansy = 0;
        for(int i=0;i+m-1<n;i++){
            for(int j=0;j+m-1<n;j++){
                for(int k=0;k<4;k++){
                    bool is_same = true;
                    for(int pi=0;pi<m;pi++){
                        for(int pj=0;pj<m;pj++){
                            if(photo[k][pi][pj]!=-1 && view[i+pi][j+pj]!=photo[k][pi][pj]){
                                is_same = false;
                                break;
                            }
                        }
                        if(!is_same)break;
                    }
                    if(is_same){
                        for(int pi=0;pi<m;pi++){
                            for(int pj=0;pj<m;pj++){
                                if(photo[k][pi][pj]!=-1){
                                    ansy = i+pi+1; ansx = j+pj+1;
                                    break;
                                }
                            }
                            if(ansx)break;
                        }
                        break;
                    }
                }
                if(ansx)break;
            }
            if(ansx)break;
        }
        if(ansx) printf("%d %d\n",ansx,ansy);
        else printf("NA\n");
    }

    return 0;
}
