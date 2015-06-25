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
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    set<vector<int> > str_list;
    queue<vector<int> > que;
    vector<int> sub_str(26,0);
    for(int i=0;i<K;i++){
        sub_str[(int)(S[i]-'a')]++;
    }

    que.push(sub_str);
    for(int i=K;i<N;i++){
        if (que.size() == K){
            str_list.insert(que.front());
            que.pop();
        }
        sub_str[(int)(S[i-K]-'a')]--;
        sub_str[(int)(S[i]-'a')]++;
        if (str_list.count(sub_str)){
            cout << "YES" << endl;
            return 0;
        }
        que.push(sub_str);
    }
    cout << "NO" << endl;
    return 0;
}