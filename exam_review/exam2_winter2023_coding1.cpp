#include <iostream>
#include <string>

int countConsonants(std::string s, int length);

int main() {
    std::string s = "CSBridge";
    std::cout << countConsonants(s, 8) << std::endl;

    return 0;
}

int countConsonants(std::string s, int length) {
    if (length < 1) return 0;
    int lastIndex = length - 1;
    int count;
    if (s[lastIndex] != 'A' && s[lastIndex] != 'E' && s[lastIndex] != 'I' && s[lastIndex] != 'O' && s[lastIndex] != 'U' && 
        s[lastIndex] != 'a' && s[lastIndex] != 'e' && s[lastIndex] != 'i' && s[lastIndex] != 'o' && s[lastIndex] != 'u') {
        count = 1;
    } else {
        count = 0;
    }
    return count + countConsonants(s, length - 1);
}
