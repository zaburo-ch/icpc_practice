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

struct edge{int to,d,c};

vector<vector<edge> > G;
int price[20][201];

int main(){
    while(1){
        int n,m,c,s,g;
        cin >>n>>m>>c>>s>>g;
        if (n==0)break;

        G.clear();
        G.resize(n);
        for(int i=0;i<c;i++)for(int j=0;j<201;j++) price[i][j] = 0;

        for(int i=0;i<m;i++){
            int x,y,d,ci;
            scanf("%d %d %d %d",&x,&y,&d,&ci);
            x--;y--;
            G[x].push_back((edge){y,d,ci});
            G[y].push_back((edge){x,d,ci});
        }
        for(int i=0;i<c;i++){

        }
    }
    return 0;
}