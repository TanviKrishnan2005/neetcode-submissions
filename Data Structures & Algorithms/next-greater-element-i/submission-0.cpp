class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        vector<int>res(nums1.size(),-1);
        stack<int>stack;

        for(int num:nums2){
            while(!stack.empty() && num>stack.top()){
                int val = stack.top();
                stack.pop();
                int idx = mp[val];
                res[idx]=num;
            }
            if(mp.find(num)!= mp.end()){
                stack.push(num);
            }
        }
        return res;
    }
};