class Solution {
public:
    
    string addStrings(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool check(string num, int start, string a, string b) {
        if (start == num.size()) return true;
        
        string c = addStrings(a, b);
        
        if (num.substr(start, c.size()) != c)
            return false;
        
        return check(num, start + c.size(), b, c);
    }
    
    bool isAdditiveNumber(string num) {
        int n = num.size();
        
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                
                string a = num.substr(0, i);
                string b = num.substr(i, j - i);
                
                if ((a.size() > 1 && a[0] == '0') ||
                    (b.size() > 1 && b[0] == '0'))
                    continue;
                
                if (check(num, j, a, b))
                    return true;
            }
        }
        
        return false;
    }
};