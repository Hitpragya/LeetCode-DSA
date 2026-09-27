class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;

        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = previous;
            previous = head;
            head = nextNode;
        }

        return previous;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfHead = reverseList(slow);
        ListNode* firstHalfPointer = head;
        ListNode* secondHalfPointer = secondHalfHead;

        while (secondHalfPointer != nullptr) {
            if (firstHalfPointer->val != secondHalfPointer->val) {
                return false;
            }

            firstHalfPointer = firstHalfPointer->next;
            secondHalfPointer = secondHalfPointer->next;
        }

        return true;
    }
};