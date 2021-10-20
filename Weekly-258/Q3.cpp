class Solution {
public:
    int isp[1 << 12], len[1 << 12];
    int chk(const string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) return 0;
            ++i, --j;
        }
        return 1;
    }
    int maxProduct(string s) {
        int n = s.size();
        for(int i = 1; i < 1 << n; ++i) {
            string p;
            for(int j = 0; j < n; ++j) if(i >> j & 1) p += s[j];
            isp[i] = chk(p);
            len[i] = __builtin_popcount(i);
        }
        int ans = 0;
        for(int i = 1; i < 1 << n; ++i) {
            if(!isp[i]) continue;
            int rev = (i ^ ((1 << n) - 1));
            for(int j = rev; j; j = (j - 1) & rev) {
                if(isp[j]) ans = max(ans, len[i] * len[j]);
            }
        }
        return ans;
    }
};
