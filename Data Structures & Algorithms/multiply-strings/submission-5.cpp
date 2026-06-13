class Solution {
public:
    string add(string& s1, string&s2){
        if (s2=="") return s1;
        if (s1=="") return s2;
        int n =  s1.size();
        int m = s2.size();
        if (n>m){
            reverse(s2.begin(), s2.end());
            while (n!=m){
                s2.push_back('0');
                m++;
            }
            reverse(s2.begin(), s2.end());
        }
        else if (m>n){
            reverse(s1.begin(), s1.end());
            while (n!=m){
                s1.push_back('0');
                n++;
            }
            reverse(s1.begin(), s1.end());
        }
        string t="";
        int cur = n-1;
        int carry=0;
        while (cur>=0){
            int d1 = s1[cur]-'0';
            int d2 = s2[cur]-'0';
            int res = (d1+d2 +carry);
            t+=(res%10 + '0');
            carry = res/10;
            cur--;
        }
        if (carry){
            t.push_back('0'+carry);
        }
        while (t.back()=='0') t.pop_back();
        reverse(t.begin(), t.end());
        return t;
        
    }
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        string y="0";
        if (num2==y || num1==y) return "0";
        if (n>m){
            reverse(num2.begin(), num2.end());
            while (n!=m){
                num2.push_back('0');
                m++;
            }
            reverse(num2.begin(), num2.end());
        }
        else if (m>n){
            reverse(num1.begin(), num1.end());
            while (n!=m){
                num1.push_back('0');
                n++;
            }
            reverse(num1.begin(), num1.end());
        }
        int cur=m-1;
        string ans="";
        int z=0;
        while (cur>=0){
            int d = num2[cur]-'0';
            int carry=0;
            string temp="";
            for (int i=0; i<z; i++){
                temp.push_back('0');
            }
            for(int i=n-1; i>=0 ;i--){
                int res = carry + (num1[i]-'0')*d;
                temp+=(res%10 + '0');
                carry = res/10;
            }
            while (carry){
                temp+=(carry%10 + '0');
                carry/=10;
            }
            reverse(temp.begin(), temp.end());

            ans = add(ans,temp);

            cur--;
            z++;
        }
        return ans;
    }
};
