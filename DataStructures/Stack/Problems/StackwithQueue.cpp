/*
push(s, x) operation’s step are described below: 
Enqueue x to q2
One by one dequeue everything from q1 and enqueue to q2.
Swap the names of q1 and q2
pop(s) operation’s function are described below: 
Dequeue an item from q1 and return it.
*/
/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
	// Two inbuilt queues
	queue<int> q1, q2;

	// To maintain current number of
	// elements
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}

	void push(int x)
	{
		curr_size++;

		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{

		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size()
	{
		return curr_size;
	}
};

// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size()
		<< endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size()
		<< endl;
	return 0;
}


//using on queue

/*
Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
pop(): remove the element from the queue.
top(): show the element at the top of the queue.
size(): size of the current queue.

*/
#include<bits/stdc++.h>

using namespace std;
class Stack
{
    queue<int>q;
    public:
    void push(int x )
    {
        int s = q.size();
        q.push(x);
        for (int i  = 0 ; i<s;i++)
        {
            q.push(q.front());
            q.pop();

        }
    }
    int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};
