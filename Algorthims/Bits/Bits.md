__Xor -> even 1 get 0 and odd 1 get 1
__~ -> flip bits
__>>(right shift)-> we right shift bits (remove bits from lsb ) -> 5>>1(101)>>1=010, فى حالة الرايت شيفت انا بحرك البيتس من الشمال ناحية اليمين يعنى الموضوع = number/2^n(الرقم اللى ناحية الشيفت)

__<<(Left Shift) -> opposite of right shift hahaha

--Not repeating element : Xoring  all بيكنسلو بعض  و يفضل رقم واحد اللى هو مختلف و مش هيتكنسل

__Swap -> (a,b)..... (1) a=a^b. (2)b=a^b.  (3) a = a^b
__Find Xor(l-r)-> we do Xor(1-R) ^ (1-(l-1))

__Even or Odd -> if ( n&1==0) even;  else odd (in the fact that the last odd of the odd number will always be set)

__To Set ith bit we create the same mask in ith bit set but we oring not anding

__Clear The i-th bit  --> mask= ~(1<<n) then (n& mask)
__Remove last set bit -> (n * n-1)

__ check if the number is powerset of 2 -> if (n&n-1==0) true ; else false

__Count the number of set bits -> while (n!=0) if(n&1) cnt++; n=n>>1; / while (n!=0)n=n&(n-1) ; cnt++;

• __builtin_clz(x): the number of zeros at the beginning of the bit representation
•__builtin_ctz(x): the number of zeros at the end of the bit representation
• __builtin_popcount(x)/__builtin_popcountll(x): the number of ones in the bit representation
• __builtin_parity(x): the parity (even or odd) of the number of ones in the bit representation
