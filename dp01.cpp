#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int n,W;
int w[100];
int v[100];
int dp[100+1][10000+1];

int rec(int no,int wt);

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> w[i] >> v[i];
  }
  cin >> W;
  memset(dp,-1,sizeof(dp));
  cout << rec(0,W) << endl;
}

//no番目以降の品物を総重量wt以下で選んだときの価値の最大を返す
int rec(int no,int wt){
  if(dp[no][wt]>=0){
    return dp[no][wt];
  }
  int res;
  if(no==n){
    res = 0;
  }else if(wt<w[no]){
    res = rec(no+1,wt);
  }else{
    res = max(rec(no+1,wt),v[no]+rec(no+1,wt-w[no]));
  }
  dp[no][wt] = res;
  return res;
}