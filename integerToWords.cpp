class Solution {
public:
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string completeWord(int n, string s) {
        string ans = "";
        if (n >= 100) {
            ans += ones[n / 100] + " Hundred";
            n %= 100;
        }
        if (n < 20) {
            if (!ans.empty() && n > 0) ans += " ";
            ans += ones[n];
        } else {
            if (!ans.empty() && n > 0) ans += " ";
            ans += tens[n / 10];
            if (n % 10 != 0) ans += " " + ones[n % 10];
        }
        if (!ans.empty() && !s.empty()) ans += " " + s;
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result;

        if (num / 1000000000 > 0) {
            result += completeWord(num / 1000000000, "Billion");
            num %= 1000000000;
        }

        if (num / 1000000 > 0) {
            if (!result.empty()) result += " ";
            result += completeWord(num / 1000000, "Million");
            num %= 1000000;
        }

        if (num / 1000 > 0) {
            if (!result.empty()) result += " ";
            result += completeWord(num / 1000, "Thousand");
            num %= 1000;
        }

        if (num / 100 > 0) {
            if (!result.empty()) result += " ";
            result += completeWord(num / 100, "Hundred");
            num %= 100;
        }

        if (num > 0) {
            if (!result.empty()) result += " ";
            if (num < 20) {
                result += ones[num];
            } else {
                result += tens[num / 10];
                if (num % 10 != 0) result += " " + ones[num % 10];
            }
        }

        return result;
    }
};
