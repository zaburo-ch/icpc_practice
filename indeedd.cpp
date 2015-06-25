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
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

int main(){
    int N;
    cin >> N;
    double sum1=1, sum2=2, ans;
    for(int i=3;i<=N;i++){
        ans = (2*sum1/i) + 1;
        sum1 = sum2;
        sum2 = sum1+ans;
    }
    printf("%.8lf\n",ans);
    return 0;
}