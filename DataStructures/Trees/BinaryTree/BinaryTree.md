# Binary Tree

## Types

- Full -> Every node has 2 or 0 children

- Complete -> All levels are filled , except the last level has nodes as left as possible
- Perfect Binary Tree -> All Nodes are in the same level.
- Balnced -> Height of the tree at max log(N).
- Degenerate -> Skewed Tree , as linked list every node has one Children

## Traversal

- PreOrder : root -> left -  > right.
- InOrder : left -> root ->right.
- postOrder: left -> right -> root.
- Level:Bfs for every level.

### Problems

- Check Balanced -> We check the abs difference height for every node and if it's bigger than one we return -1  ، من الاخر كدا انا بحسب الهايت بتاع كل نود و اشيك لو واحدة فكست بفكس لكله
- Diameter: بمشى ريكرسف و احسب الهايت يمين و شمال و بجمعهم لكل نود
- Maximum Path sum -> we take the diameter + current node to determine the maximum path ( The curved idea), and for negative values we put 0 to reject it.
- Same Tree -> We do any traversal for both trees
- Zigzag -> Level order but we reverse row order according to flag Value.
- Boundary Traversal -> We traverse The left tree with not leaf then all the leafs then the right tree in reversed order.
