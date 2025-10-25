class Solution {
public:
    int totalMoney(int n) 
    {int weeks = n / 7;   // number of complete weeks
        int days = n % 7;    // remaining days in the last week

        // Money from complete weeks:
        // Each week adds 28 + 7*(week_index)
        int total = (weeks * (weeks - 1) / 2) * 7 + weeks * 28;

        // Money from remaining days (partial week)
        int start = weeks + 1;
        total += days * start + (days * (days - 1)) / 2;

        return total;
    }

};