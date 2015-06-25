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
    stack<char> s;
    while(true){
        string command;
        cin >> command;
        if (command == "push"){
            char ch;
            cin >> ch;
            s.push(ch);
        }else if (command == "pop"){
            cout << s.top() << endl;
            s.pop();
        }else{
            break;
        }
    }
    return 0;
}