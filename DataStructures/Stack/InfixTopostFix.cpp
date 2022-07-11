#include<bits/stdc++.h>

using namespace std;
// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    stack<char>st;
    string result;
    for (int i =0;i<s.size();i++)
    {
        char c = s[i];
        //check for operand 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;//We add the result to string in case of operand 
            // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

            else if (c==')') //we will pop from the stack till we find (
                {
                    while(st.top()!='(')
                    {
                        result+=st.top();
                        st.pop();
                    }
                    //pop (
                        st.pop();
                }
                else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) //check for precednece valdity before we push
            {
                if (c == '^' && st.top() == '^')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }

    }
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
}
int main()

{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
}