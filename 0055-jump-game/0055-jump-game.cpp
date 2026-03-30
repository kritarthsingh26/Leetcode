class Solution {
public:
            int t[10001];
        bool helper(vector<int>& nums,int index)
        {
            if(index>=nums.size()-1)
            {
                return true;
            }
           
            if(t[index]!=-1)
            {
                return t[index];
            }

            for(int i=1;i<=nums[index];i++)
            {
               if(helper(nums,index+i))
               {
                return t[index]=true;
               }
            }
            return t[index]=false;
        }
    bool canJump(vector<int>& nums) 
    {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        
        return helper(nums,0);

    }
};