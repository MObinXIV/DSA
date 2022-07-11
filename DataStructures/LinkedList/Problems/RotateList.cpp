//https://leetcode.com/problems/rotate-list/
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  //Nive approach which we observe directly trhough drawing 
   ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head ->next==NULL)return head ;
        //I'll iterate to the end and swap k times 
        for(int i = 0 ; i<k ; i++)
        {
            ListNode*temp=head;
            //This is the step You miss you make the pointer position in the prev last and apply your logic 
            while(temp->next->next!=NULL)temp=temp->next;//Get pointer in the  prev to last position
            ListNode*end=temp->next;
            temp->next=NULL;
            end->next=head;
            head=end;

        }
    }

    //Optimal Solution
    /*
    The idea lies behined the multiplicty of number if k > length we will do only the multiple of k in length of linked list 
    so for that we always keep taking the modules of k 
    count length-> make last->next = head -> get len - k to point the last node after modifying to null
    */
   /// ببساطة يكبير فكرة الحل انى الاول بوصل لاخر نود و معاها بحسب الطول ، بعد كدا بشاور من اخر نود على اول نود بعدين اتحرك تانى لحد البوزيشن بتاع الفرق اللى 
/// هى هتبقى النود  اللى قبل مجموعة النودز اللى هيتقلو و اروح مشاور منها على نل
    ListNode* rotateRight2(ListNode* head, int k) {
        if(!head || head->next == NULL || k==0)return head;
        ListNode*cur=head;
        int len=1;
        while(cur->next && len++)cur=cur->next;

        cur->next=head;//point last node to the 1st node 
        k=k%len;//The step to reduce the length of k in case it bigger than the length of list 
        k=len-k;//to accsses the last node which we aren't consider in our rotation
        while (k--)cur=cur->next;//here we get the node which we assign it to Null
        head=cur->next;//Store the head to the last remaining node 
        cur->next=NULL; //Assign NULL to the last node 
        return head;


    }