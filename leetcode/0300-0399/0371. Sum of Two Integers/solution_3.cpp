// Approach: Interleavings of ANDs and XORs.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            // int c = (a & b & 0xFFFFFFFF); // this also works
            unsigned c = a & b; // each pair of 1s will produce a carry on the next pos
            a ^= b;             // add without carry
            b = c << 1;         // the right summand is what was left to add (so the multiple carrys) 
        }
        return a;
    }
};