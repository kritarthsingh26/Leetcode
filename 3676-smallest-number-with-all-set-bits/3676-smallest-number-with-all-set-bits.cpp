class Solution {
public:
    int Binary(int n)
    {
        long long b=0;
        long long place=1;
        while(n>0)
        {
            int r=n%2;
            b+=r*place;
            n/=2;
            place*=10;
        }
        return b;
    }
    int count(int n)
    {
        int c=1;
        while(n>0)
        {
            n/=10;
            c++;
        }
        return c-1;
    }
    int smallestNumber(int n) 
    {
        int number=Binary(n);
        int k=count(number);
        int result=pow(2,k)-1;

        return result;
        

    }
};