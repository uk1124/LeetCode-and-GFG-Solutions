class Solution {
public:
    bool hasTwoInTernary(int number) {
    while (number > 0) {
        if (number % 3 == 2) {
            return true;
        }
        number /= 3;
    }
    return false;
}

    bool checkPowersOfThree(int n) {
        return !hasTwoInTernary(n);
    }
};