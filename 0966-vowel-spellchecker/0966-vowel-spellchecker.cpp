class Solution {
public:
    
    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }
    
    string devowel(string s) {
        for (char &c : s) {
            c = tolower(c);
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                c = '*';
        }
        return s;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        unordered_set<string> exact;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        
        // preprocess
        for (string word : wordlist) {
            exact.insert(word);
            
            string lower = toLower(word);
            string dev = devowel(word);
            
            if (!caseMap.count(lower))
                caseMap[lower] = word;
            
            if (!vowelMap.count(dev))
                vowelMap[dev] = word;
        }
        
        vector<string> ans;
        
        for (string q : queries) {
            
            // 1. exact match
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            
            string lower = toLower(q);
            
            // 2. case-insensitive
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            
            string dev = devowel(q);
            
            // 3. vowel match
            if (vowelMap.count(dev)) {
                ans.push_back(vowelMap[dev]);
                continue;
            }
            
            // 4. no match
            ans.push_back("");
        }
        
        return ans;
    }
};