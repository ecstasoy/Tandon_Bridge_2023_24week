#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template <class T>
class List;

template <class T>
class ListNode {
    T data;
    ListNode<T>* next;
public:
    ListNode(const T& newData = T(), ListNode<T>* newNext = nullptr) : data(newData), next(newNext) {};
    friend class List<T>;
    friend void printReimbursementInstructions(List<T>& nameList, double average);
    friend void computeOwed(List<T>& nameList, double average);
};

template <class T>
class List {
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    List();
    List(const List<T>& rhs);
    ~List();

    List<T>& operator=(const List<T>& rhs);

    void clear();
    void push_back(const T& data);
    int size();
    bool isEmpty() {return head->next == tail;};

    friend void printReimbursementInstructions(List<T>& nameList, double average);
    friend void computeOwed(List<T>& nameList, double average);
};

template <class T>
List<T>::List() {
    head = new ListNode<T>();
    tail = new ListNode<T>();
    head->next = tail;
    tail->next = nullptr;
}

template <class T>
List<T>::List(const List<T>& rhs) {
    List();
    *this = rhs;
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
List<T>& List<T>::operator=(const List<T>& rhs) {
    if (this == &rhs) return *this;
	clear();
	ListNode<T>* ptr = rhs.head->next;
	while (ptr != rhs.tail) {
		push_back(ptr->data);
        ptr = ptr->next;
	}
	return *this;
}

template <class T>
void List<T>::clear() {
    ListNode<T>* curNode = head;
    while(curNode) {
        ListNode<T>* nexNode = curNode->next;
        delete curNode;
        curNode = nexNode;
    }
}

template <class T>
void List<T>::push_back(const T& data) {
    ListNode<T>* newNode = new ListNode<T>(data, tail);
    if(isEmpty()) {
        head->next = newNode;
    } else {
        ListNode<T>* curNode = head;
        while(curNode->next != tail) {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }
}

template <class T>
int List<T>::size() {
    ListNode<T>* ptr = head;
    int count = 0;
    while(ptr->next != tail) {
        ++count;
        ptr = ptr->next;
    }
    return count;
}

class People {
    std::string name;
    double bills;
    double owed;
public:
    People(std::string newName = "", double newBills = 0) : name(newName), bills(newBills), owed(0) {};

    std::string getName() { return name; };
    double getBills() { return bills; };
    double getOwed() { return owed; };

    void setOwed(double amount) { owed = amount; };
    void addOwed(double amount) { owed += amount; };
    void subtractOwed(double amount) { owed -= amount; };
};

void openInputFile(std::ifstream& inFile) {
	std::string filename;
	std::cout << "Enter the file name: ";
	std::cin >> filename;
	inFile.open(filename);
	while (!inFile) {
		std::cout << "Bad filename!" << std::endl;
		std::cout << "What filename would you like to open: ";
		std::cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}
}

void computeOwed(List<People>& nameList, double average) {
    for (ListNode<People>* person = nameList.head->next; person != nameList.tail; person = person->next) {
        double bills = person->data.getBills();
        person->data.setOwed(bills - average);
    }
}

void printReimbursementInstructions(List<People>& nameList, double average) {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    for (ListNode<People>* debtor = nameList.head->next; debtor != nameList.tail; debtor = debtor->next) {
        if(debtor->data.getOwed() == 0) {
            std::cout << debtor->data.getName() << ", you don't need to do anything. " << std::endl;
        }

        for (ListNode<People>* creditor = nameList.head->next; creditor != nameList.tail; creditor = creditor->next) {
            if (debtor->data.getOwed() < 0 && creditor->data.getOwed() > 0) {
                double amount = std::min(-debtor->data.getOwed(), creditor->data.getOwed());
                std::cout << debtor->data.getName() << ", you give " << creditor->data.getName() << " $" << amount << std::endl;
                debtor->data.addOwed(amount);
                creditor->data.subtractOwed(amount);
            }
        }
    }
    std::cout << "In the end, you should all have spent around $" << average << ". " << std::endl;
}


int main() {
    std::ifstream inFile;
    openInputFile(inFile);
    double temp, totalPaid;
    std::string name;
    List<People> nameList;

    while(inFile >> temp) {
        totalPaid += temp;
        inFile.ignore(1, ' ');
        getline(inFile, name);
        nameList.push_back(People(name, temp));
    }

    double average = totalPaid / nameList.size();
    computeOwed(nameList, average);

    printReimbursementInstructions(nameList, average);

    return 0;
}