class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0);

        // Frequency of s1
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }

        int k = s1.size();

        // Check every substring of length k
        for (int i = 0; i <= s2.size() - k; i++) {

            vector<int> freq2(26, 0);

            for (int j = i; j < i + k; j++) {
                freq2[s2[j] - 'a']++;
            }

            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};