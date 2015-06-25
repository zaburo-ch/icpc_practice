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

vec split(string& str){
    vec ret;
    int p=1;
    int part = 0;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]=='.'){
            ret.push_back(part);
            part = 0;
            p = 1;
        }else{
            part += p * (str[i]-'0');
            p *= 10;
        }
    }
    ret.push_back(part);
    return ret;
}

int main(){
    int dl_2012 = 2012/4 - 2012/100 + 2012/400;
    int dm_12 = (12 * 979 - 1033) >> 5;
    int maya_cosnt[] = {20, 18, 20, 20};
    int day_m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string input;
    while(cin >> input, input!="#"){
        vec v = split(input);
        if(v.size()==3){
            long long int dy = (long long int)(v[2] - 2012) * 365;
            long long int dl = v[2]/4 - v[2]/100 + v[2]/400 - dl_2012;
            long long int dm = ((v[1] * 979 - 1033) >> 5) - dm_12;
            long long int d = dy + dl + dm + v[0] - 21;
            vec maya(5);
            for(int i=0;i<4;i++){
                maya[i] = d % maya_cosnt[i];
                d /= maya_cosnt[i];
            }
            maya[4] = d % 13;
            cout << maya[4];
            for(int i=3;i>=0;i--){
                cout << '.' << maya[i];
            }
            cout << endl;
        }else{
            long long int dd = 0;
            long long int p = 1;
            for(int i=0;i<5;i++){
                dd += v[i] * p;
                if(i<4) p *= maya_cosnt[i];
            }
            long long int y = 2012, m = 12, d = 21;
            if(dd>11){
                y = 2013;
                m = 1;
                d = 1;
                dd -= 11;
            }
            while(1){
                bool uruu = y%4==0&&(y%100!=0||y%400==0);
                if(dd >= 366&&uruu){
                    y += 1;
                    dd -= 366;
                    continue;
                }else if(dd>=365){
                    y += 1;
                    dd -= 365;
                    continue;
                }
                break;
            }
            while(dd>0){
                bool uruu = y%4==0&&(y%100!=0||y%400==0);
                if(uruu) day_m[1] = 29;
                else day_m[1] = 28;
                if(dd + d > day_m[m-1]){
                    dd -= (day_m[m-1] - d) + 1;
                    d = 1;
                    m = m == 12 ? 1 : m + 1;
                }else{
                    d += dd;
                    dd = 0;
                }
                //cout << y << "." << m << "." << d << endl;
            }
            cout << y << "." << m << "." << d << endl;
        }
    }
    return 0;
}
