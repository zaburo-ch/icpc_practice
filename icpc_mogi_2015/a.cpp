#include <iostream>
#include <stdio.h>
#include <cmath>
#include <utility>
using namespace std;

int main(){
    while(1){
        int D,E;
        cin >> D >> E;
        if(!D)break;
        double ans = 10000000;
        for(int x=0;x<=D;x++){
            int y = D - x;
            double _ans = abs(sqrt(x*x+y*y)-E);
            ans = min(ans, _ans);
        }
        printf("%.5lf\n",ans);
    }
}