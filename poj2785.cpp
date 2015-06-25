#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

#define MAX_N 4000

int n;
int a[MAX_N],b[MAX_N],c[MAX_N],d[MAX_N];
int cd[MAX_N*MAX_N];

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cd[i*n+j] = c[i] + d[j];
    }
  }

  sort(cd,cd+n*n);

  int res = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int ab = a[i] + b[j];
      res += upper_bound(cd,cd+n*n,-ab) - lower_bound(cd,cd+n*n,-ab);
    }
  }

  cout << res << endl;
}