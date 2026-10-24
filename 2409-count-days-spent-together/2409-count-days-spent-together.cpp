class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // int cnt =0;
        // int a = stoi(arriveAlice.substr(0,2));
        // int b = stoi(leaveBob.substr(0,2));
        // if(a == b){
        //     int c = stoi(leaveAlice.substr(3,5));
        //     int d = stoi(arriveAlice.substr(3,5));
        //     cnt = c-d;
        // }
        // return cnt ;
         vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));

            for (int i = 0; i < m - 1; i++)
                d += days[i];

            return d;
        };

        int a = max(convert(arriveAlice), convert(arriveBob));
        int b = min(convert(leaveAlice), convert(leaveBob));

        return max(0, b - a + 1);
    }
};