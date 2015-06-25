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


int main(){
    while(1){
        int L;
        scanf("%d",&L);
        if(L==0)break;

        int chokin = 0, ans = 0;
        for(int i=0;i<12;i++){
            int M,N;
            scanf("%d %d",&M,&N);
            if(ans)continue;
            chokin += M-N;
            if(L <= chokin) ans = i+1;
        }
        if(ans)cout << ans << endl;
        else cout << "NA" << endl;
    }

    return 0;
}
