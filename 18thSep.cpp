class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> price;
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(price.empty())
                price.push(prices[i]);
            else
            {
                if(prices[i]<price.top())
                {
                    price.pop();
                    price.push(prices[i]);
                }
                else
                {
                    ans=max(ans,prices[i]-price.top());
                }
            }
        }
        return ans==INT_MIN? 0:ans;
    }
};
