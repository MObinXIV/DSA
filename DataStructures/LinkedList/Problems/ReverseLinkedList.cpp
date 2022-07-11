#include<bits/stdc++.h>

using namespace std;
struct ListNode {
       int val;
       ListNode  *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode  *next) : val(x), next(next) {}
   };

   ListNode* reverseList(ListNode* head) {
        ListNode* d= NULL;
        ListNode*nex=head;
        while (head!=NULL)
        {
            nex=head->next;
            head ->next=d;
            d=head;
            head=nex;
        }
        return d;

    }

//Recursive 
//https://www.youtube.com/watch?v=S92RuTtt9EE
ListNode* reverseList(ListNode* head)
{
    
    if(head == NULL || head->next==NULL) return head; 
        ListNode*node=reverseList(head->next);//keep the head node 
        head->next->next=head;//reverse arrow
        head->next=NULL;//point current to Null 
        return node;




}