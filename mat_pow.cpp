typedef vector<int> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size(),0));

    for(int i=0;i<C.size();i++){
        for(int j=0;j<C[0].size();j++){
            for(int k=0;k<B.size();k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

mat pow(mat &A, int n){
    mat B(A.size(), vec(A.size(),0));
    for(int i=0;i<A.size();i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

void print_mat(mat &A){
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            printf("%3d ",A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    mat A(3, vec(3,2));
    mat B(3, vec(3,0));
    B[0][0] = 1; B[1][1] = 1; B[2][2] = 1;
    print_mat(A);
    mat A2 = pow(A, 4);
    print_mat(A2);
    print_mat(B);
    mat B2 = pow(B, 4);
    print_mat(B2);
    return 0;
}