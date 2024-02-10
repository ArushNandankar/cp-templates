const int M = 1e9 + 7;

int power(int x, int y, int p) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = ((res % p) * (x % p)) % p;
 
        y = y >> 1;
 
        x = ((x % p) * (x % p)) % p;
    }
    return res % p;
}
 
int inv(int A, int B = M) {
    int g = gcd(A, B);
    if (g != 1) {
        return 0;
    } else {
        return power(A, B - 2, B);
    }
}
