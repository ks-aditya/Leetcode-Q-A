class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int sum = 0;

        for(int i = 0; i<nums.size(); i++){

            unordered_set<int> st;
            int count = 0;

            for(int j = i; j<nums.size(); j++){

                if(st.find(nums[j]) == st.end()){
                    st.insert(nums[j]);
                    count++;
                }

                sum += (count*count);
            }
        }
        return sum;
    }
};