#include<iostream>
#include<vector>
using namespace std;

vector<vector<string> > partition(string s);
bool testPalindrome(string &str);

int main(){
    vector<vector<string> > res = partition("efe");
    for(int i = 0; i != res.size(); ++i){
        for(int j = 0; j != res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    if(s.size() == 0) return result;
    vector<string> tmp; result.push_back(tmp); 
    for(int i = 0; i != s.size(); ++i){
        result.back().push_back(s.substr(i,1));
    }
    bool flag = true;
    while(flag){
        flag = false;
        int last = result.size() - 1;
        for(int i = 0; i != result[last].size()-1; ++i){
            string con = result[last][i] + result[last][i+1];
            if(testPalindrome(con)){
                result.push_back(tmp);
                for(int j = 0; j != i; ++j){
                    result.back().push_back(result[last][j]);
                }
                result.back().push_back(con);
                for(int j = i + 2; j < result[last].size(); ++j){
                    result.back().push_back(result[last][j]);
                }
                flag = true;
            }
        }
    }
    if(s.size() > 1 && testPalindrome(s)){
        result.push_back(tmp);
        result.back().push_back(s);
    } 
    return result;
}

bool testPalindrome(string &str){
    if(str.size() < 2) return true;
    int size = str.size();
    for(int i = 0; i != size/2; ++i){
        if(str[i] != str[size-i-1]){
            return false;
        }
    }
    return true;
}
