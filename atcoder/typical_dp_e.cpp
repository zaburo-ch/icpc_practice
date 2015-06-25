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
const int MAX_N = 100;
const long long int P = 1000000007;

//dp[pos][sum][sml] := pos桁目まで見たとき、各桁の和modPがsumで、与えられた数より小さいかどうか(sml) であるような数の個数

//
long long int dp[10001];

int main(){
    int D;
    string N;
    cin >> D >> N;
    int sum = (int)(N[0]-'0')
    dp[0] = sum / D;
    for(int i=1;i<N.size();i++){
        sum += (int)(N[i]-'0');

    }
    return 0;
}