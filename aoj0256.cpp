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
    int a,b,c;
    cin >> a >> b >> c;
    if((a&&b&&!c)||(!a&&!b&&c)){
        cout << "Open" << endl;
    }else{
        cout << "Close" << endl;
    }
    return 0;
}
