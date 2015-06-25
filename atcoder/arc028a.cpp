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
  N%=(A+B);
  if(N!=0&&N<=A) printf("Ant\n");
  else printf("Bug\n");
  return 0;
}