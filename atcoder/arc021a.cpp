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
const int INF = (int)((unsigned int)-1>>1);


int main(){
    int tile[4][4];
    const int dx[] = {0,0,1,-1};
    const int dy[] = {1,-1,0,0};
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)cin >> tile[i][j];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int nextx = i+dx[k], nexty = j+dy[k];
                if (0<=nextx && nextx<4 && 0<=nexty && nexty<4){
                    if (tile[i][j]==tile[nextx][nexty]){
                        cout << "CONTINUE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "GAMEOVER" << endl;
    return 0;
}