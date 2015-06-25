#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

bool check(double x1,double y1,double x2,double y2){
  double gaiseki = (x1*y2-y1*x2);
  if(gaiseki>0){
    return gaiseki<(double)0.000005;
  }else{
    return gaiseki>(double)-0.000005;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if(check(x2-x1,y2-y1,x4-x3,y4-y3)){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}