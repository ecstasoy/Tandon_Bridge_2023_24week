#include <iostream>
#include <list>

std::list<int> intersection(const std::list<int>& L1, const std::list<int>& L2) {
    std::list<int> res;
    auto itr1 = L1.begin();
    auto itr2 = L2.begin();

    while(itr1 != L1.end() && itr2 != L2.end()) {
        if(*itr1 < *itr2) {
            ++itr1;
        } else if(*itr1 > *itr2) {
            ++itr2;
        } else {
            res.push_back(*itr1);
            ++itr1;
            ++itr2;
        }
    }
    return res;
}

std::list<int> combination(const std::list<int>& L1, const std::list<int>& L2) {
    std::list<int> res;
    auto itr1 = L1.begin();
    auto itr2 = L2.begin();

    while(itr1 != L1.end() && itr2 != L2.end()) {
        if(*itr1 < *itr2) {
            res.push_back(*itr1);
            ++itr1;
        } else if(*itr1 > *itr2) {
            res.push_back(*itr2);
            ++itr2;
        } else {
            res.push_back(*itr1);
            ++itr1;
            ++itr2;
        }
    }

    if(itr1 == L1.end()) {
        while(itr2 != L2.end()) {
            res.push_back(*itr2);
            ++itr2;
        }
    } else {
        while(itr1 != L1.end()) {
            res.push_back(*itr1);
            ++itr1;
        }
    }

    return res;
}

void std::list::splice(iterator position, List<T> lst) {

}

int main() {
    std::list<int> L1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 30};
    std::list<int> L2 = {3, 4, 5, 6, 7, 8, 9};

    std::list<int> result1 = intersection(L1, L2);
    std::list<int> result2 = combination(L1, L2);

    for (int num : result1) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    for (int num : result2) {
        std::cout << num << " ";
    }

    return 0;
}