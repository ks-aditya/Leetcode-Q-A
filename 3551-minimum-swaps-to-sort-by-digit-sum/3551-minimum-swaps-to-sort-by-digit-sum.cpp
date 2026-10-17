class Solution {
public:

    int Sumofdigits(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int swaps = 0;
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2){
            int DigitSumNum1 = Sumofdigits(num1);
            int DigitSumNum2 = Sumofdigits(num2);

            if(DigitSumNum1 != DigitSumNum2) return DigitSumNum1 < DigitSumNum2;
            return num1 < num2;
        };

        sort(begin(afterSorted), end(afterSorted), lambda);

        unordered_map <int,int> ValtoIdx;

        for(int i = 0; i < n; i++){
            ValtoIdx[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){
            int expectedVal = afterSorted[i];
            int currentVal = nums[i];

            int reqIdx = ValtoIdx[expectedVal];

            if(expectedVal != currentVal){
                nums[i] = expectedVal;
                nums[reqIdx] = currentVal;

                swaps++;

                ValtoIdx[currentVal] = reqIdx;
                ValtoIdx[expectedVal] = i;
            }

        }

        return swaps;
    }
};