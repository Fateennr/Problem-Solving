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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * end = head;

        if(n==1){
            if(head->next == nullptr){
                    ListNode * tmp = head;
                    head = head->next;
                    tmp = nullptr;
                    return head;
            }
            else{
                while(end->next->next != nullptr){
                    end = end->next;
                }

                ListNode * tmp = end->next;
                end->next = nullptr;
                tmp = nullptr;

                return head;
            }
        }

        int sz = 1;
        while(end->next != nullptr){
            end = end->next;
            sz++;
        }

        

        // cout << sz << "\n";

        int sz1 = sz - n -1;

        if(sz1 < 0){
            ListNode * tmp = head;
            head = head->next;
            tmp = nullptr;
            return head;
        }

        end = head;
        int i = 0;
        while( i < sz1 ){
            end = end -> next;
            i++;
        }

        cout << end->val <<"\n";


        ListNode * tmp = end->next;
        // cout << tmp << "\n";
        end->next = tmp->next;
        tmp = nullptr;

        return head;
        
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


    s.removeNthFromEnd(head, 2);
    return 0;
}
