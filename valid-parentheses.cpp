class Solution {
    public:
        bool isValid(string s) {
            stack<char> validate;
            for(int i = 0; i != s.size(); ++i){
                if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                    validate.push(s[i]);
                else{
                    if(validate.size() == 0)
                        return false;
                    else{
                        if(s[i] == ')'){
                            if(validate.top() == '('){
                                validate.pop();
                            }
                            else return false;
                        }
                        else if(s[i] == '}'){
                            if(validate.top() == '{'){
                                validate.pop();
                            }
                            else return false;
                        }
                        else if(s[i] == ']'){
                            if(validate.top() == '['){
                                validate.pop();
                            }
                            else return false;
                        }
                    }
                }
            }
            if(validate.size() == 0)
                return true;
            else return false;
        }
};
