//https://leetcode.com/problems/copy-list-with-random-pointer/

#include<bits/stdc++.h>

using namespace std;
//The first approach is the hash_set approach 
/*
We create a hash set with deep copies then assign it's next and random values 

*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        int i =0 ; 
        Node*ptr=head;
        while(ptr!=NULL)
        {
            mp[ptr]=new Node(ptr->val);//Create the node 
            ptr=ptr->next;
        }
        //The next step , we assign the next and random pointers 
        ptr=head;
        while(ptr)
        {
            mp[ptr]->next=mp[ptr->next];//Assign the next value 
            mp[ptr]->random=mp[ptr->random];
            ptr=ptr->next;
        }
        return mp[head];
    }


    Node* copyRandomList(Node* head) {
        Node*iter=head,*front=head;
        // First round: make copy of each node,
          // and link them together side-by-side in a single list.
        while(iter)
        {
            front=iter->next;//Get the next value 
           Node*copy=new Node(iter->val);//create a deep copy of iter 
           iter->next=copy;//Assign iter node to the copy node 
           copy->next=front;//Point to the front of the original node 
           iter = front;
        }
        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter)
        {
            if(iter->random!=NULL) 
            iter->next->random=iter->random->next;//Point the random iter to the copy of node 
            iter=iter->next->next;//move 2 steps to go to the next original node 
        }
        iter =head ;
        // Third round: restore the original list, and extract the copy list.
        Node*dummy=new Node(0);
        Node*copy=dummy;
        while(iter)
        {
            front=iter->next->next;//Get the next value of original list 
            copy->next=iter->next;//Assign copy to the copy list node 
            iter->next=front;//Make the original list item point to it's neighbor
            copy=copy->next;//move the copy by one step
            iter=front;//go to the next node 
        }
        return dummy->next;

    }