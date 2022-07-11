#include<bits/stdc++.h>

using namespace std;

/*
Use a hash table for storing nodes. 
Start iterating through the lists.
If the current node is present in the hash table already, this indicates the cycle is present in the linked list and returns true.
Else move insert the node in the hash table and move ahead.
If we reach the end of the list, which is NULL, then we can say that the given list does not have a cycle 
in it and hence we return false.
*/
bool cycleDetect(node* head) {
    unordered_set<node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}

//Move Slow by one and fast by 2 and the moment they collid this is a cycle 
 bool hasCycle(ListNode *head) {
        if (head == NULL || head->next== NULL)return false;
        
        ListNode*fast=head;
        ListNode *slow=head;
        while (fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow)return true;
        }
        return false;
    }