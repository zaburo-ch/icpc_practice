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

bool is_prime[10000001];

int main(){
    fill(is_prime,is_prime+10000001,true);
    is_prime[0] = false; is_prime[1] = false;
    for(int i=2;i<10000001;i++){
        if(is_prime[i]){
            for(int j=2*i;j<10000001;j+=i){
                is_prime[j] = false;
            }
        }
    }

    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;

        while(1){
            if(is_prime[n]&&is_prime[n-2]&&is_prime[n-6]&&is_prime[n-8]){
                cout << n << endl;
                break;
            }
            n--;
        }
    }

    return 0;
}
