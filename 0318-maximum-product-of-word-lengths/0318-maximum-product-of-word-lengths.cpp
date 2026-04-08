class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        
        int n=words.size();
        vector<int>mask(n,0);

        for(int i=0;i<n;i++)
        {
            for(char k:words[i])
            {
                mask[i] |= (1<<(k-'a'));
            }
        }
        int product=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
        {
            if((mask[i] & mask[j]) == 0)
            {
                int x=words[i].size()*words[j].size();
                product=max(product,x);
            }
        }
        }
        return product;

    }
};