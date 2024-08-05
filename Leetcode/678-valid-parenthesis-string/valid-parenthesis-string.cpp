class Solution {
public:
    bool checkValidString(string s) {
        stack<char>st;
        int star = 0;
        int leftBracket = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '(')
            ++leftBracket;
            st.push(s[i]);
            if(!st.empty() && st.top() == ')' && leftBracket>0){
                while(st.top() != '('){
                    if(st.top() == '*')
                    ++star;
                    st.pop();
                    if(st.empty())
                    break;
                }
                if(!st.empty())
                st.pop();
                --leftBracket;
            }
            while(star>0){
                st.push('*');
                --star;
            }
        }
        string str = "";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        star = 0;
        leftBracket = 0;
        for(int i = 0;i<str.length();i++){
            if(str[i] == '(')
            ++leftBracket;
            if(str[i] == '*')
            ++star;
            st.push(str[i]);
            if(!st.empty() && st.top() == '*'){
                if(leftBracket == 0 && star == 0)
                return false;
                while(st.top() != '('){
                    st.pop();
                    if(st.empty())
                    break;
                }
                if(!st.empty())
                st.pop();
                --leftBracket;
            }
            if(!st.empty() && st.top() == ')'){
                if(star == 0)
                return false;
                while(st.top() != '*' || st.top() != '('){
                    st.pop();
                    if(st.empty())
                    break;
                }
                if(!st.empty())
                st.pop();
                --star;
            }
        }
        string str2 = "";
        while(!st.empty()){
            if(st.top() != '*')
            str2+=st.top();
            st.pop();
        }
        return str2.length() == 0;
    }
};