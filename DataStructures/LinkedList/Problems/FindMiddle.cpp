#include<bits/stdc++.h>

using namespace std;
struct ListNode {
       int val;
       ListNode  *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode  *next) : val(x), next(next) {}
   };
ListNode* middleNode(ListNode* head) {
        ListNode*cur=head;
        int len=0;
        while (cur!=NULL)
        {
            len++;
            cur=cur->next;
        }
        cur=head;
        int Hl=len/2;
        
        while (Hl--)
        {
            cur=cur->next;
            
        }
        return cur;
    }

ListNode* middleNode(ListNode* head) {
    ListNode *slow=head , *fast=head;
    while(fast!=NULL &&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
