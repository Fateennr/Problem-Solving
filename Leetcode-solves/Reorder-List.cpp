#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {

        if(head->next == nullptr || head->next->next == nullptr){
            return;
        }

        ListNode * slow = head;
        ListNode * fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;            
            fast = fast->next->next;

            // cout << slow->val << " " << fast->val <<"\n";
        }

        // Reversing the array

        ListNode* gg = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;

        while(gg != nullptr){
            ListNode * temp = gg->next;
            gg->next = prev;
            prev = gg;
            gg = temp;
        }

        ListNode * first = head;
        ListNode * second = prev;

        while(second != nullptr){
            ListNode * temp1 = first->next;
            ListNode * temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }

        ListNode * temp3 = head;
        while(temp3 != nullptr){
            cout << temp3->val << " ";
            temp3 = temp3->next;
        }
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);


    s.reorderList(head);
    return 0;
}