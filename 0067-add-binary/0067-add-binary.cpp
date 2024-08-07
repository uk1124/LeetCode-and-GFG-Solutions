class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        
        string ans = "";
        int carry = 0;
        
        while(i>=0 || j>=0 || carry==1)
        {
            int adigit = (i>=0) ? a[i]-'0' : 0;
            int bdigit = (j>=0) ? b[j]-'0' : 0;
            
            int sum = (adigit + bdigit + carry);
            
            ans = char(sum%2 +'0') + ans;   
            carry = sum/2;
            
            i--;
            j--;
        }
       return ans; 
    }
};