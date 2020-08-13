#pragma once

class Stack
{
	// SIZE - ������������ ���������� ��������� � ����� (������ 10 �� �� �����!)
public:
	enum { SIZE = 10, EMPTY = 0 };

private:
	int ar[SIZE]; // � �������� ��������� ��������� ����� ������ ������
	int top = EMPTY; // ������ ������� �����

public:
	void Clear()
	{
		top = EMPTY;
	}

	bool IsEmpty()
	{
		return top == EMPTY;
	}

	bool IsFull()
	{
		return top == SIZE;
	}

	int GetCount()
	{
		return top;
	}

	// "������������" (����������) �������� � ����
	void Push(int value)
	{
		if (IsFull())
			throw "Stack overflow!";
		
		ar[top++] = value;
	}

	// ���������� �������� �� �����
	int Pop()
	{
		if (IsEmpty())
			throw "Stack is empty!";

		top--;
		return ar[top];
	}


};

/*
// code for main:

	Stack st;

	while (st.IsFull() == false)
		st.Push(rand() % 90 + 10);

	while (st.IsEmpty() == false)
		cout << st.Pop() << "  ";
*/