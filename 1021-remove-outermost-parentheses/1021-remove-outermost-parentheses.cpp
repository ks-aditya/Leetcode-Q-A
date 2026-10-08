class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int>idx;
        string ans;

        int score = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                if(score==0) idx.push_back(i);
                score++;
            }
            else{
                score--;
                if(score==0) idx.push_back(i);
            }
        }
        for(int i: idx) s[i]='*';
        for(char c: s) if(c!='*') ans+=c;

        return ans;
    }
};