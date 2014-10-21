class Solution {
    public:
        string simplifyPath(string path) {
            list<string> s;
            string tmp, result;
            for(int i = 0; i != path.size(); ++i){
                if(path[i] == '/'){
                    if(tmp.size() == 0) continue;
                    else if(tmp == ".."){
                        if(s.size() != 0) s.pop_back();
                    }else if(tmp == "."){
                    }else{
                        s.push_back(tmp);
                    }
                    tmp.clear();
                }else{
                    tmp.push_back(path[i]);
                }
            }
            if(tmp.size() != 0){
                if(tmp == ".."){
                    if(s.size() != 0) s.pop_back();
                }else if(tmp == "."){
                }else{
                    s.push_back(tmp);
                }
            }
            if(s.size() == 0) result = "/";
            else{
                list<string>::iterator iter;
                for(iter = s.begin(); iter != s.end(); iter++){
                    result.push_back('/');
                    result += *iter;
                }
            }
            return result;
        }
};
