class Solution {
public:
    int first_occurence(vector<int>& nums, int target)
    {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int answer=-1;
        while(start<=end)
        {
            
            int mid=start+(end-start)/2;

            if(nums[mid]==target)
            {
                answer=mid;
                end=mid-1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
           


           
    }
     return answer;
    }
    int last_occurence(vector<int>& nums, int target)
    {
          int n=nums.size();
        int start=0;
        int end=n-1;
        int answer=-1;
        while(start<=end)
        {
           
            int mid=start+(end-start)/2;

            if(nums[mid]==target)
            {
                answer=mid;
                start=mid+1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
           


        }   
         return answer;
    }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>result;

        result.push_back(first_occurence(nums,target));
        result.push_back(last_occurence(nums,target));

        return result ;
    }
};