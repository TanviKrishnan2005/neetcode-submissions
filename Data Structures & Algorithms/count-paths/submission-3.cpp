class Solution {
public:
    int uniquePaths(int m, int n) {
        //Initialize a 1D array dp of size n with all values as 1
        vector<int>dp(n,1);
        //Traverse columns from right to left (excluding last column).
        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                dp[j]+= dp[j+1];
            }
        }
        return dp[0];//contains the total number of unique paths.
    }
};
