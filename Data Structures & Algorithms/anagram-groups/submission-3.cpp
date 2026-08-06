class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // key -> sorted word
        // value -> list of anagrams
        unordered_map<string, vector<string>> mp;

        // Traverse every string
        for (string str : strs) {

            string key = str;

            // Sort to create key
            sort(key.begin(), key.end());

            // Group anagrams
            mp[key].push_back(str);
        }

        vector<vector<string>> res;

        // Collect all groups
        for (auto it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};