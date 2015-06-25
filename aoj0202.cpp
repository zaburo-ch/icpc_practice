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

bool is_prime[1000001];
int max_able_num[1000001];
int max_able_prime[1000001];
int price[30];

int main(){
    is_prime[1] = false; is_prime[0] = false;
    fill(is_prime,is_prime+1000001,true);
    for(int i=2;i<=1000000;i++){
        if(is_prime[i]){
            for(int j=2;j*i<=1000000;j++){
                is_prime[j*i] = false;
            }
        }
    }

    while(1){
        int n, x;
        scanf("%d %d",&n,&x);
        if(n==0) break;

        for(int i=0;i<n;i++){
            scanf("%d",&price[i]);
        }

        fill(max_able_num,max_able_num+x+1,-1);
        max_able_num[0] = 0;
        for(int i=0;i<=x;i++){
            if(max_able_num[i]>=0){
                for(int j=0;j<n;j++){
                    if(i+price[j]<=x){
                        max_able_num[i+price[j]] = i+price[j];
                    }
                }
            }else{
                max_able_num[i] = max_able_num[i-1];
            }
            //printf("%d %d\n",i,max_able_num[i]);
        }
        max_able_prime[0] = 0;
        for(int i=1;i<=x;i++){
            if(is_prime[max_able_num[i]]){
                max_able_prime[i] = max_able_num[i];
            }else{
                max_able_prime[i] = max_able_prime[i-1];
            }
            //printf("%d %d\n",i,max_able_prime[i]);
        }
        if(max_able_prime[x])cout << max_able_prime[x] << endl;
        else cout << "NA" << endl;
    }
    return 0;
}
