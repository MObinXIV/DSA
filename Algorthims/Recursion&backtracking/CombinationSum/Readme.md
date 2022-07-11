# Combination Sum problems

1. CombinationSumI -> Normal pick not pick technique , the only difference is that we pick the same index till it exhausted
2. CombinationII -> I generate all subsequences for every number & I have the case which skip the call from last , I keep subtract the target from the elements & in case I make the target =0 this is when I push the whole array to my answer.
3. CombinationSumIII ->Another variation of CombinationSumI -> I treat the numbers from 1 -> 9 as array with unique numbers.
