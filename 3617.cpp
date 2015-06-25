#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int main(){
  string s="",t="";
  char temp;
  int n;
  bool flag;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> temp;
    s += temp;
  }
  for(int i=0;i<n;i++){
    flag=true;
    int size = s.size();
    for(int j=0;j<size;j++){
      if(s[j]<s[size-1-j]){
        t += s[0];
        s.erase(0,1);
        flag=false;
        break;
      }else if(s[j]>s[size-1-j]){
        t += s[size-1];
        s.erase(size-1,1);
        flag=false;
        break;
      }
    }
    if(flag){
      t += s[0];
    }
  }
  cout << t << endl;
}