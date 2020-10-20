class Solution {
public:
    void solve(vector<int> arr,vector<int>& temp,int k,int n,int start,vector<vector<int>>& ans)
    {
        if(temp.size()==k)
        {
            if(n==0)
                ans.push_back(temp);
            else
                return;
        }
        for(int i=start;i<arr.size();i++)
        {
            if(arr[i]>n)
                break;
            temp.push_back(arr[i]);
            solve(arr,temp,k,n-arr[i],i+1,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,temp,k,n,0,ans);
        return ans;
    }
};
