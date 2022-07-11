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
#include<bits/stdc++.h>

using namespace std;

// function to check if character is operator or not
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
string preToInfix(string pre_exp) 
{
    stack<string> s;
    for (int i = pre_exp.size()-1;i>=0;i--)
    {
        if(isOperator(pre_exp[i]))
        {
            string op1=s.top();
            s.pop();
            string op2 = s.top();   s.pop();
 
      /// concat the operands and operator(The difference between it and )
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";
 
      // Push string temp back to stack
      s.push(temp);
        }
        else {
 
      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
    
    }
    // Stack now contains the Infix expression
  return s.top();
}
int main()
{
    string pre_exp = "*-A/BC-/AKL";
  cout << "Infix : " << preToInfix(pre_exp);
}