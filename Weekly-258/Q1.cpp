class Solution {
public:
    string reversePrefix(string s, char a) {
        int pos = find(s.begin(), s.end(), a) - s.begin();
        if(pos < s.size()) {
            reverse(s.begin(), s.begin() + pos + 1);
        }
        return s;
    }
};