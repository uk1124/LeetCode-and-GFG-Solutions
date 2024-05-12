class Solution {
public:
  int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    int ans = INT_MIN;

    // Loop through magicians starting from n-k-1 (potential starting points)
    for (int j = n-k-1; j >= 0; j--) {
      // Attempt to add energy from k jumps ahead (flawed logic)
      energy[j] += energy[j + k];
    }

    // Loop through all magicians to find the maximum energy
    for (int i = 0; i < n; i++) {
      ans = max(ans, energy[i]);
    }

    // Return the maximum energy achievable
    return ans;
  }
};
