// Approach: A vector is a stack, thus we can solve this in-place.
// TC: O(n)
// SC: O(1)
class Solution {
public:
     vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for (int as : asteroids) {
            if (0 < as)
                ans.push_back(as);
            else {
                bool remains = true;

                while (!ans.empty() && ans.back() > 0 && remains) {
                    if (ans.back() > -as) 
                        remains = false;
                    else {
                        remains = ans.back() < -as;
                        ans.pop_back();
                    }
                }

                if (remains)
                    ans.push_back(as);
            }
        }

        return ans;
    }
};