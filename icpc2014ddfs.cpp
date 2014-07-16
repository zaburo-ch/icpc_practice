#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;

set<string> dict;
int size;
string input;

bool check(string str){
  bool changed[26];
  fill(changed,changed+26,false);
  changed[0] = true;
  for(int i=0;i<size;i++){
    if(str[i]>'z') return false;
    if(changed[str[i]-'a']) continue;
    str[i]--;
    changed[str[i]-'a'+1] = true;
  }
  return str==input;
}

string str;
bool used[26];
void dfs(int pos){
  if(pos<0){
    if(check(str)){
      dict.insert(str);
    }
    return;
  }

  dfs(pos-1);
  if(str[pos]<'z'&&!used[str[pos]-'a']){
    used[str[pos]-'a'] = true;
    str[pos]++;
    dfs(pos-1);
    str[pos]--;
    used[str[pos]-'a'] = false;
  }
}

int main(){
  while(1){
    cin >> input;
    if(input=="#") break;
    dict.clear();
    size = input.size();

    str = input;
    fill(used,used+26,false);
    dfs(size-1);

    int n = dict.size();
    cout << n << endl;
    set<string>::iterator it = dict.begin();
    if(n>10){
      for(int i=0;i<n;i++){
        if(i<5||dict.size()-5<=i){
          cout << *it << endl;
        }
        it++;
      }
    }else{
      for(int i=0;i<n;i++){
        cout << *it << endl;
        it++;
      }
    }
  }
  return 0;
}