class Solution {
public:
    vector<string> ans;

    void generate(string str, int open, int close, int n) {

    if (str.length() == 2 * n) {
        ans.push_back(str);
        return;
    }

    if (open < n)
        generate(str + '(', open + 1, close, n);

    if (close < open)
        generate(str + ')', open, close + 1, n);
}

    vector<string> generateParenthesis(int n) {

        generate("", 0, 0, n);
        return ans;
    }
};