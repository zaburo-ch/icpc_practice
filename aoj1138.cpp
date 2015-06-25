#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

vector< vector<int> > dist;//道のりvectorが入っているvector
int n,m,p,a,b;
int t[8];
int map[30][30];
bool dp[30];

void rec(vector<int> vec,int pos){
  if(pos==b){
    dist.push_back(vec);
  }else if(vec.size()!=n){
    for(int j=0;j<m;j++){
      if(map[pos][j]!=0 && !dp[j]){
        vec.push_back(map[pos][j]);
        dp[j] = true;
        rec(vec,j);
        vec.erase(vec.end()-1);
        dp[j] = false;
      }
    }
  }
  return;
}

int main(){
  while(1){
    cin >> n >> m >> p >> a >> b;
    if(!n&&!m&&!p&&!a&&!b) break;
    for(int i=0;i<n;i++){
      scanf("%d",&t[i]);
    }
    a--;
    b--;
    memset(map,0,sizeof(map));
    for(int i=0;i<p;i++){
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      map[x-1][y-1] = z;
      map[y-1][x-1] = z;
    }

    fill(dp,dp+m,false);
    vector<int> first;
    rec(first,a);

    sort(t,t+n);
    if(dist.size()){
      double min = 10000000;
      for(int i=0;i<dist.size();i++){
        double sum = 0;
        sort(dist[i].begin(),dist[i].end());
        for(int j=0;j<dist[i].size();j++){
          //printf("t[%d]=%d\n",n-1-j,t[n-1-j]);
          sum += (double)dist[i][dist[i].size()-1-j] / t[n-1-j];
        }
        if(sum<min){
          min = sum;
        }
      }
      printf("%lf\n",min);
    }else{
      cout << "Impossible" << endl;
    }
    dist.clear();
  }
}