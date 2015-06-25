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

int size;
set<string> dict;
string input;

void dfs(string str,int pos,char step){
  bool pushed = false;
  for(int i=pos;i>=0;i--){
    char last = str[i];
    if(last>=step) continue;
    bool can = true;
    for(int j=i;j<=pos;j++){
      if(last+1<str[j]){
        can = false;
        break;
      }
    }
    if(can){
      string cpy = str;
      cpy[i] += 1;
      pushed = true;
      dfs(cpy,i-1,cpy[i]-1);
    }
  }
  if(!pushed){
    if(str!=input){
      dict.insert(str);
    }
  }else{
    bool canpush = true;
    for(int i=pos;i>=0;i--){
      if(str[pos]!='a'){
        canpush = false;
        break;
      }
    }
    if(canpush){
      dict.insert(str);
    }
  }
}

bool check(){
  int posz = input.find("z");
  if(posz==-1) return true;
  int posy = input.find("y");
  if(posy==-1) return false;
  if(posy<posz) return true;
  else return false;
}


int main(){
  while(1){
    cin >> input;
    if(input=="#") break;

    dict.clear();
    size = input.size();
    if(!check()){
      cout << 0 << endl;
      continue;
    }
    dfs(input,size-1,'z');

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