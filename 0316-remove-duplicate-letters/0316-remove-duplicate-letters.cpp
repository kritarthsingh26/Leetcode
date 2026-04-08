class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        
        stack<char>st;
        vector<int>last_occurence(26,-1);
        vector<bool>visited(26,false);

        for(int i=0;i<s.size();i++)
        {
            last_occurence[s[i]-'a']=i;

        }

          for(int i=0;i<s.size();i++)
          {
            char k=s[i];
            if(visited[k-'a']) continue;
            
          

        while(!st.empty() && st.top()>s[i] && last_occurence[st.top()-'a']>i)
        {
            visited[st.top()-'a']=false;

            st.pop();
        }
        st.push(s[i]);
        visited[s[i]-'a']=true;
          }
        string answer="";

        while(!st.empty())
        {
           char k=st.top();
            st.pop();
            answer+=k;

        }
        reverse(answer.begin(),answer.end());

        return answer;


    }
};