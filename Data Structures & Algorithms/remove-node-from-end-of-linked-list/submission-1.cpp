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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        n = length - n + 1;
        if(n == 1){
            return head->next;
        }
        ListNode* prev = nullptr;
        temp = head;
        int index = 1;
        while(index < n){
            prev = temp;
            temp = temp->next;
            index++;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};
