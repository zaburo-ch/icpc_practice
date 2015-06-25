#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    int a,n,nam;

    vector<int> allnum;
    vector<int> oddnum;
    int allam[1000001];
    int oddam[1000001];

    for(int i=1;i<1000001;i++){
        allam[i]=999999;
        oddam[i]=999999;
    }


    for(int i=1;i<200;i++){
        a=i*(i+1)*(i+2)/6;
        if(a>1000000) break;
        if(a%2==1) oddnum.push_back(a);
        allnum.push_back(a);
    }

    allam[0]=0;oddam[0]=0;
    for(int i=0;i<1000001;i++){
        for(int j=0;j<allnum.size();j++){
            nam=i+allnum[j];
            if(nam<1000000) allam[nam]=min(allam[nam],allam[i]+1);
        }
        for(int j=0;j<oddnum.size();j++){
            nam=i+oddnum[j];
            if(nam<1000000) oddam[nam]=min(oddam[nam],oddam[i]+1);
        }
    }

    while(cin>>n,n){
        cout<<allam[n]<<" "<<oddam[n]<<endl;
    }

    return 0;
}