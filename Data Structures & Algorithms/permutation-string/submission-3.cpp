class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     if(s1.size()>s2.size()) return false;
     vector<int> s1count(26,0),window(26,0);

     for(char c :s1){
        s1count[c-'a']++;
     }   
     int l =0;
     for(int r =0;r<s2.size();r++){
        window[s2[r]-'a']++;
        if(r-l+1>s1.size()){
            window[s2[l]-'a']--;
            l++;
        }
        if(window == s1count){
            return true;
        }
     }
     return false;
    }
};
