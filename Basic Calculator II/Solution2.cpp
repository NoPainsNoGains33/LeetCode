class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        int result = 0, currentNumber = 0;
        int lastNumber = 0;
        char operation = '+', currentChar;
        for (int i = 0; i < len; i++){
            currentChar = s[i];
            if (isdigit (currentChar))
                currentNumber = currentNumber * 10 + (currentChar - '0');               
            if (!isdigit (currentChar) && !iswspace(currentChar) || i == len - 1){
                if (operation == '+' || operation == '-'){
                    result = result + lastNumber;
                    lastNumber = (operation == '+')? currentNumber: -currentNumber;
                }
                else{
                    if (operation == '*')
                        lastNumber = lastNumber * currentNumber;
                    else
                        lastNumber = lastNumber / currentNumber;
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
};
