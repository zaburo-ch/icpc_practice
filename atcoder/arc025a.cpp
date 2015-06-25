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


int main(){
    int D[7],J[7];
    for(int i=0;i<7;i++){
        cin >> D[i];
    }
    for(int i=0;i<7;i++){
        cin >> J[i];
    }
    int sum = 0;
    for(int i=0;i<7;i++){
        sum += max(J[i],D[i]);
    }
    cout << sum << endl;
}