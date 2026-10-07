class Solution {
public:
    vector<string> ans;

    void generate(string &s, int idx, int removeOpen, int removeClose,
                  string curr, int score) {

        if (idx == s.size()) {
            if (removeOpen == 0 && removeClose == 0 && score == 0) {
                ans.push_back(curr);
            }
            return;
        }

        // Remove this '('
        if (s[idx] == '(' && removeOpen > 0) {
            generate(s, idx + 1, removeOpen - 1, removeClose,
                     curr, score);
        }

        // Remove this ')'
        if (s[idx] == ')' && removeClose > 0) {
            generate(s, idx + 1, removeOpen, removeClose - 1,
                     curr, score);
        }

        // Keep this character
        if (s[idx] == '(') {
            generate(s, idx + 1, removeOpen, removeClose,
                     curr + s[idx], score + 1);
        }
        else if (s[idx] == ')') {
            if (score > 0) {
                generate(s, idx + 1, removeOpen, removeClose,
                         curr + s[idx], score - 1);
            }
        }
        else {
            generate(s, idx + 1, removeOpen, removeClose,
                     curr + s[idx], score);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int open = 0;
        int removeOpen = 0;
        int removeClose = 0;

        // Find how many '(' and ')' actually need removal
        for (char c : s) {
            if (c == '(') {
                open++;
            }
            else if (c == ')') {
                if (open > 0)
                    open--;
                else
                    removeClose++;
            }
        }

        removeOpen = open;

        generate(s, 0, removeOpen, removeClose, "", 0);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};