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
    int y, m, d;
    cin >> y >> m >> d;
    //735369
    if (m <= 2){
        m += 12;
        y -= 1;
    }
    int days = 365*y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d - 429;
    cout << 735369-days << endl;
    return 0;
}