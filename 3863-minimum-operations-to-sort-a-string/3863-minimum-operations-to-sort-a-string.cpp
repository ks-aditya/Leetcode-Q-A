class Solution {
public:
    int minOperations(string s) {
        
        int len = s.length();
        
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if(sorted == s) return 0;
        if(len <= 2) return -1;

        else{
            int minIdx = 0, maxIdx = 0;
            for(int i = 0; i < len; i++){
                if(s[i] < s[minIdx]) minIdx = i;
                if(s[i] >= s[maxIdx]) maxIdx = i;
            }
    
            if(s[minIdx] == s[0] || s[maxIdx] == s[len-1]) return 1;

            if (abs(maxIdx - minIdx) <= len - 2) {
                return 2;
            }
            return 3;
        }

        return -1;
    }
};