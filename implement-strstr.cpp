class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int lens = strlen(haystack);
        int lenp = strlen(needle);
        int i = 0, j = 0;
        int *next = new int[lenp];
        calcNext(needle, next);
        while(i < lens && j < lenp){
            if(j == -1 || haystack[i] == needle[j]){
                ++i; ++j;
            }else{
                j = next[j];
            }
        }
        delete next;
        if(j == lenp){
            return haystack + (i - j);
        }
        else return NULL;
    }
    
    void calcNext(char *needle, int *next){
        int n = strlen(needle);
        if(n == 0) return;
        int j = 0, k = -1;
        next[0] = -1;
        while(j < n - 1){
            if(k == -1 || needle[j] == needle[k]){
                ++j; ++k;
                next[j] = k;
            }else
            {
                k = next[k];
            }
        }
    }
};
