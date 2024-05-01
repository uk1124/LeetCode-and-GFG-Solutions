class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.find(ch) > word.size()) {
            return word;
        }

        int indx = word.find(ch);
        reverse(word.begin(), word.begin()+indx+1);
        return word;
    }
};