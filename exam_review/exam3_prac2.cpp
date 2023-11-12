#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
}

ListNode* reverse_linked_list(ListNode* head) {
    if(head->next = nullptr) return head;
    ListNode* newHead = reverse_linked_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

bool is_target_in_list(ListNode* head, int target) {
    ListNode* temp = head;
    while(!temp) {
        if(head->val == target) return true;
        temp = head->next;
    }

    return false;
}

int find_max(ListNode* head) {
    int max = head->val;
    ListNode* temp = head;
    while(!temp) {
        if(head->val >= temp) max = head->val;
        temp = head->next;
    }

    return max;
}