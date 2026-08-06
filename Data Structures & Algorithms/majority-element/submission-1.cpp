class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> mp;

        // Count frequency
        for (int num : nums) {
            mp[num]++;
        }

        int maxFreq = 0;
        int ans = 0;

        // Find maximum frequency
        for (auto it : mp) {

            if (it.second > maxFreq) {
                maxFreq = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};