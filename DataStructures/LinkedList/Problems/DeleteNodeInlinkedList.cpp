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
   *we copy the value of next node in the cur node 
   *point the node to node.next.next


   */

    void deleteNode(ListNode* node) {
        node->val=node->next->val;//assign current node with next node 
        node->next=node->next->next;//Only link with next node 
        
    }