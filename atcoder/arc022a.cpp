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
    string x, y;
    cin >> x;
    y = "";
    for(int i=0;i<x.size();i++){
        if (x[i] == 'I' || x[i] == 'i'){
            y.push_back('i');
        }else if (x[i] == 'C' || x[i] == 'c'){
            y.push_back('c');
        }else if (x[i] == 'T' || x[i] == 't'){
            y.push_back('t');
        }
    }
    for(int i=0;i+2<y.size();i++){
        for(int j=i+1;j+1<y.size();j++){
            for(int k=j+1;k<y.size();k++){
                if (y[i]=='i' && y[j]=='c' && y[k]=='t'){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}