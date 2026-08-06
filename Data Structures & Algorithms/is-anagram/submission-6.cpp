class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        if(s.size()!= t.size()) return false;

        for(int x : s){
            count[x-'a']++;
        }
        for(int x : t){
            count[x-'a']--;
        }
        for(int x : count){
            if(x!=0) return false;
        }
        return true;
    }
};
