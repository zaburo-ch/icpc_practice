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


int main(){
    while(1){
        string input;
        cin >> input;
        if(input[0]=='-')break;

        int dot_i;
        for(int i=0;i<input.size();i++){
            if(input[i]=='.'){
                dot_i = i;
                break;
            }
        }

        int p=1, a=0, b=0;
        for(int i=dot_i-1;i>=0;i--){
            a += (input[i]-'0') * p;
            p *= 10;
        }
        p = 1000;
        for(int i=dot_i+1;i<input.size();i++){
            b += (input[i]-'0') * p;
            p /= 10;
        }

        string a_str = "00000000", b_str = "0000";
        for(int i=0;i<8&&a>0;i++){
            a_str[7-i] += a&1;
            a >>= 1;
        }
        p = 5000;
        for(int i=0;i<4&&b>0;i++){
            b_str[i] += b / p;
            b %= p;
            p /= 2;
        }

        if (a>0||b>0){
            cout << "NA" << endl;
        }else{
            cout << a_str << "." << b_str << endl;
        }
    }

    return 0;
}
