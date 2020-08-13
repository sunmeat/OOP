#pragma once

class VMT2PolymorphismDemo
{
	class Dog
	{
	public:
		char* name; 
		int age;
		
		virtual void Guard()
		{
			cout << "Dog::Guard\n";
		}
		virtual void Bark()
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
	public:
		int mops_field;

		virtual void Guard() override
		{
			cout << "Mops::Guard\n";
		}
		virtual void Bark() override
		{
			cout << "Mops::Bark\n";
		}
	};
	

public:
	static void Test()
	{
		cout << "������ � ������ ���� Dog: ";
		cout << sizeof(Dog) << "\n";

		cout << "������ � ������ ���� Mops: ";
		cout << sizeof(Mops) << "\n\n";

		Mops d;
		cout << "����� ������� d ���� Mops: ";
		cout << &d << " - " << (int)(&d) << "\n";

		cout << "����� ������� ���� ������� d: ";
		cout << &d.name << " - " << (int)(&d.name) << "\n";

		cout << "����� ������� ���� ������� d: ";
		cout << &d.age << " - " << (int)(&d.age) << "\n";

		cout << "����� �������� ���� ������� d: ";
		cout << &d.mops_field << " - " << (int)(&d.mops_field) << "\n";
	}
};

// VMT2PolymorphismDemo::Test();