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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1);
const int MAX_N = 1000;
const long long int P = 1000000007;

int N;
vector<int> G[MAX_N];

int main(){
    cin >> N;

    for(int i=0;i<N-1;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i=0;i<N;i++){

    }

    return 0;
}