class Solution {
public:
    unordered_map<int, bool> dp;
    
    bool solve(int mask, int remaining, int maxNum)
    {
        if(dp.count(mask)) return dp[mask];
        
        for(int i = 1; i <= maxNum; i++)
        {
            if(!(mask & (1 << i))) // not used
            {
                // if current player can win directly
                if(i >= remaining)
                    return dp[mask] = true;
                
                // opponent loses
                if(!solve(mask | (1 << i), remaining - i, maxNum))
                    return dp[mask] = true;
            }
        }
        
        return dp[mask] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) 
    {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        
        if(sum < desiredTotal) return false;
        if(desiredTotal <= 0) return true;
        
        return solve(0, desiredTotal, maxChoosableInteger);
    }
};