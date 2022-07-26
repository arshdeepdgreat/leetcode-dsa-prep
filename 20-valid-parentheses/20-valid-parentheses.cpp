class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push('&');
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else if(st.top()=='{' and s[i]=='}'|| 
               st.top() == '[' and s[i]==']' || 
               st.top() == '(' and s[i]==')')
                st.pop();
            else 
                return false;
        }
        if(st.top()=='&')
            return true;
        return false;
    }
};