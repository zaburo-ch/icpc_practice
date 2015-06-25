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
struct edge{int to,cost;};

typedef pair<string, int> siP;
typedef pair<int, string> isP;

bool cmp(const siP& left, const siP& right){
    return left.second == right.second ? left.first < right.first : left.second > right.second;
}

int main(){
    int n;
    while(cin >> n, n){
        map<string, int> counter;
        for(int i=0;i<n;i++){
            string line;
            getline(cin, line);
            if(line.size()==0){
                i--;
                continue;
            }
            string str = "";
            for(int j=0;j<line.size();j++){
                if(line[j]==' '){
                    counter[str]++;
                    str = "";
                }else{
                    str.push_back(line[j]);
                }
            }
            if(str.size())counter[str]++;
        }
        char k;
        cin >> k;
        vector<siP> v(counter.begin(),counter.end());
        sort(v.begin(), v.end(), cmp);
        int count = 0;
        for(int i=0;i<v.size();i++){
            if(v[i].first[0]==k){
                if(count==0){
                    cout << v[i].first;
                }else{
                    cout << " " << v[i].first;
                }
                count++;
                if(count==5)break;
            }
        }
        if(count==0)cout << "NA" << endl;
        else cout << endl;
    }

    return 0;
}
