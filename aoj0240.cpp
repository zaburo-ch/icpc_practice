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
        cin >> y;
        for(int i=0;i<n;i++){
            cin >> b[i] >> r[i] >> t[i];
        }

        int max_i = 0;
        double max_m = motori(0);
        for(int i=1;i<n;i++){
            double m = motori(i);
            if(m>max_m){
                max_i = i;
                max_m = m;
            }
        }
        cout << b[max_i] << endl;
    }

    return 0;
}
