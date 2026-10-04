class Solution {
public:
    bool checkValidString(string s) {
        int MinNumOfLeftParenthesis = 0, MaxNumOfLeftParenthesis = 0;
        for(char c: s){
            if(c=='('){
                MinNumOfLeftParenthesis++;
                MaxNumOfLeftParenthesis++;
            }
            else if(c==')'){
                MinNumOfLeftParenthesis--;
                MaxNumOfLeftParenthesis--;
            }
            else{
                MinNumOfLeftParenthesis--; // if * is ')' then '(' number decreases.
                MaxNumOfLeftParenthesis++;  // if * is '(' then '(' number increases.
            }

            if(MaxNumOfLeftParenthesis < 0) return false;
            MinNumOfLeftParenthesis = max(0, MinNumOfLeftParenthesis);
        }
        if(0>=MinNumOfLeftParenthesis  && 0<=MaxNumOfLeftParenthesis ) return true;
        else return false;
    }
};