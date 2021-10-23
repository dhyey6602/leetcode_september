class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> fre;
        for(auto x:s)
            fre[x]++;
        sort(s.begin(),s.end(),[&](char a, char b){
            if(fre[a] == fre[b])
                return a > b;
            return fre[a] > fre[b];
        });
        return s;
    }
};