class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left pointer until vowel
            while (left < right && !isVowel(s[left])) left++;

            // Move right pointer until vowel
            while (left < right && !isVowel(s[right])) right--;

            // Swap vowels
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};