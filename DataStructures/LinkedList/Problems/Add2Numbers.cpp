#include<bits/stdc++.h>

using namespace std;
struct ListNode {
       int val;
       ListNode  *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode  *next) : val(x), next(next) {}
   };
   /*
   We sum the values by adding them then take the carry and add it to the next value 
   
   */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        int carry=0;
        while(l1 !=NULL || l2!=NULL ||carry )
        {
            int sum =0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            //calculate total sum by adding it to the previous carry 
            sum+=carry;
            //update carry
            carry=sum/10;
            ListNode*node=new ListNode(sum%10);//The value assign 
            temp->next=node;//Link the current node with temp
            temp=temp->next;//move temp to the next node 
        }
        return dummy->next;
    }