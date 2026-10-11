 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.empty() || s.empty()) return ans;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowLen = wordLen * totalWords;

        if (n < windowLen) return ans;

        unordered_map<string, int> wordCount;

        for (string &word : words) {
            wordCount[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> seen;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.find(word) == wordCount.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > wordCount[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }

                if (count == totalWords) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return ans;
    }
};
 