class Solution {
public:
    vector<string> ans;

    void makeParenthesis(vector<string>& ans, int n, int strlen, int score, char c, string str) {

        if (c == '(')
            score += 1;
        else if (c == ')')
            score -= 1;

        str += c;
        ++strlen;

        if (strlen == n && score == 0) {
            ans.push_back(str);
            return;
        } else if (strlen < n && score >= 0 && score <= n / 2) {
            makeParenthesis(ans, n, strlen, score, '(', str);
            makeParenthesis(ans, n, strlen, score, ')', str);
        } else return;
    }

    vector<string> generateParenthesis(int n) {

        int strlen = 0;
        int maxchar = 2 * n;
        int score = 0;
        string str = "";

        makeParenthesis(ans, maxchar, strlen, score, '(', str);

        return ans;
    }
};