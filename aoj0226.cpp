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

int main(){
    while(1){
        string r,a;
        cin >> r >> a;
        if(r=="0")break;

        int hit = 0, blow = 0;
        for(int i=0;i<4;i++){
            if(r[i]==a[i]){
                r[i] = '-';
                a[i] = '-';
                hit += 1;
            }
        }
        for(int i=0;i<4;i++){
            if(r[i]=='-')continue;
            for(int j=0;j<4;j++){
                if(r[i]==a[j]){
                    blow += 1;
                    break;
                }
            }
        }
        cout << hit << " " << blow << endl;
    }

    return 0;
}
