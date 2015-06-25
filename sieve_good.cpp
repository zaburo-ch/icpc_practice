#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime[10000001];

int main(){
    fill(is_prime,is_prime+10000001,true);
    is_prime[0] = false; is_prime[1] = false;
    for(int i=2;i<10000001;i++){
        if(is_prime[i]){
            for(int j=2*i;j<10000001;j+=i){
                is_prime[j] = false;
            }
        }
    }
    return 0;
}
