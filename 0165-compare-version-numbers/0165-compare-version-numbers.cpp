class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        
        // Pointers to keep track of the current position in each version number
        int i = 0, j = 0;
        
        // Iterate until we reach the end of both version numbers
        while (i < n1 or j < n2) {
            // Initialize revision values for comparison
            int rev1 = 0, rev2 = 0;
            
            // Calculate the revision value for version1
            while (i < n1 and version1[i] != '.') {
                rev1 = rev1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Calculate the revision value for version2
            while (j < n2 and version2[j] != '.') {
                rev2 = rev2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // Compare the revision values
            if (rev1 < rev2) {
                return -1;
            } 
            else if (rev1 > rev2) {
                return 1;
            }
            
            // Move to the next revision in both version numbers
            i++;
            j++;
        }
        
        // // If all revisions are equal, check if there are any remaining revisions
        // while (i < n1) {
        //     int rev1 = 0;
        //     // Calculate the revision value for version1
        //     while (i < n1 and version1[i] != '.') {
        //         rev1 = rev1 * 10 + (version1[i] - '0');
        //         i++;
        //     }
        //     // If any remaining revision in version1 is non-zero, version1 > version2
        //     if (rev1 > 0) {
        //         return 1;
        //     }
        //     i++;
        // }
        
        // while (j < n2) {
        //     int rev2 = 0;
        //     // Calculate the revision value for version2
        //     while (j < n2 and version2[j] != '.') {
        //         rev2 = rev2 * 10 + (version2[j] - '0');
        //         j++;
        //     }
        //     // If any remaining revision in version2 is non-zero, version1 < version2
        //     if (rev2 > 0) {
        //         return -1;
        //     }
        //     j++;
        // }
        
        // If all revisions are equal and there are no remaining revisions, return 0
        return 0;
    }
};
