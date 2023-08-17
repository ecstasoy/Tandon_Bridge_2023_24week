#include <iostream>
#include <string>

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    using namespace std;

    int n, m, option;
    char symbol;

    cout<<"Type 1 to print shifted triangles and type 2 to print pine trees: "<<endl;
    cin>>option;

    if (option == 1) {
        cout<<"Please enter an integer for number of lines: "<<endl;
        cin>>n;
        cout<<"Please enter an integer for number of spaces: "<<endl;
        cin>>m;
        cout<<"Please enter a symbol: "<<endl;
        cin>>symbol;

        printShiftedTriangle(n, m, symbol);
    } else if (option == 2)
    {
        cout<<"Please enter an integer > 2 for number of triangles: "<<endl;
        cin>>n;
        cout<<"Please enter a symbol: "<<endl;
        cin>>symbol;

        printPineTree(n, symbol);
    }


    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    using namespace std;

    string spacing = "", printSymbol = "";

    for (int i = 0; i < n; ++i) {
        spacing = string(m + n - i - 1, ' ');
        printSymbol = string(2 * i + 1, symbol);

        cout<<spacing<<printSymbol<<endl;
    }
}

void printPineTree(int n, char symbol) {
    using namespace std;

    for (int i = 0; i < n; ++i) {
        printShiftedTriangle(i + 2, n - 1 - i, symbol);
    }

}