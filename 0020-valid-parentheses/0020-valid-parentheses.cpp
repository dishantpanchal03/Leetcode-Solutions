class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            myStack.push(s[i]);
            }
            else{ 
                if(myStack.empty())  return false;
                if((myStack.top() == '(' && s[i]==')') ||
                   (myStack.top() == '[' && s[i]==']') ||
                   (myStack.top() == '{' && s[i]=='}'))
                {
                myStack.pop();
                }
                else return false;            
            }
        }
        return myStack.empty();
    }
};