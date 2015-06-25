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

//C++は負の余りを正に直してくれない

const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
struct edge{int to,cost;};

int imod(int i, int j){
  return i % j + (i % j < 0 ? j : 0);
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(!n) break;

        vector<int> ans;
        while(n!=0){
            ans.push_back(imod(n, 10));
            n -= imod(n, 10);
            n /= -10;
        }
        for(int i=ans.size()-1;i>=0;i--)cout << ans[i];
        cout << endl;
    }

    return 0;
}
