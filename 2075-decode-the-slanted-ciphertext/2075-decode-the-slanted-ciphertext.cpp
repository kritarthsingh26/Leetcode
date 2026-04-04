class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) 
    {
        int n=encodedText.size();
        
        int col=n/rows;
        string or_text;

        for(int i=0;i<col;i++)
        {
            for(int j=i;j<n;j+=(col+1))
            {
                or_text+=encodedText[j];
            }
        }
        while(!or_text.empty() && or_text.back()==' ')
        {
            or_text.pop_back();
        }

        return or_text;
    }
};