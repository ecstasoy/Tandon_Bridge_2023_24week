#include<iostream>
#include<cstring>

int main() {
    int input;
    std::string print_str = "";
    std::cin >> input;
    int width = 2*input-1;

    int spaces = 0;
    for(int i = 0; i < width + 1; ++i) {

        if (2*i <= width)
        {
            spaces = i;
        }
        else if (i > input)
        {
            --spaces;
        }
        
        print_str = "";
        for (int j = 0; j < width; ++j) {
            if (j < spaces || j >= (width-spaces)) {
                print_str = " " + print_str;
            }
            else {
                print_str = "*" + print_str;
            }
        }
        std::cout << print_str << std::endl;
    }

    return 0;
}