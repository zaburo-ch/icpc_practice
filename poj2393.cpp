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

#define N_MAX 10000
int c[N_MAX];
int y[N_MAX];
int n,s;

int main(){
  scanf("%d%d",&n,&s);
  for(int i=0;i<n;i++){
    scanf("%d%d",&c[i],&y[i]);
  }

  long long int cost = c[0];
  long long int total = cost * y[0];
  for(int i=1;i<n;i++){
    cost = min(cost+s,(long long int)c[i]);
    total += cost * y[i];
  }

  cout << total << endl;

  return 0;
}