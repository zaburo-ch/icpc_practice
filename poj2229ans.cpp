#include <iostream>
#include <string.h>
using namespace std;

long long memo[1000020];

int main() {
  memset(memo, 0, sizeof(memo));
  int n;
  cin>>n;
  memo[0] = 0;
  memo[1] = 1;
  memo[2] = 2;
  for(int i=3; i<=1000000; ++i) {
    if(i%2) memo[i] = memo[i-1];
    else {
      memo[i] = (memo[i/2] + memo[i-2])%1000000000ll;
    }
  }
  cout<<memo[n]<<endl;
}

//http://d.hatena.ne.jp/h_chiro/20101116/1289922584