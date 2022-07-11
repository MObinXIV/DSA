#include<bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


  //BruteForce:We traverse till we found 2 nodes has is same

  ListNode* intersectionPresent(ListNode* head1,ListNode* head2) {
    while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

//Hashing Solution
ListNode* intersectionPresent(ListNode* head1,ListNode* head2) {
     unordered_set<ListNode*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}


 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     if(headA==NULL || headB==NULL)return NULL;
        ListNode*h1=headA;
        ListNode*h2=headB;
        //Traverse till they equal
        while(h1!=h2)
        {
            h1=h1==NULL ? headB :h1->next;// when I reach NULL I go to the other list head else I move next
            h2=h2==NULL ? headA :h2->next;
        }
        return h1;
 }

