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
const int MAX_N = 100000;

int main(){
    int N;
    int A[MAX_N];

    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }

    int i = 1, j = 0;
    int ans = 1;
    set<int> s;
    s.insert(A[0]);
    while(i<N){
        if (s.count(A[i]) == 0){
            ans = max(ans, i+1-j);
            //cout << "add "<< A[i] << " " << ans << endl;
            s.insert(A[i]);
            i++;
        }else{
            //cout << "erase " << A[j] << endl;
            s.erase(A[j]);
            j++;
        }
    }
    printf("%d\n", ans);

    return 0;
}