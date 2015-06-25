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

//AC 通った！

const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
struct edge{int to,cost;};

int main(){
    while(1){
        long long int n;
        cin >> n;
        if(!n) break;

        int num[12];
        fill(num,num+12,0);
        int i=0;
        long long int p = -100000000000;
        while(p!=0){
            if(p<0){
                int p_b = p * 9 / 100;
                int temp = p_b / 100;
                while(temp!=0){
                    p_b += temp;
                    temp /= 100;
                }
                while(n < p_b){
                    n -= p;
                    num[i]++;
                }
            }else{
                int p_b = p * 9 / 100;
                int temp = p_b / 100;
                while(temp!=0){
                    p_b += temp;
                    temp /= 100;
                }
                while(n > p_b){
                    n -= p;
                    num[i]++;
                }
            }
            p /= -10;
            i++;
        }
        bool is_start = false;
        for(int i=0;i<12;i++){
            if(!is_start&&num[i]>0){
                is_start = true;
            }
            if(is_start || i==11){
                cout << num[i];
            }
        }
        cout << endl;
    }

    return 0;
}
