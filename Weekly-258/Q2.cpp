class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& a) {
        map<pair<int,int>, int> mp;
        long long ans = 0;
        for(auto &v : a) {
            int g = gcd(v[0], v[1]);
            v[0] /= g;
            v[1] /= g;
            ans += mp[{v[0], v[1]}];
            ++mp[{v[0], v[1]}];
        }
        return ans;
    }
};