class Solution {
public:
    // Store all possible letter combinations
    vector<string> res;

    // Map each digit to its corresponding phone letters
    vector<string> digitToChar = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {

        // No digits means no combinations
        if (digits.empty())
            return res;

        // Start from the first digit with an empty string
        backtrack(0, "", digits);

        return res;
    }

    void backtrack(int i, string curStr, string& digits) {

        // If one letter is chosen for every digit,
        // the combination is complete
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }

        // Get letters mapped to the current digit
        // Example: '2' - '0' = 2 → "abc"
        string chars = digitToChar[digits[i] - '0'];

        // Try every possible letter for the current digit
        for (char c : chars) {

            // Add current letter and move to the next digit
            backtrack(i + 1, curStr + c, digits);
        }
    }
};