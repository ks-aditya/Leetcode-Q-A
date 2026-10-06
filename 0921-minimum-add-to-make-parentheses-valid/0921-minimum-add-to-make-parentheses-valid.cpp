class Solution {
public:
    int minAddToMakeValid(string s) {
        

        // own thinking and solution.
        stack<char> st;
        int open = 0;
        int close = 0;

        for(char c : s){
            if(c=='('){
                open++;
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    open--;
                }else{
                    close++;
                }
            }
        }
        return open+close;
    }
};