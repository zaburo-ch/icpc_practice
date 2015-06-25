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


int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n) break;

        for(int i=0;i<n;i++){
            int pm,pe,pj;
            scanf("%d%d%d",&pm,&pe,&pj);
            int ave = (pm+pe+pj)/3;
            if((pm==100||pe==100||pj==100) || (pm+pe)/2>=90 || ave>=80){
                cout << "A" << endl;
            }else if(ave>=70 || (ave>=50&&(pm>=80||pe>=80))){
                cout << "B" << endl;
            }else{
                cout << "C" << endl;
            }
        }
    }

    return 0;
}
