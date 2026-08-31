/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        
        int position = 2;
        int firstCriticalPosition = -1;
        int previousCriticalPosition = -1;
        int minimumDistance = INT_MAX;

        while (currentNode->next != nullptr) {
            bool isLocalMaximum = currentNode->val > previousNode->val &&
                                  currentNode->val > currentNode->next->val;

            bool isLocalMinimum = currentNode->val < previousNode->val &&
                                  currentNode->val < currentNode->next->val;

            if (isLocalMaximum || isLocalMinimum) {
                if (firstCriticalPosition == -1) {
                    firstCriticalPosition = position;
                } else {
                    minimumDistance = min(minimumDistance,
                                          position - previousCriticalPosition);
                }

                previousCriticalPosition = position;
            }

            previousNode = currentNode;
            currentNode = currentNode->next;
            position++;
        }

        if (firstCriticalPosition == -1 ||
            firstCriticalPosition == previousCriticalPosition) {
            return {-1, -1};
        }

        return {minimumDistance,
                previousCriticalPosition - firstCriticalPosition};
    }
};