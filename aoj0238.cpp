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
    int t;
    while(cin >> t, t){
        int n;
        cin >> n;
        int sum = 0;
        for(int i=0;i<n;i++){
            int s,f;
            cin >> s >> f;
            sum += f-s;
        }
        if(sum<t) cout << t-sum << endl;
        else cout << "OK" << endl;
    }

    return 0;
}
