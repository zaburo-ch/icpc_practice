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
using namespace std;
typedef pair<int,int> P;
const int INF = ~(1<<31) / 2;

int main(){
    int k;
    cin >> k;
    for(int j=0;j<k;j++){
        int n[80];
        string a,b;
        cin >> a >> b;
        int n_a = a.size(),n_b = b.size();
        if(n_a>80||n_b>80){cout << "overflow" << endl;continue;}

        fill(n,n+80,0);
        bool is_over = false;
        for(int i=0;i<max(n_a,n_b);i++){
            int ai,bi;
            if (i<n_a) ai = a[n_a-i-1]-'0';
            else ai = 0;
            if (i<n_b) bi = b[n_b-i-1]-'0';
            else bi = 0;
            n[i] += ai + bi;
            if (n[i]>=10){
                if(i+1 == 80){
                    is_over = true;
                    break;
                }else{
                    n[i+1] += n[i]/10;
                    n[i] = n[i]%10;
                }
            }
        }
        if (is_over){
            cout << "overflow" << endl;
        }else{
            bool started = false;
            for(int i=79;i>=0;i--){
                if(!started && n[i]>0){
                    started = true;
                }
                if(started || (!started&&i==0)){
                    cout << n[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}