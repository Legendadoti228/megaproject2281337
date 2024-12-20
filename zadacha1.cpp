#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string binarySum(const string& a, const string& b) {
    string result;
    int carry = 0;
    int maxLength = max(a.size(), b.size());

    string aPadded = string(maxLength - a.size(), '0') + a;
    string bPadded = string(maxLength - b.size(), '0') + b;

    for (int i = maxLength - 1; i >= 0; --i) {
        int sum = (aPadded[i] - '0') + (bPadded[i] - '0') + carry;
        result.push_back((sum % 2) + '0'); 
        carry = sum / 2; 
    }
    if (carry) {
        result.push_back('1'); 
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string A = "101101";
    string B = "110011";

    bitset<6> aBitset(A);
    bitset<6> bBitset(B);
    bitset<6> andResult = aBitset & bBitset;


    string sumResult = binarySum(A, B);

    cout << "A AND B: " << andResult << endl;
    cout << "A + B: " << sumResult << endl;

    return 0;
}