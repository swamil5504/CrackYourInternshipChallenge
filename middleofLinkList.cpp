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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        int count = 0;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            count ++;
            curr = curr->next;
        }

        int mid = count / 2;
        
        curr = head;
        for(int i = 0;i < mid; i++)
        {
            curr = curr->next;
        }
        return curr;
    }
};