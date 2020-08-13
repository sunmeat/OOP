#pragma once

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DPSDataBase // ������ ������, ������� ����� ����� ������ �������������� �� ���� ���������
{
public:

	// �������� ��������� ������ ��������� ��������
	class Violation 
	{
	public: // ������-�� �� �������� ����� ������ ���� ������ private!
		string article; // ������ ��������������
		string name; // �������� �������� ��������������
		string description; // ��������� �������� ��������������
		double penalty; // ����� � ���.
	public:
		// ����� ����� �������-�������, ������������, ����������

	};

	// �����-������� (�������� ��� ����������� STL-������ �������
	class ViolationList
	{
	public: // ����� ������ ���� ������!
		//Violation first;
		//Violation second;
		//Violation third;

		//Violation* ar;
		//int violation_count;

		//Vector<Violation> list; // ��� ����� �������, ���� ����� ����� ���������� �������
		
		//ViolationVector list; // ��� ��������� ���� ���������� ������ ����� � ������ ���������

		//vector<Violation> list; // ���������� ����������� STL-����� ������! ������ �� � ���, ���� ��������� ����� �����, � � ��� ����� ������� ������������ ������
	
		//SLL<Violation> list; // ���� �������� ��������� ��������� ����� ������
		
		//ViolationSLL list;

		list<Violation> list;

	public:
		void AddViolation(const Violation& v)
		{
			list.push_back(v);
		}

		void Print() const
		{
			for (auto v : list)
			{
				cout << v.name << "\n";
			}
		}
	};

	// �����, ������� ��������� ���� "����-��������"
	// ���� ������ ������ ���� - ��� ���� ���� ������ (� ������ ����� ����� ����� ������)
	class KeyValuePair
	{
	public: // ������ ���� private!!
		string car_number; // key
		ViolationList list; // value
	public:
		// ������� ������� ������������ ���������� - �� ��� ����� ������� ���������� ��� ������ �������� �� 2 ������!
	};

	// ������������ ����� (����� �� ������, ���� ����)
	class Person
	{
	public: // ������ ���� private!!
		string name;
		string surname;
	};

	class CarInfo
	{
	public: // ������ ���� private!!
		KeyValuePair info;
		Person driver;
		// �����������:
		// ����, ������� �������� �� ����� ���������� ������
		// ���������� � ������ �������� (����� ����� ���� ��������)
		// ���������� � ���������� �� ����������
	};

	struct Node // one element of the DPSDataBase
	{
		CarInfo* value; // useful data

		Node* parent;
		Node* right;
		Node* left;

		void ShowNode()
		{
			cout << value->info.car_number << "\n";
			cout << value->driver.name << "\n";
			cout << value->driver.surname << "\n";
			value->info.list.Print();
			
		}
	};

	///////////////////////////////////

private:
	Node* root;
	// int count;

public:
	DPSDataBase()
	{
		root = nullptr;
	}

	bool IsEmpty()
	{
		return root == nullptr;
	}

	~DPSDataBase()
	{
		Clear();
	}

private:
	void ShowDPSDataBase(Node* elem)
	{
		if (elem != nullptr)
		{
			ShowDPSDataBase(elem->left);
			elem->ShowNode();
			ShowDPSDataBase(elem->right);
		}
	}

public:
	void ShowDPSDataBase()
	{
		cout << "\n";
		ShowDPSDataBase(root);
		cout << "\n";
	}

private:
	Node* GetRoot()
	{
		return root;
	}

	int GetCount(Node* elem, int count)
	{
		if (elem != nullptr)
		{
			count = GetCount(elem->left, count);
			count++; // 1
			count = GetCount(elem->right, count);
		}
		return count;
	}

public:
	int GetCount()
	{
		int count = 0;
		count = GetCount(root, count);
		return count;
	}

private:
	void Clear(Node* elem)
	{
		if (elem != nullptr)
		{
			Clear(elem->left);
			Clear(elem->right);
			delete elem;

			elem = nullptr;
		}
	}

public:
	void Clear()
	{
		if (!IsEmpty())
		{
			Clear(root);
			root = nullptr;
		}
	}

	// ���� �� ������� ������! ���� ����� �� ������ ����������!
	// ����� ����� ������� ��� ����� ���������� ����� ������� - � ������� �� ������� ��������, ��� �� ����������� ��������������
	// FindNodesByDriver
	// FindNodesByViolation
	Node* FindNodeByCarNumber(const string& car_number)
	{
		if (IsEmpty())
			return nullptr;

		Node* f = root;
		while (true)
		{
			if (car_number < f->value->info.car_number)
			// ��� ������ �� ������� ��������
			//if (driver_surname < f->value->driver.surname)
			// ��� ������ �� ����������� ��������������
			//if (violation < f->value->info.list[i])
			{
				if (f->left != nullptr)
					f = f->left;
				else
					break;
			}
			else if (car_number > f->value->info.car_number)
			{
				if (f->right != nullptr)
					f = f->right;
				else
					break;
			}
			else
				return f;
		}
		return nullptr;
	}

	/*void AddNode(int value)
	{
		if (FindNode(value))
			return;
		Node* n = new Node;
		n->right = n->left = nullptr;
		n->value = value;
		Node* parent = nullptr;
		if (IsEmpty())
		{
			root = n;
			root->parent = nullptr;
		}
		else
		{
			Node* p = root;
			while (p != nullptr)
			{
				parent = p;
				if (n->value > p->value)
					p = p->right;
				else
					p = p->left;
			}

			n->parent = parent;

			if (n->value < parent->value)
				parent->left = n;
			else
				parent->right = n;

		}
	}

	DPSDataBase& operator = (const DPSDataBase& obj)
	{
		if (!IsEmpty())
			Clear();

		AddNode(obj.root->value);
		Copy(obj.root);
		return *this;
	}

	DPSDataBase(const DPSDataBase& obj)
	{
		root = nullptr;
		AddNode(obj.root->value);
		Copy(obj.root);
	}

	void Copy(Node* elem)
	{
		if (elem->left != nullptr)
			AddNode(elem->left->value);
		if (elem->right != nullptr)
			AddNode(elem->right->value);
		if (elem->left != nullptr)
			Copy(elem->left);
		if (elem->right != nullptr)
			Copy(elem->right);
	}

	void DeleteNode(int value)
	{
		Node* d = FindNode(value);
		if (d == nullptr)
			return;

		Node* parent = d->parent;
		if (d == root && GetCount() == 1)
		{
			Clear();
			return;
		}
		if (d->left == nullptr && d->right == nullptr)
		{
			if (parent->left == d)
				parent->left = nullptr;
			else
				parent->right = nullptr;
			delete d;
			return;
		}
		if (d->left == nullptr && d->right != nullptr)
		{
			if (parent->left == d)
			{
				parent->left = d->right;
			}
			else
			{
				parent->right = d->right;

			}
			d->right->parent = parent;
			delete d;
			return;
		}

		if (d->left != nullptr && d->right == nullptr)
		{
			if (parent->left == d)
			{
				parent->left = d->left;
			}
			else
			{
				parent->right = d->left;

			}
			d->left->parent = parent;
			delete d;
			return;
		}
		if (d->left != nullptr && d->right != nullptr)
		{
			Node* r = d->right;
			if (r->right == nullptr && r->left == nullptr)
			{
				d->value = r->value;
				d->right = nullptr;
				delete r;
			}
			else if (r->left != nullptr)
			{
				Node* p = r->left;
				while (p->left != nullptr)
					p = p->left;
				d->value = p->value;
				if (p->right == nullptr)
					p->parent->left = nullptr;
				else
					p->parent->left = p->right;
				delete p;
			}
			else
			{
				d->value = r->value;
				d->right = r->right;
				delete r;
			}
		}
	} */
};