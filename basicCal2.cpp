
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> mystack;
        int currNum = 0;
        char op = '+'; 

        for (int i = 0; i < n; i++) {
            char currChar = s[i];

            if (isdigit(currChar)) {
                currNum = (currNum * 10) + (currChar - '0'); 
            }

            if (!isdigit(currChar) && !iswspace(currChar) || i == n - 1) {
                if (op == '-') {
                    mystack.push(-currNum);
                } else if (op == '+') {
                    mystack.push(currNum);
                } else if (op == '*') {
                    int top = mystack.top();
                    mystack.pop();
                    mystack.push(top * currNum);
                } else if (op == '/') {
                    int top = mystack.top();
                    mystack.pop();
                    mystack.push(top / currNum);
                }

                op = currChar; // Update the operator
                currNum = 0;   // Reset the number
            }
        }

        int result = 0;
        while (!mystack.empty()) {
            result += mystack.top();
            mystack.pop();
        }

        return result;
    }
};
