class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;
        int val;
        st.push(0);

        for(char c : s){
            if( c == '(') st.push(0);
            else{
                int inner = st.top();
                st.pop();
                
                (inner == 0) ? val = 1 : val = 2*inner ;
                st.top() += val;
            }
        }
        return st.top();
    }
};