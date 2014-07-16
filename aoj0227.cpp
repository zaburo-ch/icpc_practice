#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int n,m;
int p[1000];


int main(){
  while(1){
    cin >> n >> m;
    if(!n&&!m){
      return 0;
    }
    for(int i=0;i<n;i++){
      cin >> p[i];
    }
    sort(p,p+n);
    int sum=0;
    for(int i=1;i<=n;i++){
      if(i%m!=0){
        sum += p[n-i];
      }
    }
    cout << sum << endl;
  }
}