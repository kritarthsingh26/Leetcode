class Solution {
public:
    int findClosest(int x, int y, int z) 
    {
        int k=abs(x-z);
        int l=abs(y-z);

        if(k<l)
        {
            return 1;
        }
        else if(l==k)
        {
            return 0;
        }
        else

        {
            return 2;
        }
        return -1;

    }
};