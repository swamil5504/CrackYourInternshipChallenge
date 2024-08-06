#include <unordered_map>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* temp = head; 

        while (temp != NULL) {
            if (mpp.find(temp) != mpp.end()) {
                return true;
            }

            mpp[temp] = 1;
            
            temp = temp->next;
        }
        return false;
    }
};
