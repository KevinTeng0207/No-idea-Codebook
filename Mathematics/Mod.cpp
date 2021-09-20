int pow_mod(int a, int n, int m) // a ^ n mod m;
{ // a, n, m < 10 ^ 9
    if (n == 0)
        return 1;
    int x = pow_mid(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if (n % 2 == 1)
        ans = ans * a % m;
    return (int)ans;
}

// 加法：(a + b) % p = (a % p + b % p) % p;
// 減法：(a − b) % p = (a % p − b % p + p) % p;
// 乘法：(a * b) % p = (a % p * b % p) % p;
// 次方：(a ^ b) % p = ((a % p) ^ b) % p;
// 加法結合律：((a + b) % p + c) % p = (a + (b + c)) % p;
// 乘法結合律：((a * b) % p * c) % p = (a * (b * c)) % p;
// 加法交換律：(a + b) % p = (b + a) % p;
// 乘法交換律：(a * b) % p = (b * a) % p;
// 結合律：((a + b) % p * c) = ((a * c) % p + (b * c) % p) % p;

// 如果 a ≡ b(mod m) ，我們會說 a,b 在模 m 下同餘。
// 整除性： a ≡ b(mod m) ⇒ c ⋅ m = a − b, c ∈ Z ⇒ a ≡ b (mod m) ⇒ m|a−b
// 遞移性：若 a ≡ b (mod c), b ≡ d(mod c) 則 a ≡ d (mod c)
/****基本運算****/
// a ≡ b (mod m) ⇒ { a ± c ≡ b ± d (mod m) }
// c ≡ d (mod m) ⇒ { a * c ≡ b * d (mod m) }
// 放大縮小模數：k∈Z+, a ≡ b (mod m) ⇔ k ⋅ a ≡ k ⋅ b (mod k⋅m)
