class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        // int cnt =0;
        // int a = stoi(date1.substr(0,4));
        // int b =  stoi(date2.substr(0,4));
        // int d = stoi(date2.substr(5,2));
        // int c = stoi(date1.substr(5,2));
        // int y = stoi(date2.substr(8,2));
        // int x = stoi(date1.substr(8,2));
        // if(a == b){
        //     return y-x;
        // }
        //  return y-x-1;
        return abs(convert(date1) - convert(date2));
    }
    int convert(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int total = 0;

        for (int y = 1971; y < year; y++) {
            total += 365;
            if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
                total++;
        }

        if (year % 4 == 0 &&
            (year % 100 != 0 || year % 400 == 0))
            days[1] = 29;

        for (int m = 0; m < month - 1; m++)
            total += days[m];

        return total + day;
    }
};