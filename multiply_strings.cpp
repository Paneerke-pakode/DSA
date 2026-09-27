// Given two non-negative integers num1 and num2 represented as strings, 
// return the product of num1 and num2, also represented as a string.
//Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1+n2, 0);

        for (int i = n1-1; i>=0; i--){
            for (int j = n2-1; j>=0; j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int sum = mul + result[i+j+1];
                result[i+j+1] = sum % 10;
                result[i+j] += sum / 10;
            }
        }

        string res;

        for (int num : result) 
            if (!(res.empty() && num == 0)) 
                res += to_string(num);

        return res.empty() ? "0" : res;
    }
};
