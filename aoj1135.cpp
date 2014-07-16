#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    long mon;
    int m,n,i,j,k,y,te,th;
    double rate;

    cin >> m;
    for(i=0;i<m;i++){
        vector<int> kekka;
        cin >> mon >> y >> n;
        for(j=0;j<n;j++){
            cin >> th >> rate >> te;
            if(th==1){
                long A=mon;
                int B =0;
                for(k=0;k<y;k++){
                    B = (int)(A*rate);
                    A = A + B - te;
                }
                kekka.push_back(A);
            }else{
                long A=mon;
                int B =0;
                for(k=0;k<y;k++){
                    B += (int)(A*rate);
                    A -= te;;
                }
                kekka.push_back(A+B);
            }
        }
        sort(kekka.begin(),kekka.end());

        cout << kekka[kekka.size()-1] <<endl;

    }

    return 0;
}