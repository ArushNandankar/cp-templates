/*
    returns {x, y} which are solutions to the equation
    ax + by = gcd(a, b)
*/
pair<int, int> gcd_extended(int a, int b) {
    if (b == 0) {
        return {1, 0};
    }
    auto [x2, y2] = gcd_extended(b, a % b);
    int x = y2;
    int y = x2 - (a / b) * y2;
    return {x, y};
}
