class Solution {
public:
    bool judgeCircle(string moves) 
    {
       int x=0;
       int y=0;
       int n=moves.size();

        for(int i=0;i<n;i++)
        {
            if(moves[i]=='U')
            {
               x++;
            }
            if(moves[i]=='D')
            {
                 x--;
            }
             if(moves[i]=='L')
            {
               y++;
            }
             if(moves[i]=='R')
            {
                y--;
            }

        }  
        
            if(x==0 && y==0)
            {
                return true;
            }
        
         return false;
    }
};