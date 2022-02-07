class Solution {
public:
    char findTheDifference(string s, string t) {
        string x = s+t;
        char a = NULL;
        for(int i=0; i<x.size(); i++) {
           a ^= x[i];                       // All similar charcters will be eliminated
        }
        return a;
    }
};