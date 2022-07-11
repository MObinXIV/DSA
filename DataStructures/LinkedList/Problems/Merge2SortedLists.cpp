 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2; 
        if (l2==NULL) return l1;
         if(l1->val > l2->val) std::swap(l1,l2);
            ListNode* res = l1;//Return with it 
        while (l1!=NULL && l2!=NULL)
        {
            ListNode*t=NULL;//assign it to Null to keep track of l1 node 
            while(l1 != NULL && l1->val <= l2->val) {

                t = l1;//storing last sorted node in l1 before we do the cut  
                l1 = l1->next;
            }
            t->next = l2;//cut and point 
            std::swap(l1,l2);//swap 

        }
        return res;
        
    }