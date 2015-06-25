#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#define INF 10000000
using namespace std;
typedef pair<int,int> P;


int main(){
  //long long int a = (unsigned long long int)-1/2;
  //string dict = "abcde";
  //if(dict.find('a')>=0) cout << "ok!" << endl;
  int array[] = {0,3,3,3};
  int pos = lower_bound(array,array+4,4) - array;
  cout << pos << endl;
  return 0;
}