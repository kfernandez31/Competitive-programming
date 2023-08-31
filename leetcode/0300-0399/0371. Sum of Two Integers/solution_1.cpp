// Approach: Inline assembly.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int getSum(int a, int b){
        __asm__(
            "add %%ebx, %%eax" 
            : "=a" (a) 
            : "a" (a), "b" (b)
        );
        return a;
    }
};