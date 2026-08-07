class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>res(n,-1);
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i =0;i<n;i++){
            mp[nums1[i]] =i;
        }

        for(int num :nums2){
            while(!st.empty()&& num>st.top()){
                int val = st.top();
                st.pop();
                int idx = mp[val];
                res[idx]=num;
            }
            if(mp.find(num)!=mp.end()){
                st.push(num);
            }
        }
        return res;
    }
};