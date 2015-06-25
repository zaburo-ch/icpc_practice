#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <utility>
#include <set>
using namespace std;

string str[50];

string code(string& target, int k){
    string ret = "";
    ret.push_back(target[0]);
    for(int i=1;i<target.size()&&ret.size()<k;i++){
        if(target[i-1]=='a'||target[i-1]=='i'||target[i-1]=='u'||target[i-1]=='e'||target[i-1]=='o'){
            ret.push_back(target[i]);
        }
    }
    return ret;
}


int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n)break;

        int max_size = 0;
        for(int i=0;i<n;i++){
            cin >> str[i];
            max_size = max(max_size, (int)(str[i].size()));
        }

        bool ans_found;
        int ans_k;
        for(int k=1;k<=max_size;k++){
            set<string> s;
            ans_found = true;
            for(int i=0;i<n;i++){
                string coded = code(str[i], k);
                //cout << "k = " << k << " i = " << i << " coded = " << coded << endl;
                if(s.count(coded)){
                    ans_found = false;
                    break;
                }else{
                    s.insert(coded);
                }
            }
            if(ans_found){
                ans_k = k;
                break;
            }
        }
        if(ans_found) cout << ans_k << endl;
        else cout << -1 << endl;
    }
}