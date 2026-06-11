class Solution {
public:
    void helper(int op, int cp, string& cur, vector<string>&ans, int n){
        if (op==n && cp==n){
            ans.push_back(cur);
            return;
        }
        if (op>n || cp>n) return ;
        if (op<n){
            string temp="(";
            cur =  cur + temp;
            helper(op+1, cp, cur,ans,n);
            cur.pop_back();
        }
        if (cp<op){
            string temp2=")";

            cur+=temp2;
            helper(op,cp+1,cur,ans, n);
            cur.pop_back();
        }

  
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        helper(0,0,cur,ans,n);
        return ans;
    }
};
