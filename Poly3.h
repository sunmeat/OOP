#pragma once

class VMT1PolymorphismDemo
{
	class Dog
	{
	public:
		char* name; // 4
		int age; // 4

		void Guard()
		{
			cout << "Dog::Guard\n";
		}
		void Bark()
		{
			cout << "GAV GAV\n";
		}
		int Sum(int x, int y)
		{
			return x + y;
		}

		static void Print()
		{
			cout << "Dog::Print\n";
		}
	};

public:
	static void Test()
	{
		cout << "������ � ������ ���� Dog: ";
		cout << sizeof(Dog) << "\n";

		Dog d;
		cout << "����� ������� d ���� Dog: ";
		cout << &d << " (" << (int)&d << ")\n";

		cout << "����� ������� ���� ������� d: ";
		cout << &d.name << " (" << (int)&d.name << ")\n";

		cout << "����� ������� ���� ������� d: ";
		cout << &d.age << " (" << (int)&d.age << ")\n";

		cout << "����� ������������ ������ ������ Dog: ";
		cout << &Dog::Print << " (��� ";
		cout << &d.Print << ")\n";

		cout << "����� �������� ������ ������ Dog: ";
		void (Dog:: * memfunc_ptr)() = &Dog::Guard;


		int (Dog:: * psum)(int,int) = &Dog::Sum;
		auto test = &Dog::Sum;

		auto cheat = &Dog::Bark;
		cout << memfunc_ptr << "\n";
		Dog* doge = new Dog;
		(doge->*memfunc_ptr)();

		int result = (doge->*psum)(5, 10);
		cout << result << "\n";
		//doge->Sum(1, 2);
		doge->Bark();
	}
};

// VMT1PolymorphismDemo::Test();