class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Map each nums1 value to its index in the result
        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]] = i;
        }

        // Default answer is -1 if no greater element is found
        vector<int> res(nums1.size(), -1);

        // Decreasing stack: stores nums1 elements
        // still waiting for their next greater element
        stack<int> st;

        // Traverse nums2 to find next greater elements
        for(int num : nums2) {

            // Current number is the next greater element
            // for all smaller values on top of the stack
            while(!st.empty() && num > st.top()) {

                int val = st.top();
                st.pop();

                // Store current number as val's answer
                int idx = mp[val];
                res[idx] = num;
            }

            // Only track numbers that belong to nums1
            if(mp.find(num) != mp.end()) {
                st.push(num);
            }
        }

        return res;
    }
};