#include <iostream>
using namespace std;

int divide(int dividend, int divisor);

int main()
{
    cout << divide(2147483647,2) << endl;
    cout << divide(2147483647,2) << endl;
    cout << divide(2147483647,2) << endl;
    cout << divide(2147483647,2) << endl;
    cout << divide(2147483647,2) << endl;
    cout << divide(2147483647,2) << endl;
    cout << divide(2147483647,2) << endl;
    return 0;
}

int divide(int dividend, int divisor) {
    int symbol = 1;
    long n1 = dividend, n2 = divisor;
    if(n1 < 0) {symbol = symbol * -1; n1 = n1 * -1;}
    if(n2  < 0) {symbol = symbol * -1; n2 = n2 * -1;}

    int res = 0, count = 0;
    while(true){
        if(n2 == 1) return n1*symbol;
        if(n1 < n2) return res*symbol;
        else if(n1 == n2) return (res + 1)*symbol;
        else{
            while(n1 > n2){
                n2 = n2 << 1;
                if(count == 0) count = 1;
                else count = count << 1;
            }
            n1 = n1 - (n2 >> 1);
            n2 = divisor;
            res += count;
            count = 0;
        }
    }
}
