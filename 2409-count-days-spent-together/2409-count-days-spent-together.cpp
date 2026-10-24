class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // prefix[m] = number of days before month m+1 starts
        int prefix[13] = {0};
        for (int i = 0; i < 12; i++) prefix[i + 1] = prefix[i] + monthDays[i];

        auto toDay = [&](const string& s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));
            return prefix[month - 1] + day;
        };

        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));

        return max(0, end - start + 1);
    }
};