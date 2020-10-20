class Solution {
public:
    int compareVersion(string version1, string version2) {
        string temp="";
        vector<int> ver1,ver2;
        for(int i=0;i<version1.size();i++)
        {
            if(i==version1.size()-1)
                temp+=version1[i];
            if(version1[i]=='.' || i==version1.size()-1)
            {
                ver1.push_back(atoi( temp.c_str() ));
                temp="";
            }
            else
            {
                temp+=version1[i];
            }
        }
        for(int i=0;i<version2.size();i++)
        {
            if(i==version2.size()-1)
                temp+=version2[i];
            if(version2[i]=='.' || i==version2.size()-1)
            {
                ver2.push_back(atoi( temp.c_str() ));
                temp="";
            }
            else
            {
                temp+=version2[i];
            }
        }
        if(ver1.size()>ver2.size())
            ver2.resize(ver1.size());
        else if(ver1.size()<ver2.size())
            ver1.resize(ver2.size());
        for(int i=0;i<ver1.size();i++)
        {
            if(ver1[i]>ver2[i])
                return 1;
            else if(ver1[i]<ver2[i])
                return -1;
        }
        return 0;
    }
};
