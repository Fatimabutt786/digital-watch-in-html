

class TrieNode {
public:
    TrieNode* children[26] = {nullptr}; // Only for lowercase a-z
    int count = 0; // Count of words that pass through this node
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
            node->count++;
        }
    }

    int getPrefixScore(const std::string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c - 'a'];
            score += node->count;
        }
        return score;
    }

    ~Trie() {
        // Destructor to deallocate Trie memory
        clear(root);
    }

private:
    void clear(TrieNode* node) {
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        delete node;
    }
};

class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        Trie trie;

        // Insert all words into the Trie
        for (const std::string& word : words) {
            trie.insert(word);
        }

        // Calculate scores for each word
        std::vector<int> scores;
        for (const std::string& word : words) {
            scores.push_back(trie.getPrefixScore(word));
        }

        return scores;
    }
};
