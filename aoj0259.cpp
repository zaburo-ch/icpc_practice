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
typedef vector<vec> mat;
typedef pair<int,int> P;
struct edge{int to,cost;};

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};



int main(){
    string N;
    while(cin >> N, N != "0000"){
        if(N=="0000"||N=="1111"||N=="2222"||N=="3333"||N=="4444"||N=="5555"||N=="6666"||N=="7777"||N=="8888"||N=="9999"){
            cout << "NA" << endl;
            continue;
        }else if(N=="6174"){
            cout << 0 << endl;
            continue;
        }
        vec Nv(4);
        for(int i=0;i<4;i++){
            Nv[i] = N[i]-'0';
        }
        int t = 0;
        while(1){
            t++;
            sort(Nv.begin(), Nv.end());
            int l=0, s=0, p=1;
            for(int i=0;i<4;i++){
                l += Nv[i]*p;
                s += Nv[i]*1000/p;
                p *= 10;
            }
            int sub = l - s;
            if(sub == 6174) break;
            p = 1000;
            for(int i=0;i<4;i++){
                Nv[i] = (sub/p)%10;
                p /= 10;
            }
        }
        cout << t << endl;
    }
    return 0;
}
