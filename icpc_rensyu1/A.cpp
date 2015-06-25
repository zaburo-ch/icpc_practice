#include <iostream>
using namespace std;



int main(){

    int n,j,count;
    bool num[246913];

    num[1]=false;
    for(int i=2;i<246913;i++){
        num[i]=true;
    }
    for(int i=2;i<246913;i++){
        if(num[i]){
            j=2*i;
            while(j<246913){
                num[j]=false;
                j+=i;
            }
        }
    }

    while(cin>>n,n){

        j=n+1;
        count=0;
        while(j<=2*n){
            if(num[j]){
                count++;
            }

                j++;
        }

        cout<<count<<endl;

    }



    return 0;
}