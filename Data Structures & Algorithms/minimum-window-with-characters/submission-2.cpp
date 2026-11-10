class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char c :t) mp[c]++;

        int i =0;int count = t.size();
        int minLen =INT_MAX ,start =0;

        for(int j =0;j<s.size();j++){
            if(mp[s[j]]>0) count--;
            mp[s[j]]--;

            while(count==0){
                if(j-i+1 <minLen){
                    minLen = j-i+1;
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) count++;
                i++;
            }
        }
        return (minLen ==INT_MAX)?"":s.substr(start,minLen);
    }
};
