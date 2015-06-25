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
  int h,m;
  scanf("%d%d",&h,&m);

  printf("%d\n",(17-h)*60+(60-m));
  return 0;
}