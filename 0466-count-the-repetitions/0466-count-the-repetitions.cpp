class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;

        int s1_count = 0, s2_count = 0;
        int j = 0;

        unordered_map<int, pair<int,int>> mp;

        while (s1_count < n1) {
            s1_count++;

            for (char c : s1) {
                if (c == s2[j]) {
                    j++;
                    if (j == s2.size()) {
                        j = 0;
                        s2_count++;
                    }
                }
            }

            // cycle detection
            if (mp.count(j)) {
                auto [prev_s1, prev_s2] = mp[j];

                int cycle_len_s1 = s1_count - prev_s1;
                int cycle_len_s2 = s2_count - prev_s2;

                int remaining_s1 = n1 - s1_count;

                int cycles = remaining_s1 / cycle_len_s1;

                // skip cycles
                s1_count += cycles * cycle_len_s1;
                s2_count += cycles * cycle_len_s2;
            } else {
                mp[j] = {s1_count, s2_count};
            }
        }

        return s2_count / n2;
    }
};