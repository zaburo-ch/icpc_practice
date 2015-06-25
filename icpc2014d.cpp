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
using namespace std;
typedef pair<int,int> P;
const int INF = (int)((unsigned int)-1>>1);

string input;
set<string> s;
bool c[20];
int n;

bool check(string str){
    for(int i=1;i<26;i++){
        for(int j=0;j<n;j++){
            if (str[j]=='a'+i){
                str[j] -= 1;
                break;
            }
        }
    }
    return str == input;
}

void dfs(string str, int pos){
    if (pos == n){
        if(check(str) && s.count(str)==0){
            s.insert(str);
        }
    }else{
        dfs(str,pos+1);
        if (!c[(int)(str[pos])]){
            c[(int)(str[pos])] = true;
            str[pos]++;
            dfs(str,pos+1);
            c[(int)(str[pos])-1] = false;
        }
    }
}

int main(){
    while(1){
        cin >> input;
        if (input == "#") break;
        n = input.size();
        fill(c,c+n,false);
        dfs(input, 0);
        printf("%d\n", (int)s.size());
        vector<string> ans(s.begin(), s.end());
        if (ans.size()>10){
            for(int i=0;i<5;i++){
                cout << ans[i] << endl;
            }
            for(int i=ans.size()-5;i<ans.size();i++){
                cout << ans[i] << endl;
            }
        }else{
            for(int i=0;i<ans.size();i++){
                cout << ans[i] << endl;
            }
        }
        s.clear();
    }
    return 0;
}

