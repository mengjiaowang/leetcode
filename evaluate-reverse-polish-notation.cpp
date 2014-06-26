class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            if(tokens.size() == 0) return 0;
            stack<int> s;
            for(int i = 0; i != tokens.size(); ++i){
                if(tokens[i].compare("+") == 0){
                    int op1 = s.top(); s.pop();
                    int op2 = s.top(); s.pop();
                    s.push(op1+op2);
                }
                else if(tokens[i].compare("-") == 0){
                    int op1 = s.top(); s.pop();
                    int op2 = s.top(); s.pop();
                    s.push(op2-op1);               
                }
                else if(tokens[i].compare("*") == 0){
                    int op1 = s.top(); s.pop();
                    int op2 = s.top(); s.pop();
                    s.push(op2*op1);               
                }else if(tokens[i].compare("/") == 0){
                    int op1 = s.top(); s.pop();
                    int op2 = s.top(); s.pop();
                    s.push(op2/op1);               
                }
                else{
                    int num = 0, factor = 1;
                    for(int j = tokens[i].size() - 1; j >= 0 ; --j){
                        if(tokens[i][j] == '-') num *= -1;
                        else{
                            num += (tokens[i][j] - '0') * factor;
                            factor *= 10;
                        }
                    }
                    s.push(num);  
                } 
            }
            return s.top();
        }
};
