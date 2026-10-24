class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // converts "MM-DD" to day of the year
        auto toDay = [&](string s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));

            int total = 0;
            for (int i = 0; i < month - 1; i++) {
                total += monthDays[i];   // add all full months before this one
            }
            return total + day;
        };

        int start = max(toDay(arriveAlice), toDay(arriveBob));  // later arrival
        int end = min(toDay(leaveAlice), toDay(leaveBob));      // earlier leave

        return max(0, end - start + 1);
    }
};