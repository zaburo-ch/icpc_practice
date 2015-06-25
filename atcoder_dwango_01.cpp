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
#include <math.h>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int factorial(int n) {
    if (n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int f[101];

double com(int n,int m){
  return (double)f[n]/(f[m]*f[n-m]);
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<=100;i++){
    f[i] = factorial(i);
  }
  double turn[100+1];
  fill(turn,turn+101,0);
  turn[1] = 0;
  turn[2] = 1;
  for(int i=3;i<=n;i++){
    double a = 1;
    for(int j=1;j<i;j++){
      double b = com(i,j)*3/pow(3,i);
      a-=b;
      turn[i] += turn[j]*b;
    }
    double c = turn[i];
    for(int j=0;j<100;j++){
      turn[i] += c*a;
      a*=a;
    }
  }
  cout << turn[n] << endl;
  return 0;
}