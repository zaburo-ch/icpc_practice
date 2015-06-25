#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int main(){
  int coinc[6];
  const int coinv[] = {1,5,10,50,100,500};
  int a,ans=0;

  for(int i=0;i<6;i++){
    cin >> coinc[i];
  }
  cin >> a;
  for(int i=5;i>=0;i--){
    coinc[i] = min(a/coinv[i],coinc[i]);
    a -= coinc[i]*coinv[i];
    ans += coinc[i];
  }

  cout << ans << endl;

}