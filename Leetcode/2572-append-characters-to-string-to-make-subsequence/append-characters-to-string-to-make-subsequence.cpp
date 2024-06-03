class Solution {
public:
    int appendCharacters(string s, string t) {
        int append = 0;
        int i = 0;
        int j = 0;
        string c = "";
        while(i<t.length()){
            // int temp = j;
            while(j<s.length()){
                if(t[i] == s[j]){
                    c+=s[j];
                    ++j;
                    break;
                }
                ++j;
            }
            if(j == s.length()){
                if(c == t)
                append = 0;
                else
                if(t[i] == s[s.length()-1])
                append+=t.length()-(i+1);
                else
                append+=t.length()-i;
                break;
            }
            ++i;
        }
        return append;
    }
};