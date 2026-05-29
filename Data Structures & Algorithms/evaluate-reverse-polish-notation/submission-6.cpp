class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i=0; i<n; i++){
            if (tokens[i]=="+"){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x1+x2);
            }
            else if (tokens[i]=="*"){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x1*x2);
            }
            else if (tokens[i]=="-"){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(x2-x1);
            }
            else if (tokens[i]=="/"){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push((int)(x2/x1));
            }
            else {
                int v=0;
                int r=1;
                for (int j=tokens[i].size()-1; j>=0; j--){
                    if (tokens[i][j]<'0' || tokens[i][j]>'9') break;
                    v+=(r*(tokens[i][j]-'0'));
                    r*=10;
                }
                if (tokens[i][0]=='-') v = -v;
                st.push(v);
            }
        }
        return st.top();
        
    }
};
