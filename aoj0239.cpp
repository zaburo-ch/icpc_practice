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

int i[1000],p[1000],q[1000],r[1000];

int main(){
    int n;
    while(cin >> n, n){
        for(int j=0;j<n;j++){
            cin >> i[j] >> p[j] >> q[j] >> r[j];
        }
        bool is_na = true;
        int P, Q, R, C;
        cin >> P >> Q >> R >> C;
        for(int j=0;j<n;j++){
            int c = 4*(p[j]+r[j])+9*q[j];
            if(p[j]<=P&&q[j]<=Q&&r[j]<=R&&c<=C){
                is_na = false;
                cout << i[j] << endl;
            }
        }
        if(is_na) cout << "NA" << endl;
    }

    return 0;
}
