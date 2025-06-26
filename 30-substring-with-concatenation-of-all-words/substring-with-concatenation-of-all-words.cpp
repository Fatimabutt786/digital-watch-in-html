class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLength = words[0].length();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;

        // Store the frequency of each word
        unordered_map<string, int> wordFreq;
        for (string& word : words) {
            wordFreq[word]++;
        }

        // Loop through all possible starting points within word length
        for (int i = 0; i < wordLength; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j <= (int)s.length() - wordLength; j += wordLength) {
                string word = s.substr(j, wordLength);
                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    // If word appears more than required, slide window
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seen[leftWord]--;
                        left += wordLength;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset if word not found
                    seen.clear();
                    count = 0;
                    left = j + wordLength;
                }
            }
        }

        return result;
    }
};
