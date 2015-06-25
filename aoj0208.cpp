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
typedef pair<int,int> P;
const int INF = 1<<29;

int eight[] = {0,1,2,3,5,7,8,9};

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;

        vector<int> ans;
        while(n){
            int a = n&7;
            ans.push_back(eight[a]);
            n >>= 3;
        }
        for(int i=ans.size()-1;i>=0;i--){
            printf("%d",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
