#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;

int main(){
  int N;
  cin >> N;

  double maxValue=0;
  for(int i=0;i<N;i++){
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    double v = a+b+c+d+(double)e*110/900;
    if(maxValue<v){
      maxValue = v;
    }
  }
  printf("%.7f\n",maxValue);
}