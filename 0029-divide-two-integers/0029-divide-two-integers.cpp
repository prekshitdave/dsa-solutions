class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow: only INT_MIN / -1 overflows 32-bit signed range
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to safely hold abs(INT_MIN)
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);
        
        long long quotient = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }
        
        return negative ? -quotient : quotient;
    }
};