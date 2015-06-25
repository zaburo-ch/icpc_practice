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

int N,K;
int A[6];
int ans = INF;
bool used[6];

void dfs(int pos,int v){
    if(pos==N){
        ans = min(ans,abs(v-K));
    }
    if (pos==0){
        for(int i=0;i<N;i++){
            used[i] = true;
            dfs(pos+1,A[i]);
            used[i] = false;
        }
    }else{
        for(int i=0;i<N;i++){
            if(!used[i]){
                used[i] = true;
                dfs(pos+1,v+A[i]);
                dfs(pos+1,v*A[i]);
                used[i] = false;
            }
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    fill(used,used+N,false);
    dfs(0,0);
    cout << ans << endl;
    return 0;
}