class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";

        while(num>0){
            if(sum<=9){
                ans += to_string(sum);
                sum = 0;
            }
            else{
                sum -= 9;
                ans += to_string(9);
            }
            num--;
        }
        if(sum!=0) return "";
        return ans;
    }
};