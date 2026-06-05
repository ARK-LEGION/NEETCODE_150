class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if (n==1 && s[0]=='*') return true;
        stack<int> st1, st2;
        for (int i=0; i<n; i++){
            if (s[i]=='*') st2.push(i);
            else if (s[i]=='(') st1.push(i);
            else{
                if (!st1.empty()) st1.pop();
                else if (!st2.empty()) st2.pop();
                else return false;
            }
        }
        while (!st2.empty()){
            if (st1.empty()) break;
            if (st1.top()>st2.top()) break;
            st2.pop();
            st1.pop();
        }
        if (!st1.empty()) return false;
        return true;
    }
};
