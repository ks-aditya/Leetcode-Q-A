class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long totalCost = 0;

        if(1LL * cost1 + cost2 < costBoth){
            totalCost = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }

        else {
            long long remain = abs(1LL * need2 - need1);

            if(need1 <= need2){
                totalCost = 1LL * costBoth * need1 +
                            min(remain * cost2, remain * costBoth);
            }
            else {
                totalCost = 1LL * costBoth * need2 +
                            min(remain * cost1, remain * costBoth);
            }
        }

        return totalCost;
    }
};