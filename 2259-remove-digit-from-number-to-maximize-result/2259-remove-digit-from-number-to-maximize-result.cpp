class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<long long> v;
        set<string> st;
        for(int i=0; i<number.size(); i++) {
            if(number[i] == digit) {
                string s = number;
                s.erase(s.begin() + i);
                st.insert(s);
            }
        }
        string ans = *(--st.end());
        return ans;
    }
};