class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int minLength = INT_MAX;
        int start = 0;
        int left = 0;
        int right = 0;

        unordered_map<char, int> t_count, window_count;

        for (char c : t) t_count[c]++;

        int required = t_count.size();
        int formed = 0;

        while (right < s.size()) {
            char c = s[right];
            window_count[c]++;

            if (t_count.find(c) != t_count.end() && window_count[c] == t_count[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s[left];

                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                window_count[c]--;
                if (t_count.find(c) != t_count.end() && window_count[c] < t_count[c]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};
