class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n=s.size();
        int count=0;
        int lastCount=0;
        for(char k:s)
        {
            if(k==' ')
            {
                if(count>0)
                {
                    lastCount=count;
                count=0;
                }
            }
            else
            {

            count++;
            }
        }   
        return count>0?count:lastCount; 
    }
};