class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); int n = matrix[0].size();

        int r =0,c=n-1;

        while(r<m && c>=0){
            if(matrix[r][c]>target){
                c--;
            }
            else if(matrix[r][c]<target){
                r++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
// brute force check all cells
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(int r =0;r<matrix.size();r++){
//             for(int c =0;c<matrix[r].size();c++){
//                 if(matrix[r][c]==target){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };