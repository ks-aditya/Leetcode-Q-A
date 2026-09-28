class Solution {
public:
    string reverseParentheses(string s) {
        stack <string> st;
        string curr="";

        for(char c : s){
            if( c == '('){
              st.push(curr);
              curr = "";  
            }
            else if( c!= '(' && c!= ')') curr += c;
            else if ( c == ')'){
                reverse ( curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
        }
        
        return curr;
    }
};