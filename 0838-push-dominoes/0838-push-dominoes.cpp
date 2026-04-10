class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n = dominoes.size();
        string s = "L" + dominoes + "R";
        int i = 0;

        for (int j = 1; j < s.size(); j++) 
        {
            if (s[j] == '.') continue;

            int middle = j - i - 1;

            if (s[i] == s[j]) 
            {
                for (int k = i + 1; k < j; k++) {
                    s[k] = s[i];
                }
            } 
            else if (s[i] == 'R' && s[j] == 'L') 
            {
                int left = i + 1;
                int right = j - 1;

                while (left < right) {
                    s[left++] = 'R';
                    s[right--] = 'L';
                }
                
            }
           

            i = j;
        }

       
        return s.substr(1, n);
    }
};