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

int p[65000], j[65000-1];

int main(){
    int n;
    while(cin >> n, n){
        long long int sum_p = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
            sum_p += p[i];
        }
        for(int i=0;i<n-1;i++){
            scanf("%d",&j[i]);
        }
        long long int ans = n * sum_p;
        sort(j,j+n-1);
        for(int i=n-2;i>=0;i--){
            sum_p += j[i];
            n--;
            long long int temp = n * sum_p;
            if(ans <= temp){
                ans = temp;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
