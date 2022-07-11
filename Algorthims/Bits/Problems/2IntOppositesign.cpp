//The XOR of x and y will have the sign bit as 1 iff they have opposite sign.
bool oppositeSign(int x , int y){return((x^y)<0);}