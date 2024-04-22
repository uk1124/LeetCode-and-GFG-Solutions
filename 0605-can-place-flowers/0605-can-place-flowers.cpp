class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size(); i++) {
            if(flowerbed[i] == 1) {
                i += 1;
                continue;
            }
            n -= 1;
            i += 1;
        }
        return n == 0;
    }
};