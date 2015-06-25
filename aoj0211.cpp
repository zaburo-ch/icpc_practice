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

int d[10],v[10];
int x[9],y[9];

int gcd(int x, int y){
    return y ? gcd(y, x%y): x;
}

int lca(int x, int y){
    long long int mul = (long long int)x*y;
    return mul/gcd(x,y);
}

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;

        for(int i=0;i<n;i++){
            scanf("%d%d",&d[i],&v[i]);
        }

        for(int i=0;i<n-1;i++){
            x[i] = d[i+1]*v[0];
            y[i] = d[0]*v[i+1];
            int g = gcd(x[i],y[i]);
            x[i] /= g;
            y[i] /= g;
            //cout << x[i] << " " << y[i] << endl;
        }

        if(n>2){
            int l = 1;
            for(int i=0;i<n-1;i++){
                l = lca(l, x[i]);
            }
            cout << l << endl;
            for(int i=0;i<n-1;i++){
                cout << l / x[i] * y[i] << endl;
            }
        }else{
            cout << x[0] << endl;
            cout << y[0] << endl;
        }

    }

    return 0;
}
