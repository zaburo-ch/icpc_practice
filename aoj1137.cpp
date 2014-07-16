#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;

int s2i(string str){
    int sum = 0;
    int pos;
    pos = str.find("m");
    if(pos>=0){
        if(pos-1>=0 && str[pos-1]>'0' && str[pos-1]<='9'){
            sum += ((int)(str[pos-1]-'0'))*1000;
        }else{
            sum += 1000;
        }
    }
    pos = str.find("c");
    if(pos>=0){
        if(pos-1>=0 && str[pos-1]>'0' && str[pos-1]<='9'){
            sum += ((int)(str[pos-1]-'0'))*100;
        }else{
            sum += 100;
        }
    }
    pos = str.find("x");
    if(pos>=0){
        if(pos-1>=0 && str[pos-1]>'0' && str[pos-1]<='9'){
            sum += ((int)(str[pos-1]-'0'))*10;
        }else{
            sum += 10;
        }
    }
    pos = str.find("i");
    if(pos>=0){
        if(pos-1>=0 && str[pos-1]>'0' && str[pos-1]<='9'){
            sum += ((int)(str[pos-1]-'0'));
        }else{
            sum += 1;
        }
    }
    return sum;
}

string i2s(int sum){
    string str = "";
    int di;
    di = sum / 1000;
    if(di>0){
        if(di>1){
            str.push_back(di+'0');
        }
        str.push_back('m');
    }
    di = (sum%1000)/100;
    if(di>0){
        if(di>1){
            str.push_back(di+'0');
        }
        str.push_back('c');
    }
    di = (sum%100)/10;
    if(di>0){
        if(di>1){
            str.push_back(di+'0');
        }
        str.push_back('x');
    }
    di = (sum%10);
    if(di>0){
        if(di>1){
            str.push_back(di+'0');
        }
        str.push_back('i');
    }
    return str;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string str1,str2;
        cin >> str1 >> str2;
        cout << i2s( s2i(str1) + s2i(str2) ) << endl;
    }
    return 0;
}