#include<bits/stdc++.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=head;
        int cnt=0;
        if(head==NULL) return NULL;
        while(dummy!=NULL)
        {
            dummy=dummy->next;
            cnt++;
        }
        
        int x=cnt-n;
        if(x==0) return head->next;
       ListNode*curr=head;
    ListNode*prev=NULL;
        while(x>0)
        {
            prev=curr;
            curr=curr->next;
            x--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=head;
        int l=0;

        while ( cur!=NULL)
        {
            l++;
            cur=cur->next;
        }
        if (l==1 || l==0)return NULL;
        int x = l-n;
        if (x==0)return head->next;
        cur=head;
        for (int i=0;i<x-1;i++)
            cur=cur->next;
        ListNode*temp=cur->next;
        cur->next=temp->next;
        delete temp;
        return head;
        
    }
    /*
    move fast pointer to the nth node
    move fast & slow till fast.next is null
    */
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
