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


int main(){
    int temp;
    cin >> temp;
    stack<char> s[100];
    while(true){
        string command;
        cin >> command;
        if (command == "push"){
            int n;
            char ch;
            cin >> n >> ch;
            s[n-1].push(ch);
        }else if (command == "pop"){
            int n;
            cin >> n;
            cout << s[n-1].top() << endl;
            s[n-1].pop();
        }else if (command == "move"){
            int n1, n2;
            cin >> n1 >> n2;
            s[n2-1].push(s[n1-1].top());
            s[n1-1].pop();
        }else{
            break;
        }
    }
    return 0;
}