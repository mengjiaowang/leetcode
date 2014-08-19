class Solution {
public:
    bool isNumber(const char *s){
    
        int len = strlen(s);
        int preState = -1;
        int curState = -1;
    
        int e = 0;
        int digit = 0;
        int dot = 0;
    
        // -1 -> start
        //  0 -> space
        //  1 -> space before digit
        //  2 -> space after digit
        //  10 -> digit
        //  11 -> digit before E
        //  12 -> digit after E
        //  20 -> dot 
        //  30 -> E or e
        //  40 -> minus or plus
    
        for(int i = 0; i != len; ++i){
            // determin current state
            if(s[i] == ' ') curState = 0;
            else if(isdigit(s[i])) {curState = 10; ++digit;}
            else if(s[i] == '.') {curState = 20; ++dot;}
            else if(s[i] == 'E' || s[i] == 'e') {curState = 30; ++e;}
            else if(s[i] == '-' || s[i] == '+') curState = 40;
            else return false;
    
            // judge if the current is valid
            if(curState == 20 && e > 0) return false; // dot after E is invalid
            if(curState == 20 && dot > 1) return false; // dot after dot is invalid
            if(curState == 30 && digit == 0) return false; // no number before E is invalid
            if(e > 1) return false; // more than one E is invalid
            
            // judge if the current is valid given previous state
            if(preState == -1){ // start -> space | digit | dot | minus
                if(curState == 10 || curState == 20 || curState == 40) 
                    preState = curState;
                else if(curState == 0) preState = 1;
                else return false;
            }
            else if(preState == 1){ // space_b -> space_b | digit | dot | -/+
                if(curState == 10 || curState == 20 || curState == 40)
                    preState = curState;
                else if(curState == 0) preState = 1;
                else return false;
            }
            else if(preState == 2){ // space_a -> space_a | stop
                if(curState == 0) preState = 2;
                else return false;
            }
            else if(preState == 10){ // digit -> space_a | digit | dot | E/e 
                if(curState == 10 || curState == 20 || curState == 30)
                    preState = curState;
                else if(curState == 0) preState = 2;
                else return false;
            }
            else if(preState == 20){ // dot -> digit | space | E/e
                if(curState == 10 || curState == 30)
                    preState = curState;
                else if(curState == 0 && digit > 0) preState = 2;
                else return false;
            }
            else if(preState == 30){ // E/e -> digit | minus
                if(curState == 10 || curState == 40)
                    preState = curState;
                else return false;
            }
            else if(preState == 40){ // -/+ -> digit
                if(curState == 10 || curState == 20)
                    preState = curState;
                else return false;
            }
        }
    
        if(preState == 2 || preState == 10) return true;
        if(preState == 20 && digit > 0) return true;
        else return false;
    }
};
