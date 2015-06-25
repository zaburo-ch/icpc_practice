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
        if(!n)break;

        vector<int> num(10,0);
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            num[t]+=1;
        }
        for(int i=0;i<10;i++){
            if(num[i]>0){
                for(int j=0;j<num[i];j++){
                    printf("*");
                }
                printf("\n");
            }else{
                cout << "-" << endl;
            }
        }
    }

    return 0;
}
