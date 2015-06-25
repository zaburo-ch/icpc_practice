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
const int MAX_N = 5000;


int main(){
    int R, C, D;
    cin >> R >> C >> D;

    vector<P> square;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            int a_ij;
            cin >> a_ij;
            square.push_back(P(a_ij, i+j));
        }
    }
    sort(square.begin(), square.end(), greater<P>());

    for(int i=0;i<square.size();i++){
        int d = square[i].second;
        if (d <= D && (D - d)%2 == 0){
            cout << square[i].first << endl;
            break;
        }
    }

    return 0;
}