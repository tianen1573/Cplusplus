#define _CRT_SECURE_NO_WARNINGS 1

//#include"myStack.h"
//void test_stack()
//{
//	
//	qlz::stack<int> st;
//
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);
//
//	while (!st.empty())
//	{
//		cout << st.top() << endl;
//		st.pop();
//	}
//}

//#include"myQueue.h"
//void test_queue()
//{
//	qlz::queue<int, list<int>> q;
//
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	while (!q.empty())
//	{
//		cout << q.front() << endl;
//		q.pop();
//	}
//}

#include"priority_queue.h"
#include<algorithm>
void test_priority_queue()
{
	qlz::priority_queue<int, vector<int>, greater<int>> priQue;



	priQue.push(3);
	priQue.push(4);
	priQue.push(2);
	priQue.push(7);

	while (!priQue.empty())
	{
		cout << priQue.top() << endl;
		priQue.pop();
	}
}

int main()
{
	//test_stack();

	//test_queue();

	test_priority_queue();

	return 0;
}