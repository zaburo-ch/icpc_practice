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


int n;
string str;

int toint(string s){
    int n = 0;
    int p = 1;
    for(int i=s.size()-1;i>=0;i--){
        n += p*(s[i]-'0');
        p *= 10;
    }
    return n;
}

int dfs(int pos){
    //printf("in : %d\n",pos);
    vector<int> points;
    int kakko_n = 1;
    for(int i=pos+1;i<str.size();i++){
        if (kakko_n == 1){
            if(str[i]=='['){
                points.push_back(dfs(i));
                kakko_n += 1;
            }else if(str[i]==']'){
                break;
            }else{
                string num = "";
                while(str[i]!=']'){
                    num.push_back(str[i]);
                    i+=1;
                }
                points.push_back((toint(num)+1)/2);
                break;
            }
        }else{
            if(str[i]=='['){
                kakko_n += 1;
            }else if(str[i]==']'){
                kakko_n -= 1;
            }
        }
    }
    sort(points.begin(), points.end());
    int p = 0;
    for(int i=0;i<(points.size()+1)/2;i++){
        p += points[i];
    }
    /*
    printf("out : %d\n",pos);
    for(int i=0;i<points.size();i++){
        printf("%d ",points[i]);
    }
    cout << endl;
    */
    return p;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        cout << dfs(0) << endl;
    }
}