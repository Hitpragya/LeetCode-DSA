class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aliceStart = convertToDate(arriveAlice, daysInMonth);
        int aliceEnd = convertToDate(leaveAlice, daysInMonth);
        int bobStart = convertToDate(arriveBob, daysInMonth);
        int bobEnd = convertToDate(leaveBob, daysInMonth);

        int overlapStart = max(aliceStart, bobStart);
        int overlapEnd = min(aliceEnd, bobEnd);

        return max(0, overlapEnd - overlapStart + 1);
    }

private:
    int convertToDate(string date, vector<int>& daysInMonth) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int dayOfYear = 0;
        for (int currentMonth = 0; currentMonth < month - 1; currentMonth++) {
            dayOfYear += daysInMonth[currentMonth];
        }

        return dayOfYear + day;
    }
};