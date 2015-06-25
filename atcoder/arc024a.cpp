#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1) /2;


int main(){
    int L, R;
    int l[31], r[31];
    cin >> L >> R;

    fill(l, l+31, 0);
    fill(r, r+31, 0);
    for(int i=0;i<L;i++){
        int temp;
        cin >> temp;
        l[temp-10]++;
    }
    for(int i=0;i<R;i++){
        int temp;
        cin >> temp;
        r[temp-10]++;
    }

    int ans = 0;
    for(int i=0;i<31;i++){
        ans += min(l[i],r[i]);
    }
    cout << ans << endl;

    return 0;
}