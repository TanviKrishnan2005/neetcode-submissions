class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int x : nums){
            mp[x]++;
        }
        vector<pair<int,int>>freq;
        for(auto x : mp){
            freq.push_back({x.second,x.first});
        }
        sort(freq.rbegin(),freq.rend());

        vector<int>res;

        for(int i =0;i<k;i++){
            res.push_back(freq[i].second);
        }
        return res;
    }
};
