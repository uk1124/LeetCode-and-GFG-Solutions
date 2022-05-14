class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
          return "1";
        }
        
        if(n == 2) {
          return "11";
        }
          
        string str = "11";
        
        for(int i=3; i<=n; i++) {
             str += '$';
             int n = str.length();
             
             int count = 1;
             string temp = "";
             
             for(int j=1; j<n; j++) {
                  if(str[j] != str[j-1]) {
                        temp += count + '0';
                        temp = temp + str[j-1];
                        count = 1;
                    }
                   else {
                     count++;
                   }
              }
            str = temp;  
         }
        return str;
    }
};