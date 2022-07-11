/*
Read the Prefix expression in reverse order (from right to left)
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack 
Create a string by concatenating the two operands and the operator between them. 
string = (operand1 + operator + operand2) 
And push the resultant string back to Stack
Repeat the above steps until the end of Prefix expression.
At the end stack will have only 1 string i.e resultant string
*/

#include <bits/stdc++.h>

using namespace std;
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '%':
    return true;
  }
  return false;
}
string preToPost(string pre_exp)
{
    stack<string>s;
     int length = pre_exp.size();
     for (int i = length-1; i>=0;i--)
     {
         if (isOperator(pre_exp[i]))
         {
             string op1=s.top();s.pop();
             string op2=s.top();s.pop();
             // concat the operands and operator(The difference between it and infix conversation)
             string temp=op1+op2+pre_exp[i];
             s.push(temp);
         }
         else {
 
            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
     }
     return s.top();
}
int main()

{
string pre_exp = "*-A/BC-/AKL";
    cout << "Postfix : " << preToPost(pre_exp);
    return 0;
}