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
  long long int N;
  cin >> N;

  int rank;
  for(rank=1;rank<=18;rank++){
    long long int maxValue = 9*rank;
    long long int power = 1;
    for(int i=0;i<rank;i++){
      maxValue += 9*power;
      power*=10;
    }
    if(N<maxValue){
      long long int margin = (maxValue - N)/2;

    }
  }
  return 0;
}