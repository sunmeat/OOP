#pragma once

class VMT3PolymorphismDemo
{
	class Dog
	{

		// void** __vfptr;
		// VPTR - ��������� �� ������� VTABLE (�� ������ ��������� �� ������ ������!)

		// static void* Dog::vftable[2];
		// ���� "�������" (������ ���� �� ��� �������!)
		
	public:
		char* name;
		int age;

		/* Dog()
		{
			// __vfptr = Dog::vftable; // ������� ���������� ��������� � ��������

			// ... ������ ����� �������� ������������
		} */
		
		virtual void Guard() // &Guard (����� ������) - by index 0 in vftable
		{
			cout << "Dog::Guard\n";
		}
		
		virtual void Bark() // &Bark - by index 1 in vftable
		{
			cout << "Dog::Bark\n";
		}

		static void Print()
		{
			cout << "Dog::Print\n";
		}
	};

	class Mops : public Dog
	{

		// ���������������
		// void** __vfptr; // VPTR - ��������� �� ������� VTABLE (�� ������ ��������� �� ������ ������)

		// ����������� ���������� �� �����������, - ��� ��� ����� �������!
		// static void* Mops::vftable[2]; // ������� (���� �� �����)

	public:
		int mops_field;

		/* Mops()
		{
			// __vfptr = Mops::vftable; // ������� ���������� ��������� � ����� ��������

			// ... ������ ����� �������� ������������
		} */
		
		virtual void Guard() override // ��������������� ������ ����, ������� � "�������" - ����� ����� 
		{
			cout << "Mops::Guard\n";
		}
		
		virtual void Bark() override // �� �� ����� ��� Bark
		{
			cout << "Mops::Bark\n";
		}
	};


public:
	static void Test()
	{
		Mops m;
		cout << "����� ������� m ���� Mops: ";
		cout << &m << "\n";
		// ����� ����� ��������� ����������
		// � ��������� ������� ������� Mops

		//////////////////////////////////////////////////////////////////////

		// ��������� ��������� VTABLE ��� ������ Dog:
		// Dog::vftable[0] = &Dog::Guard;
		// Dog::vftable[1] = &Dog::Bark;

		Dog* d = new Dog;
		// � ������������ Dog() ��� ����������� ���������� ������� ��������� ���������� VPTR � VTABLE
		// __vfptr = Dog::vftable;

		d->Guard(); // <--- ��, �������, ����� ��� :)

		// � �� ����� ����, ���������� ���� ����������� ���-�� �����:
		// d->__vfptr[0](); // 0 - ��� ������ ������ Guard

		d->Bark(); // pd->__vfptr[1]();

		Dog* dd = new Mops();
		dd->Bark();
	}
};

// VMT3PolymorphismDemo::Test();