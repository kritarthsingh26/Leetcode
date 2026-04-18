class Solution {
public:
    int mirrorDistance(int n) 
    {
        int k=n;
        int num=0;
        int r;

        while(k>0)
        {
            r=k%10;
            num=(num*10)+r;
            k=k/10;

        }   

        return abs(num-n); 
    }
};