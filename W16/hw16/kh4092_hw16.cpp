#include <iostream>
#include <fstream>
#include <stack>
#include <vector>


/* Part 1 */


bool symbolBalanceChecker(std::ifstream& inFile) {
    char ch;
    std::stack<char> symbols;

    while(inFile.get(ch)) {
        if(ch == 'b') {
            std::string word = "b";
            for(int i = 0; i < 4 && inFile.get(ch); ++i) {
                word += ch;
            }
            if(word == "begin") symbols.push('b');
        } else if(ch == 'e') {
            std::string word = "e";
            for(int i = 0; i < 2 && inFile.get(ch); ++i) {
                word += ch;
            }
            if(word == "end" && !symbols.empty() && symbols.top() == 'b') {
                symbols.pop();
            } else {
                return false;
            }
        } else if(ch == '{') {
            symbols.push(ch);
        } else if(ch == '}') {
            if(symbols.empty() || symbols.top() != '{') return false;
            symbols.pop();
        } else if(ch == '(') {
            symbols.push(ch);
        } else if(ch == ')') {
            if(symbols.empty() || symbols.top() != '(') return false;
            symbols.pop();
        } else if(ch == '[') {
            symbols.push(ch);
        } else if(ch == ']') {
            if(symbols.empty() || symbols.top() != '[') return false;
            symbols.pop();
        }
    }

    return symbols.empty();
}

int main() {
    std::ofstream output1("input1.txt"), output2("input2.txt");
    output1 << "begin [{}][] end";
    output2 << "begin [{}(]) end";
    output1.close();
    output2.close();

    std::ifstream input1("input1.txt"), input2("input2.txt");

    std::cout << "First expressions: begin [{}][] end; Return type: " << 
    (symbolBalanceChecker(input1) ? "True" : "False") << std::endl;

    std::cout << "First expressions: begin [{}(]) end; Return type: " << 
    (symbolBalanceChecker(input2) ? "True" : "False") << std::endl;

    input1.close();
    input2.close();
    
    return 0;
}


/* Part 2 */


template <class T>
class Stack {
        std::vector<T> data;
        size_t start;

    public:
        Stack() : start(0) {};

        bool empty() {return start > data.size() - 1; }
        size_t size() {return data.size() - start; }

        void push(const T& value) {data.push_back(value); }
        void pop() {
            if(empty()) {
                data.clear();
                start = 0;
            }
            ++start;
        }
        T& front() {return data[start]; }
        const T& front() const {return data[start]; }
        T& back() {return data.back(); }
        const T& back() const {return data.back(); }
};