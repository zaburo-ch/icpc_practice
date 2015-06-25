#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

//入力関係
static const int N = 1000000;
static char _buf[10*N];
int read_int(){
    static unsigned long long int c=0;
    int r=0;
    while( _buf[c] >= '0' && _buf[c] <= '9' ){
        r = r*10 + _buf[c++]-'0';
    }
    c++;
    return r;
}

int n,t;
vector<P> cows;

int main(){
  fread(_buf,1,sizeof(_buf),stdin);

  n = read_int();
  t = read_int();
  for(int i=0;i<n;i++){
    cows.push_back(P(read_int(),read_int()));
  }
  sort(cows.begin(),cows.end());
/*
  for(int i=0;i<n;i++){
    cout << cows[i].first << " " << cows[i].second << endl;
  }
*/
  int sum = 0;
  int start=1;
  int endM = 0;
  int conFlag = 0;
  for(int i=0;i<n;i++){
    if(cows[i].first<=start){
      if(endM<cows[i].second){
        conFlag = 1;
        endM = cows[i].second;
        if(endM>=t){
          cout << sum+1 << endl;
          return 0;
        }
      }
    }else{
      if(conFlag){
        start = endM;
        sum++;
        i--;
        conFlag = 0;
      }else{
        break;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}