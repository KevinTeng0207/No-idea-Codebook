/*n people kill k for each turn*/
int josephus(int n,int k){
    int s = 0;
    for (int i = 2; i <= n; i++){
        s = (s + k) % i;
    }
    /*index start from 1 -> s+1*/
    return s+1;
}
/*died at kth*/
int kth(int n, int m, int k){
    if (m == 1) return n-1;
    for (k = k*m+m-1; k >= n; k = k-n+(k-n)∕(m-1));
    return k;
}