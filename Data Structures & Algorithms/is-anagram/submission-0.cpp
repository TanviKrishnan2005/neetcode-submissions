class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()) return false;
        vector<int>freq(26,0);

        for(char x :s){
            freq[x-'a']++;
        }

        for(char x: t){
            freq[x - 'a']--;
        }

        for(int c : freq){
            if (c != 0){
                return false;
            }
        }
        return true;
    }
};
