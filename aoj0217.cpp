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

        vector<P> patients(n);
        for(int i=0;i<n;i++){
            int p,d1,d2;
            scanf("%d%d%d",&p,&d1,&d2);
            patients[i] = P(d1+d2,p);
        }
        sort(patients.begin(),patients.end());
        cout << patients[n-1].second << " " << patients[n-1].first << endl;
    }

    return 0;
}
