#include <iostream>
#include <vector>

class Money {
    private:
        long allCents;
    public:

        Money(long dollars, int cents) : allCents(dollars * 100 + cents) {};
        Money(long dollars) : allCents(dollars * 100) {};
        Money(const Money& amount) : allCents(amount.allCents) {};
        Money() : allCents(0) {};

        Money operator+(const Money& rhs) const;
        Money operator-(const Money& rhs) const;
        Money operator-() const;
        bool operator==(const Money& rhs) const;
        friend std::istream& operator >>(std::istream& ins, Money& amount);
        friend std::ostream& operator <<(std::ostream& outs, const Money& amount);

        double getValue() const;

        void setValue(long dollars, int cents);
};

class Check {
    private:
        int number;
        Money amount;
        bool isCashed;
    public:

        Check(int num, const Money& amt, bool isCashed) : number(num), amount(amt), isCashed(isCashed) {};
        Check() : number(0), amount(), isCashed(false) {};

        int getNumber() const {return number;};
        Money getAmount() const {return amount;};
        double getAmountValue() const {return amount.getValue();};
        bool getCashedStatus() const {return isCashed;};

        void setNumber(int num) {number = num;};
        void setAmount(const Money& amt) {amount = amt;};
        void setCashedStatus(bool cashed) {isCashed = cashed;};

        void input();
        void output() const;
};

void cashedDetail(std::vector<Check> cashed, std::vector<Check> notCashed);
void sortCheck(std::vector<Check> vec);
void printVectorCheck(std::vector<Check> vec);
void printVectorMoney(std::vector<Money> vec);
int digit_to_int(char c);

int main() {
    std::vector<Money> deposits;
    std::vector<Check> checksCashed;
    std::vector<Check> checksNotCashed;

    Money oldBalance, newBalance, currDeposit, depositSum, checkCashedSum, checkNotCashedSum;
    long dollars;
    int cents;
    char inputCheckFlag = 'y', inputDepositFlag = 'y';

    std::cout << "\n------ Please enter the details of your check below ------" << std::endl;
    while (inputCheckFlag == 'y' || inputCheckFlag == 'Y') {
        Check inputCheck;
        inputCheck.input();
        if (inputCheck.getCashedStatus()) {
            checksCashed.push_back(inputCheck);
            checkCashedSum = inputCheck.getAmount() + checkCashedSum;
        } else {
            checksNotCashed.push_back(inputCheck);
            checkNotCashedSum = inputCheck.getAmount() + checkNotCashedSum;
        }

        std::cout << "Do you want to continue entering (y/n): " << std::endl;
        std::cin >> inputCheckFlag;
    }



    while (inputDepositFlag == 'y' || inputDepositFlag == 'Y') {
        std::cout << "\nPlease enter the amount of your deposit (in the format of $***.**, 2 digits after the decimal point): " << std::endl;
        std::cin >> currDeposit;

        deposits.push_back(currDeposit);
        depositSum = currDeposit + depositSum;

        std::cout << "Do you want to continue entering? (y/n): " << std::endl;
        std::cin >> inputDepositFlag;
    }

    printVectorMoney(deposits);

    std::cout << "\nPlease enter the amount of your old account balance (in the format of $***.**, 2 digits after the decimal point): " << std::endl;
    std::cin >> oldBalance;

    std::cout << "Please enter the amount of your new account balance (in the format of $***.**, 2 digits after the decimal point): " << std::endl;
    std::cin >> newBalance;

    Money bankBalance(oldBalance + depositSum - checkCashedSum);

    std::cout << "\nYour new account balance should be: " << std::endl;
    std::cout << "\n\tOld Account Balance:\t\t" << oldBalance << std::endl;
    std::cout << "+\tSum of Deposits:\t\t" << depositSum << std::endl;
    std::cout << "-\tCashed Amount from Checks:\t" << checkCashedSum << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "=\tNew Account Balance:\t\t" << bankBalance << std::endl;
    std::cout << "\nThe discrepancy between the account holders balance of " << newBalance << " and the bank balance of " << bankBalance << " is: " << newBalance - bankBalance << std::endl;

    cashedDetail(checksCashed, checksNotCashed);

    std::cout << "\n" << checkCashedSum << " of the checks are cashed and " << checkNotCashedSum << " of the checks are not cashed." << std::endl;

    return 0;
}

