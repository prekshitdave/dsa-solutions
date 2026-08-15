class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorVal = start ^ goal;
        int count = 0;
        while (xorVal) {
            xorVal &= (xorVal - 1);  // clears the lowest set bit
            count++;
        }
        return count;
    }
};