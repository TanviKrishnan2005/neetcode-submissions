class Solution {
public:

    vector<string>res;
    void solve(int n , string cur,int open,int close){
        if(cur.length()==2*n){
            res.push_back(cur);
            return;
        }

        // if "(" avail
        if(open<n){
            cur.push_back('(');
            solve(n,cur,open+1,close);
            cur.pop_back();
        }

        if(close<open){
            cur.push_back(')');
            solve(n,cur,open,close+1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        solve(n,cur,0,0);
        return res;
    }
};
