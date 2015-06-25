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
    string str[10] = {"0111111","0000110","1011011","1001111","1100110","1101101","1111101","0100111","1111111","1101111"};
    while(1){
        int n;
        scanf("%d",&n);
        if(n==-1)break;
        string cur = "0000000";
        for(int i=0;i<n;i++){
            int next;
            scanf("%d",&next);
            string ans = "0000000";
            for(int i=0;i<8;i++){
                if(cur[i]!=str[next][i]){
                    ans[i] = '1';
                }
            }
            cout << ans << endl;
            cur = str[next];
        }
    }

    return 0;
}
