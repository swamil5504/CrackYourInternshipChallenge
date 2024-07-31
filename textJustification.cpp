class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].length();
            int last = index + 1;

            // Determine the last word that fits on the current line
            while (last < n) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length();
                last++;
            }

            string sb;
            int diff = last - index - 1; // number of gaps between words

            // If this is the last line or contains only one word, left-justify
            if (last == n || diff == 0) {
                for (int i = index; i < last; i++) {
                    sb += words[i];
                    if (i < last - 1) {
                        sb += " ";
                    }
                }
                int remainingSpaces = maxWidth - sb.length();
                appendSpaces(sb, remainingSpaces);
            } else {
                int spaces = (maxWidth - totalChars) / diff;
                int extraSpaces = (maxWidth - totalChars) % diff;

                for (int i = index; i < last; i++) {
                    sb += words[i];
                    if (i < last - 1) {
                        int spacesToApply = spaces + (i - index < extraSpaces ? 1 : 0);
                        appendSpaces(sb, spacesToApply + 1); // one space for word separation
                    }
                }
            }
            result.push_back(sb);
            index = last;
        }

        return result;
    }

private:
    void appendSpaces(string& sb, int count) {
        for (int i = 0; i < count; i++) {
            sb += " ";
        }
    }
};
