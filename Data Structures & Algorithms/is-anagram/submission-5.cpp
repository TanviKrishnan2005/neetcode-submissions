class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return 0;

        vector<int>freq(26,0);
        for(int x : s){
            freq[x-'a']++;
        }
        for(int x : t){
            freq[x-'a']--;
        }
        for(int x : freq){
            if(x!=0) return false;
        }
        return true;
    }
};
