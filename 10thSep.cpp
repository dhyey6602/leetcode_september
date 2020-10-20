class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> dicti,dicti1;
        int bull=0,cow=0;
        for(int i=0;i<secret.size();i++)
        {
            if(dicti.find(secret[i])==dicti.end())
                dicti[secret[i]]=1;
            else
                dicti[secret[i]]++;
            
            if(dicti1.find(guess[i])==dicti1.end())
                dicti1[guess[i]]=1;
            else
                dicti1[guess[i]]++;
            if(secret[i]==guess[i])
                bull++;
        }
        for(auto itr=dicti.begin();itr!=dicti.end();++itr)
        {
            if(dicti1.find(itr->first)!=dicti1.end())
            {
                cow+=min(itr->second,dicti1[itr->first]);
            }
        }
        string ans=to_string(bull)+'A'+to_string(cow-bull)+'B';
        return ans;
    }
};
