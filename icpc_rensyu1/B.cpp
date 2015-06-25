#include <iostream>
#include <complex>
#include <vector>
#include <cstdio>
using namespace std;
typedef complex<int> P;

int cross(const P& a, const P& b){
    return imag(conj(a)*b);
}

int main(){
    int n;
    while(cin >> n, n){
        vector<vector<int> > oresen(n+1);
        vector<int> r_motosen;
        for(int i=0;i<=n;i++){
            int m;
            cin >> m;
            vector<P> input(m);
            for(int j=0;j<m;j++){
                int x,y;
                scanf("%d%d",&x,&y);
                input[j] = P(x,y);
            }
            for(int j=0;j+1<m;j++){
                P v = input[j+1] - input[j];
                oresen[i].push_back(abs(real(v)) + abs(imag(v)));
                if(j+2<m){
                    P v2 = input[j+2] - input[j+1];
                    if(cross(v, v2)>0) oresen[i].push_back(1);
                    else oresen[i].push_back(0);
                }
            }
            if(i==0){
                for(int j=m-1;j-1>=0;j--){
                    P v = input[j-1] - input[j];
                    r_motosen.push_back(abs(real(v)) + abs(imag(v)));
                    if(j-2>=0){
                        P v2 = input[j-2] - input[j-1];
                        if(cross(v, v2)>0) r_motosen.push_back(1);
                        else r_motosen.push_back(0);
                    }
                }
            }
        }
        /*
        for(int i=0;i<oresen[0].size();i++){
            cout<<oresen[0][i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<r_motosen.size();i++){
            cout<<r_motosen[i]<<" ";
        }
        cout<<endl;
        */
        for(int i=1;i<=n;i++){
            if(oresen[i]==oresen[0]||oresen[i]==r_motosen){
                cout << i << endl;
            }
        }/*
        for(int i=1;i<=n;i++){
            if(oresen[i].size()!=oresen[0].size())continue;
            bool same = true;
            for(int j=0;j<oresen[0].size();j++){
                if(oresen[0][j]!=oresen[i][j]){
                    same = false;
                    break;
                }
            }
            if(!same){
                same = true;
                for(int j=0;j<r_motosen.size();j++){
                    if(r_motosen[j]!=oresen[i][j]){
                        same = false;
                        break;
                    }
                }
                if(!same) continue;
            }
            cout << i << endl;
        }
        */
        cout << "+++++" << endl;
        //break;
    }

    return 0;
}