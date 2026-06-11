class Solution {
public:
    void helper(int i,string& cur, vector<string>&ans, string digits){
        int n = digits.size();
        if (i==n) {
            ans.push_back(cur);
            return;
        }
        if (digits[i]=='2'){
            for (char ch='a'; ch<='c'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='3'){
            for (char ch='d'; ch<='f'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='4'){
            for (char ch='g'; ch<='i'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='5'){
            for (char ch='j'; ch<='l'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='6'){
            for (char ch='m'; ch<='o'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='7'){
            for (char ch='p'; ch<='s'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='8'){
            for (char ch='t'; ch<='v'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }
        if (digits[i]=='9'){
            for (char ch='w'; ch<='z'; ch++){
                cur+=ch;
                helper(i+1,cur,ans,digits);
                cur.pop_back();
            }
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits=="") return {};
        string init="";
        helper(0,init,ans,digits);
        return ans;
    }
};
