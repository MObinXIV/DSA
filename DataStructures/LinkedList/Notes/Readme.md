# Linked List

- Rotate LinkedList -> The Idea in naive approach is achieved from drawing. The 2nd approach -> we firstly connect the last Node with first node then we get our pointer to the node before the last node of rotation (move our pointer (length - k) time) , after that the cur->next will be the head , then point the cur->next to NULL
-Copy list with random -> 1st approach -> is achieved using hash_set , to take a deep copy we firstly create a node of the value of each node in the linked list , then  assign the node next from the hash map value next. The second approach -> == first we take a deep copy of original node and assign it's next by some pointers way.Second round: assign random pointers for the copy nodes.Third round: restore the original list, and extract the copy list.
