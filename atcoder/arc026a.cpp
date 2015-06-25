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
  int N,A,B;
  scanf("%d%d%d",&N,&A,&B);

  if(N>=5){
    printf("%d\n",5*B+(N-5)*A);
  }else{
    printf("%d\n",N*B);
  }
  return 0;
}