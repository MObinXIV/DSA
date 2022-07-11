# SubSet Sum Problems

1. SubsetSum (Normal)->keep sum = target
2. SubsetSumI -> we add the current element to our sum or go next without add it
3. SubsetSumII -> I'll iterate for every element from i -> n and generate all the possible subset then push it in the call , we avoid duplicates by consider that for every original iteration for the function we check the equality (i!= ind & & arr[i]==arr[i-1]) here i call the index twice so I avoid this , and when I back from the recursion I empty the data structure. (My base case come when I reach n (When the loop ends ))
