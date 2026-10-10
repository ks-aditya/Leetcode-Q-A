class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            } else {
                // Case: a single ')' without another ')' after it
                if (i + 1 == s.size() || s[i + 1] != ')') {
                    insertions++;
                } else {
                    // Consume the second ')'
                    i++;
                }

                // We now have a pair of closing parentheses
                if (open > 0) {
                    open--;
                } else {
                    // No '(' available to match this pair
                    insertions++;
                }
            }
        }

        return insertions + 2 * open;
    }
};