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
typedef vector<vec> mat;
typedef pair<int,int> P;
struct edge{int to,cost;};

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int main(){
    int n;
    while(cin >> n, n){
        vec seed(n+1);
        for(int i=0;i<n+1;i++){
            cin >> seed[i];
        }
        for(int i=0;i<n+1;i++){
            vec cpy_seed = seed;
            cpy_seed.erase(cpy_seed.begin()+i);
            for(int j=n;j>=1;j--){
                cpy_seed[j] -= cpy_seed[j-1];
            }
            set<int> s(cpy_seed.begin()+1, cpy_seed.end());
            if(s.size()==1){
                cout << seed[i] << endl;
                break;
            }
        }
    }
    return 0;
}
