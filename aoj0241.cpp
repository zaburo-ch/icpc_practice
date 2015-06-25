#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
#include <complex>
using namespace std;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
struct edge{int to,cost;};

int b[50],r[50],t[50];
int y;

double motori(int i){
    if(t[i]==1){
        return (double)y*r[i]/100 + 1;
    }else{
        return pow(1+(double)r[i]/100, y);
    }
}
int main(){
    int n;
    while(cin >> n, n){
        for(int i=0;i<n;i++){
            int x1,y1,z1,w1,x2,y2,z2,w2;
            scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&w1,&x2,&y2,&z2,&w2);
            printf("%d %d %d %d\n", x1*x2-y1*y2-z1*z2-w1*w2, x1*y2+y1*x2+z1*w2-w1*z2, x1*z2-y1*w2+z1*x2+w1*y2, x1*w2+y1*z2-z1*y2+w1*x2);
        }
    }

    return 0;
}
