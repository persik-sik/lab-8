#include <cstring>
#include <iostream>
using namespace std;

char* CopyString(const char* str) {
    size_t len = 0;
    while (str[len]) ++len;
    char* copy = new char[len + 1];
    memcpy(copy, str, len + 1);
    return copy;
}
char* ConcatinateStrings(const char* a, const char* b) {
    size_t lena = 0, lenb = 0;
    while(a[lena]) ++lena;
    while(b[lenb]) ++lenb;
    char* res = new char[lena + lenb + 1];
    memcpy(res, a, lena);
    memcpy(res + lena, b, lenb + 1);
    return res;
}

int main() {
    const char* str1 = "ZZZZZ";
    const char* str2 = "ZOVZOV";
    char* copy = CopyString(str1);
    cout << copy << endl;
    char* concatenated = ConcatinateStrings(str1, str2);
    cout << concatenated << endl;
    delete[] copy;
    delete[] concatenated;
