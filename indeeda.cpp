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

bool used[100];

int main(){
    string S;
    cin >> S;
    fill(used,used+S.size(),true);
    for(int i=0;i+1<S.size();i++){
        if(S[i]=='r' && S[i+1]=='a'){
            used[i] = false;
            used[i+1] = false;
            i++;
        }
    }
    for(int i=0;i<S.size();i++){
        if (used[i]) cout << S[i];
    }
    cout << endl;
    return 0;
}