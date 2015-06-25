#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;
typedef pair<char,char> Pc;

vector<Pc> s;
int n = 32;
int as[26],ae[26];

int main(){
  for(int i=0;i<n;i++){
    string temp;
    getline(cin,temp);
    s.push_back(Pc(tolower(temp[0]),tolower(temp[temp.size()-1])));
  }

  memset(as,0,sizeof(as));
  memset(ae,0,sizeof(ae));
  for(int i=0;i<n;i++){
    as[s[i].first-'a']++;
    ae[s[i].second-'a']++;
  }

  sort(s.begin(),s.end());
  for(int i=0;i<n;i++){
    cout << s[i].first << s[i].second << endl;
  }

  for(int i=0;i<26;i++){
    if(!as[i]||!ae[i]){
      continue;
    }
    cout << (char)(i+'a') << " " << as[i]  << ":" << ae[i] << endl;
  }
  return 0;
}