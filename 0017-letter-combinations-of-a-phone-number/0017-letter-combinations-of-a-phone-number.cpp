class Solution {
public:
        vector<string>answer;
        void helper(int index,string digits, unordered_map<char,string>mapping,string &result)
        {
            if(index==digits.size())
            {
                answer.push_back(result);
                return;
            }
            char ch=digits[index];

            for(char k:mapping[ch])
            {
                result+=k;
                helper(index+1,digits,mapping,result);
                result.pop_back();
            }
        }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0) return {};
        unordered_map<char,string>mapping;

        mapping['2']={"abc"};
        mapping['3']={"def"};
        mapping['4']={"ghi"};
        mapping['5']={"jkl"};
        mapping['6']={"mno"};
        mapping['7']={"pqrs"};
        mapping['8']={"tuv"};
        mapping['9']={"wxyz"};

        string result="";

        helper(0,digits,mapping,result);
        return answer;
    }
};