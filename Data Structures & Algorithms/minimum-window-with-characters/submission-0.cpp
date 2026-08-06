class Solution {
public:
    string minWindow(string s, string t) {
     int n = s.size();
     if(t.size()>n) return "";

     //map
     unordered_map<char,int>mp;

     //store
     for(char c : t){
        mp[c]++;
     }   
     int i =0,j=0;
     int count=t.size();
     int start_i=0;
     int minwindow=INT_MAX;

     while(j<n){
        char c =s[j];
        if(mp[c]>0){
            count--;}
            mp[c]--;

            while(count ==0){
                //shrink
                int currwindow= j - i + 1;
                if(minwindow>currwindow){
                    minwindow=currwindow;
                    start_i=i;
                }
                mp[s[i]]++;

                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
        return (minwindow == INT_MAX)? "" :s.substr(start_i,minwindow);
     
    }
};