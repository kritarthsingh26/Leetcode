class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        // 3 loop ko reduce karne ke liye hm ek ki position fix kar denge aur baki do to two pointers ki help se move karenge

        int n=nums.size();

            int closest_sum=nums[0]+nums[1]+nums[2];
            int current_sum=0;

            for(int i=0;i<n-2;i++)
            {
                int left=i+1;
                int right=n-1;

                while(left<right)
                {

                    current_sum=nums[i]+nums[left]+nums[right];

                    if(abs(target-current_sum)<abs(target-closest_sum))
                    {
                        closest_sum= current_sum;
                    }


                    //// kaha move karenge aur kb hm target ke aur pass jaege

                    if( current_sum<target)
                    {
                        left++;
                    }
                    else if(current_sum>target)
                    {
                        right--;
                    }
                    else
                    {
                        return target;
                    }


                }
            }
            return  closest_sum;

    }
};