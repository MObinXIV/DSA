ListNode *detectCycle(ListNode *head) {
        if (head==NULL || head->next==NULL)return NULL;
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*entry=head;

        while (fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if (slow == fast)
            {
                while (slow !=entry )
                {
                    slow = slow->next;
                    entry=entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }