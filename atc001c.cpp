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

const int MAX_N = 100000;
int A[MAX_N],B[MAX_N];

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }
    sort(A,A+N);
    int ans = 0;
    for(int i=0;i<N;i++){
        int a = upper_bound(A,A+N,B[i])-lower_bound(A,A+N,B[i])
        ans += a;
        cout << a << endl;
    }
    return 0;
}

