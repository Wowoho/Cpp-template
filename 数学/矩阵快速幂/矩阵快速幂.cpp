struct Matrix//定义
{
    int row;
    int cal;
    long long m[105][105];
}A;

Matrix init(Matrix a,long long t)//矩阵初始化
{
    for(int i = 0; i <=a.row; i++)
        for(int j = 0; j <= a.cal; j++)
            a.m[i][j] = t;
    return a;
}

Matrix mul(Matrix a,Matrix b)//矩阵乘法
{
    Matrix ans;
    ans.row = a.row, ans.cal = b.cal;
    ans = init(ans,0);
    for(int i = 1; i <= a.row; i++)
        for(int j = 1; j <= b.cal; j++)
            for(int k = 1; k <= a.cal; k++)
                ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j])%mod;
    return ans;
}



Matrix quick_pow( Matrix A,long long k)//快速幂
{
    Matrix I;
    I.row = n, I.cal = n;
    I = init(I, 0);
    for(int i = 1; i <=n; i++){
        I.m[i][i] = 1;
    }
    while(k){
        if(k & 1) I = mul(I, A);
        A = mul(A, A);
        k >>= 1;
    }
    return I;
}
