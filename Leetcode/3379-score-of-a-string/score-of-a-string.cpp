class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 0;i<s.length()-1;i++)
        sum+=abs((char)s[i] - (char)s[i+1]);
        return sum;
    }
};