void cashedDetail(std::vector<Check> cashed, std::vector<Check> notCashed) {
    sortCheck(cashed);
    sortCheck(notCashed);
    std::cout << "\n**************Checks Details****************" << std::endl;
    if(cashed.size() == 0) {
        std::cout << "There is no record of cashed checks." << std::endl;
    } else {
        printVectorCheck(cashed);
    }
    std::cout << "\n" <<std::endl;
    if(notCashed.size() == 0) {
        std::cout << "There is no record of uncashed checks." << std::endl;
    } else {
        printVectorCheck(notCashed);
    }
    std::cout << "********************************************" << std::endl;
}

void sortCheck(std::vector<Check> vec) {
    std::sort(vec.begin(), vec.end(), [] (const Check& lhs, const Check& rhs) {return lhs.getNumber() < rhs.getNumber();});
}

void printVectorCheck(std::vector<Check> vec) {
    std::cout << "Number\t" << "Amount\t" << "Cashed Status" << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i].getNumber() << "\t" << vec[i].getAmount() << "\t" << (vec[i].getCashedStatus() ? "Yes" : "No") << std::endl;
    }
}

void printVectorMoney(std::vector<Money> vec) {
    int index = 1;
    Money sum;

    std::cout << "\nThe details of your deposits are as follows: " << std::endl;
    std::cout << "Num" << "\t" << "Amount" << std::endl;
    for (const Money& deposit : vec) {
        std::cout << index << "\t" << deposit << std::endl;
        sum = deposit + sum;
        ++index;
    }
    std::cout << "Total: \t" << sum << std::endl;
}

int digit_to_int(char c) {
    return (static_cast<int> (c) - static_cast<int> ('0'));
}

std::istream& operator >>(std::istream& ins, Money& amount) {
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> oneChar;

    if (oneChar == '-') {
        negative = true;
        ins >> oneChar;
    }
    else {
        negative = false;
    }

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        std::cout<<"Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.allCents = dollars * 100 + cents;

    if (negative) {
        amount.allCents = -amount.allCents;
    }

    return ins;
}

std::ostream& operator <<(std::ostream& outs, const Money& amount) {
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (amount.allCents < 0 ) {
        outs << "-$" << dollars << '.';
    }
    else {
        outs << "$" << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;

    return outs;
}

Money Money::operator+(const Money& rhs) const {
    Money temp(* this);
    temp.allCents += rhs.allCents;
    return temp;
}

Money Money::operator-(const Money& rhs) const {
    Money temp(* this);
    temp.allCents -= rhs.allCents;
    return temp;
}

Money Money::operator-() const {
    Money temp(* this);
    temp.allCents = -allCents;
    return temp;
}

bool Money::operator==(const Money& rhs) const {
    if (allCents == rhs.allCents) {
        return true;
    } else {
        return false;
    }
}

double Money::getValue() const {
    return allCents * 0.01;
}

void Money::setValue(long dollars, int cents) {
    allCents = dollars * 100 + cents;
}

void Check::input() {
    std::cout << "\nPlease enter the number of the check: " << std::endl;
    std::cin >> number;

    std::cout << "Please enter the amount of the check (in the format of $***.**, 2 digits after the decimal point): " << std::endl;
    std::cin >> amount;

    std::cout << "Enter 1 if the check has been cashed, 0 if not: " << std::endl;
    std::cin >> isCashed;
}

void Check::output() const {
    std::cout << "Check Number: " << number << std::endl;
    std::cout << "Amount: $" << amount.getValue() << std::endl;
    std::cout << "Cashed: " << (isCashed ? "Yes" : "No") << std::endl;
}