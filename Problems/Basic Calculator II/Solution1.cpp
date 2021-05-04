class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        int result = 0, currentNumber = 0;
        stack<int> stack;
        int multipleNumber = 1;
        char operation = '+', currentChar;
        for (int i = 0; i < len; i++){
            currentChar = s[i];
            if (isdigit (currentChar)){
                currentNumber = currentNumber * 10 + (currentChar - '0');
                multipleNumber = currentNumber;
            }
                
            if (!isdigit (currentChar) && !iswspace(currentChar) || i == len - 1){
                if (operation == '+'){
                    stack.push(currentNumber);
                    operation = currentChar;
                    currentNumber = 0;
                }
                else{
                    if (operation == '-'){
                        stack.push(-currentNumber);
                        operation = currentChar;
                        currentNumber = 0;
                    }
                    else {
                        if (operation == '*'){
                            currentNumber = currentNumber * stack.top();
                            stack.pop();
                            stack.push(currentNumber);
                            operation = currentChar;
                            currentNumber = 0;
                        }
                        else{
                            currentNumber = stack.top() / currentNumber;
                            stack.pop();
                            stack.push(currentNumber);
                            operation = currentChar;
                            currentNumber = 0;
                        }
                    }
                }
            }
        }
        while (stack.size() != 0){
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};
