#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int n;
int ba[10];

bool all(int,int,int);

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      cin >> ba[j];
    }
    if(all(0,0,0)){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}

bool all(int end,int l,int r){
  if(end==10){
    return true;
  }
  if(ba[end]>l){
    return all(end+1,ba[end],r);
  }
  if(ba[end]>r){
    return all(end+1,l,ba[end]);
  }
  return false;
}
