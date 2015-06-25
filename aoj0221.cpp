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

string itos(int t){
    string ret = "";
    stack<int> v;
    while(t>0){
        v.push(t%10);
        t /= 10;
    }
    while(v.size()){
        ret.push_back(v.top()+'0'); v.pop();
    }
    return ret;
}

int main(){
    while(1){
        int m,n;
        scanf("%d%d",&m,&n);
        if(!m)break;

        vector<bool> p(m,true);
        vector<string> str(n);
        for(int i=0;i<n;i++){
            cin >> str[i];
        }

        int out_num = 0;
        int player_i = 0;
        for(int i=0;i<n;i++){
            if((i+1)%15==0){
                if(str[i]!="FizzBuzz"){
                    p[player_i] = false;
                    out_num++;
                }
            }else if((i+1)%3==0){
                if(str[i]!="Fizz"){
                    p[player_i] = false;
                    out_num++;
                }
            }else if((i+1)%5==0){
                if(str[i]!="Buzz"){
                    p[player_i] = false;
                    out_num++;
                }
            }else{
                if(str[i]!=itos(i+1)){
                    p[player_i] = false;
                    out_num++;
                }
            }

            if(out_num==m-1){
                break;
            }

            player_i = player_i==m-1 ? 0 : player_i+1;
            while(!p[player_i]) player_i = player_i==m-1 ? 0 : player_i+1;
        }

        bool first = true;
        for(int i=0;i<m;i++){
            if(p[i]){
                if(first){cout << i+1;first=false;}
                else cout << " " << i+1;
            }
        }
        cout << endl;
    }

    return 0;
}
