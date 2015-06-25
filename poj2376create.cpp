#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;

int main(){
  cout << "100 10" << endl;
  for(int i=0;i<50;i++){
    cout << rand()%4+1 << " " << rand()%5 + 1 << endl;
    cout << rand()%5+5 << " " << rand()%5 + 6 << endl;
  }
}