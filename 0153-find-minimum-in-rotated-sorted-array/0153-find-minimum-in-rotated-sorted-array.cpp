class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(n == 1) return nums[0];
        if(nums[start] < nums[end]) return nums[start];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;

            if (nums[prev] >= nums[mid] && nums[next] >= nums[mid])
            {
                return nums[mid];
            }
            
            else if(nums[mid]<=nums[end])
            
            {
                end=mid-1;
            }
            else 
            {
                start=mid+1;
            }
        }
        return -1;
    }
};