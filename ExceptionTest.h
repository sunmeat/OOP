#pragma once

class ExceptionExamples
{
public:
	// ������������ ������ ��������� ������ � ����� ����� �
	static double Divide(double a, double b, bool& error)
	{
		if (b == 0)
		{
			error = true;
			return 0;
		}
		return a / b;
	}

	static void CStyleExceptions()
	{
		double a, b;
		bool error = false;
		cout << "Enter a numerator: ";
		cin >> a;
		cout << "Enter a denominator: ";
		cin >> b;
		double result = Divide(a, b, error);
		if (error)
			cout << "Divide by zero!\n";
		else
			cout << "Result: " << result << "\n";

		cout << "CStyleExceptions DONE\n";
	}

	////////////////////////////////////////////////////////////

	class Stack
	{
		enum { max = 5 };
		int mass[max];
		int top = 0;

	public:
		void Push(int number)
		{
			if (top < max)
				mass[top++] = number;
			else
				throw "Stack overflow!";
				// ��������� ���������� � ����� �++
		}

		int Pop()
		{
			if (top > 0)
				return mass[--top];
			else
				throw "Stack is empty!";
		}
	};

	static void CPPStyleExceptions()
	{
		Stack st;

		// st.Pop(); // OOPS!

		st.Push(1);
		st.Push(2);
		st.Push(3);
		st.Push(4);
		st.Push(5);

		// st.Push(6); // OOPS!

		cout << "CPPStyleExceptions DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void TryCatchExample()
	{
		cout << "������ �������\n";

		// throw 500;

		try // ���� � �������������� ����
		{
			cout << "��������� �� ��������� ����������\n";
			throw 404;
			cout << "��������� ����� ��������� ����������\n"; // dead code
		}
		catch (int& value)
		{
			cout << "���� ������� ���������� (������ ���� int �� ��������� " << value << ")\n";
		}

		cout << "����� �������.\n";
		cout << "TryCatchExample DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void DivideByZeroException()
	{
		// http://stackoverflow.com/questions/6121623/catching-exception-divide-by-zero
		// http://stackoverflow.com/questions/4747934/c-catch-a-divide-by-zero-error

		cout << "������ �������\n";

		float a, b;
		cout << "������� 2 �����: ";
		cin >> a >> b;

		try
		{
			if (b == 0) throw b;
			cout << "���������:  " << a / b << "\n";
		}
		catch (float& f)
		{
			cout << "�� ���� ������ �� ����!\n";
		}

		cout << "����� �������.\n";
		cout << "DivideByZeroException DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void HardwareExceptions()
	{
		// ����������� ���������� ���������� �� ���������������!
		// https://docs.microsoft.com/ru-ru/cpp/cpp/hardware-exceptions?view=vs-2019
		try
		{
			double a, b;
			cout << "Enter a numerator: ";
			cin >> a;
			cout << "Enter a denominator: ";
			cin >> b;
			cout << a / b; // ���������� �� �������������!
		}
		catch (...)
		{
			cout << "Divide by zero!\n";
		}
		cout << "HardwareExceptions DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void SeveralCatches()
	{
		// ������ ����� ���� ���������!
		int size;
		int* ar = nullptr;

		cout << "������� ������ �������: ";
		cin >> size;

		try
		{
			if (size < 1 || size > 500)
				throw "Error size!";

			ar = new int[size];

			// ���������, ���������� �� ������
			if (!ar)
				throw "Error memory!";

			cout << "��������...\n";
			throw 0;
		}
		catch (int) // �������� ��������� ��������� �������������
		{
			cout << "������ ����������, ��������������� ��� ����� �����\n";
		}
		catch (char* message)
		{
			MessageBoxA(0, message, "Runtime Error", MB_OK | MB_ICONERROR);
		}
		catch (...) // ������������� ���� ��� ���� ��������������� ����������
		{
			cout << "\nSome error!\n\n";
		}

		cout << "SeveralCatches DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void SeveralCatches2()
	{
		try
		{
			int n;
			cout << "Enter a number (1 - 4): ";
			cin >> n;
			switch (n)
			{
				case 1: throw 10; break;
				case 2: throw 5.5; break;
				case 3: throw "Error"; break;
				case 4: throw 'A'; break;
				default: throw true;
			}
		}
		catch (int n)
		{
			cout << "\nType of exception - int\n";
		}
		catch (double n)
		{
			cout << "\nType of exception - double\n";
		}
		catch (char* s)
		{
			cout << "\nType of exception - string\n";
		}
		catch (char n)
		{
			cout << "\nType of exception - char\n";
		}
		catch (...)
		{
			cout << "\nOther type of exception\n";
		}

		cout << "SeveralCatches2 DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void CheckBattery()
	{
		SYSTEM_POWER_STATUS status;
		GetSystemPowerStatus(&status);
		int life = status.BatteryLifePercent;

		if (status.ACLineStatus == 1) cout << "Battery Charging\n";
		else if (life < 80) throw "Critical Battery Life Percent!";
		else if (life < 90) cout << "Battery Low with " << life << "%\n";
		else cout << "Battery High with " << life << "%\n";
	}

	static unsigned long long counter;

	static void DoHardWork()
	{
		for (int i = 0; i < 987654321; i++)
		{
			counter++;
		}
		cout << counter << "\n";
	}

	static void SaveProgress()
	{
		FILE* f;
		fopen_s(&f, "C:\\1\\1.txt", "a+");
		fwrite(&counter, sizeof(counter), 1, f);
		cout << "successfully saved!\n";
		fclose(f);
		system("C:/1/1.txt");
	}

	static void ExceptionInFunction()
	{
		try
		{
			while (true)
			{
				DoHardWork();
				CheckBattery();
			}
		}
		catch (char* message)
		{
			cout << message << "\n";
			SaveProgress();
		}

		cout << "ExceptionInFunction DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void FunctionTryBlock()
	{
		// https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2010/e9etx778(v=vs.100)?redirectedfrom=MSDN
		cout << "FunctionTryBlock DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void ExceptionInDestructor()
	{
		class Test
		{
		public:
			~Test()
			{
				cout << "DESTRUCTOR\n";
				throw "EXCEPTION";
			}
		};

		try
		{
			// Test ar; // ��
			cout << "Test ar[5]; with exception in destructor...\n";
			Test ar[5]; // ���!
		}
		catch (char* message)
		{
			cout << message << "\n";
		}

		/*

C++ �� ��������� ������������ ���������� � ������������,
�� ���, ����������, ����� ������������� ��������.
�� �� ���� ��������� �������. ���������� ������:

class Widget {
public:
...
~Widget() {...} // �����������, ����� ���� ����������
};
void doSomething()
{
std::vector v;
...
} // ����� v ������������� ������������

����� ������ v ������������, �� �������� �� �����������
���� �������� Widget, ������� � ��� ����������.
�����������, ��� v �������� 10 �������� Widget, � �� �����
����������� ������� �� ��� ������������
����������. ��������� ������ �������� Widget ����� ������
���� ���������� (����� �������, ����������
��� ���, ����� ��������), ������� ���������� ������� � ��
�����������. �� ����������, ��� � ��� �����
���������� ������� ������� Widget ����� ����������� ����������.
����� ��������� ����� ��� ������������
�������� ����������, � ��� ��� ������� ����� ��� C++.
� ����������� �� ���������� ������� ����������
��������� ���� ����� ��������, ���� �� ��������� ��������
�������������. � ���� ������� ��� ���
����� ����� ������ ������. � ��� ����� ����������� ���
������������� ������ �������������
���������� (��������, list, set), � ���� �������. � �������
���� �������� �� � ����������� ��� ��������.
��������������� ���������� ��������� ��� �������������
��������� ����� �������� ����������� ����,
��� ����������� ���������� ����������.
*/

		cout << "ExceptionInDestructor DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void ThrowGenerator()
	{
		try
		{
			throw "����!";
		}
		catch (char* message)
		{
			cout << "� ������� ThrowGenerator: " << message << "\n";
			throw; // �������� ���������� ���������� catch	
		}
	}

	static void ReThrowing()
	{
		cout << "����� �������\n";
		try
		{
			ThrowGenerator();
		}
		catch (char* message)
		{
			cout << "� ������� ReThrowing: " << message << "\n";
			// throw;
		}
		cout << "����� �������\n";

		cout << "ReThrowing DONE\n";

		/*
		������:
1) ������ ������ � ������ ������������ � ���������
����������� � ���������� ��� (����� ������ ���� ��������
��� ��������).
2) throw; ��������� ������, ���������� ������ ����
������ � ������������� ����
		*/
	}

	////////////////////////////////////////////////////////////

	static bool KnownException()
	{
		try
		{
			throw;
		}
		catch (const int&)
		{
			cout << "caught int.\n";
			return true;
		}
		catch (const double&)
		{
			cout << "caught double.\n";
			return true;
		}
		catch (const char*)
		{
			cout << "caught char*.\n";
			return true;
		}

		return false;
	}

	static void ReThrowing2()
	{
		try
		{
			throw "oops!";
		}
		catch (...)
		{
			if (!KnownException())
			{
				cerr << "unknown exception...\n";
			}
		}

		cout << "ReThrowing2 DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void CustomExceptions()
	{
		class Exception
		{
		protected:
			string message;
			int code;

		public:
			Exception()
			{
				message = "";
			}

			Exception(string message)
			{
				this->message = message;
			}

			virtual void WhatHappened()
			{
				cout << message << "\n";
			}
		};

		class JobImpossible : public Exception
		{
		public:
			JobImpossible()
			{
				message = "";
			}

			JobImpossible(string message) : Exception(message) {}
		};

		class WorkerIsBusy : public JobImpossible // �������� ��� ���-�� �����
		{
		protected:
			string finish_working;
			string work_description;

		public:
			WorkerIsBusy()
			{
				message = "";
			}

			WorkerIsBusy(string message) : JobImpossible(message) {}

			string GetFinishWorking()
			{
				return finish_working;
			}

			void SetFinishWorking(string finish_working)
			{
				this->finish_working = finish_working;
			}

			string GetWorkDescription()
			{
				return work_description;
			}

			void SetWorkDescription(string work_description)
			{
				this->work_description = work_description;
			}
		};

		class ForceMajor : public JobImpossible // ��������� ��
		{

		protected:
			double damage;
			string forcemajor_description;

		public:
			ForceMajor()
			{
				message = "";
			}

			ForceMajor(string message) : JobImpossible(message) {}

			double GetDamage()
			{
				return damage;
			}

			void SetDamage(double damage)
			{
				this->damage = damage;
			}

			string GetForcemajorDescription()
			{
				return forcemajor_description;
			}

			void SetForcemajorDescription(string forcemajor_description) {
				this->forcemajor_description = forcemajor_description;
			}
		};

		class ToolsCrush : public JobImpossible // ���-�� ���������
		{
		protected:
			string toolcrush_description;

		public:
			ToolsCrush()
			{
				message = "";
			}

			ToolsCrush(string message) : JobImpossible(message) {}

			string GetToolcrushDescription()
			{
				return toolcrush_description;
			}

			void SetToolcrushDescription(string toolcrush_description)
			{
				this->toolcrush_description = toolcrush_description;
			}
		};

		class Worker
		{
		private:
			bool is_working;

		public:
			Worker()
			{
				is_working = false;
			}

			// http://stackoverflow.com/questions/1055387/throw-keyword-in-functions-signature-c
			void Work() throw (WorkerIsBusy, ToolsCrush)
			{
				if (is_working)
				{
					throw WorkerIsBusy("������� �����!");
				}
				else
				{
					if (VerificateTools())
					{
						is_working = true;
						cout << "������� ��������...\n";
						Sleep(1000);
						is_working = false;
						cout << "������� �������� ������!\n";

						// �������� � catch (Exception exc), ���� � ��� ����� ��� ForceMajor
						// throw ForceMajor("��������� �����!\n");
					}
					else
					{
						throw ToolsCrush("������� c�������!\n");
					}
				}
			}

		private:
			bool VerificateTools()
			{
				int k = rand() % 2;
				return k != 0 ? true : false;
			}
		};

		Worker Andrew;

		try
		{
			Andrew.Work();
		}
		catch (ToolsCrush& ex)
		{
			ex.WhatHappened();
		}
		catch (WorkerIsBusy& ex)
		{
			ex.WhatHappened();
		}
		catch (Exception& ex)
		{
			ex.WhatHappened();
		}
		catch (...)
		{
			cout << "����� ������...";
		}

		cout << "CustomExceptions DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void PolymorphicException()
	{
		class Roots
		{
		protected:
			double a, b, c;
		public:
			Roots(double n, double m, double k)
			{
				a = n;
				b = m;
				c = k;
			}
			virtual void Result() = 0;
		};

		class NoRoots : public Roots
		{

		public:
			NoRoots(double n, double m, double k) : Roots(n, m, k) { }
			virtual void Result()
			{
				cout << "Equation has no any roots\n";
			}
		};

		class OneRoot : public Roots
		{
		public:
			OneRoot(double n, double m, double k) : Roots(n, m, k) { }
			virtual void Result()
			{
				double x = -b / (2 * a);
				cout << "One root: " << x;
			}
		};

		class TwoRoots : public Roots
		{
		public:
			TwoRoots(double n, double m, double k) : Roots(n, m, k) { }
			virtual void Result()
			{
				double d = b * b - 4 * a * c;
				double x1 = (-b + sqrt(d)) / (2 * a);
				double x2 = (-b - sqrt(d)) / (2 * a);
				cout << "X1 = " << x1;
				cout << "\nX2 = " << x2;
			}
		};

		double a, b, c;
		cout << "Input number: ";
		cin >> a >> b >> c;
		try
		{
			double d = b * b - 4 * a * c;
			if (d == 0)
				throw OneRoot(a, b, c); // <<< �����
			else if (d > 0)
				throw TwoRoots(a, b, c);
			else
				throw NoRoots(a, b, c);
		}
		catch (Roots& a)
		{
			a.Result();
		}

		cout << "PolymorphicException DONE\n";
	}

	////////////////////////////////////////////////////////////

	// headers in Application.h:
	// #include <stdexcept> // std::out_of_range
	// #include <bitset>

	static void StdExcept()
	{
		// http://www.cplusplus.com/reference/stdexcept/

		vector<int> v(10);
		try
		{
			v.at(20) = 100; // vector::at throws an out-of-range
		}
		catch (const out_of_range& ex)
		{
			cout << "Out of Range error: " << ex.what() << '\n';
		}

		try
		{
			// vector throws a length_error if resized above max_size
			v.resize(v.max_size() + 1);
		}
		catch (const length_error& ex)
		{
			cout << "Length error: " << ex.what() << '\n';
		}

		try
		{
			// bitset constructor throws an invalid_argument if initialized
			// with a string containing characters other than 0 and 1
			bitset<5> mybitset(string("01234"));
		}
		catch (const invalid_argument& ex)
		{
			cout << "Invalid argument: " << ex.what() << '\n';
		}

		cout << "StdExcept DONE\n";
	}

	////////////////////////////////////////////////////////////
	
	static void WhereIsFinally()
	{
		// http://programmers.stackexchange.com/questions/197562/why-is-there-no-finally-construct-in-c

		// Because C++ supports an alternative that is almost
		// always better: The "resource acquisition is
		// initialization" technique. The basic idea is to
		// represent a resource by a local object, so that the
		// local object's destructor will release the resource.
		// That way, the programmer cannot forget to release
		// the resource.

		// It's really just a matter of understanding the
		// philosophy and idioms of C++. Take your example of
		// an operation that opens a database connection on
		// a persistent class and has to make sure that it
		// closes that connection if an exception is thrown.
		// This is a matter of exception safety and applies to
		// any language with exceptions (C++, C#, Delphi...).

		// In a language that uses try / finally, the code
		// might look something like this:

		/*
		database.Open();
		try {
			database.DoRiskyOperation();
		}
		finally {
			database.Close();
		} */

		// Simple and straightforward.There are, however,
		// a few disadvantages:

		// 1) If the language doesn't have deterministic
		// destructors, I always have to write the finally
		// block, otherwise I leak resources.

		// 2) If DoRiskyOperation is more than a single method
		// call and if I have some processing to do in the
		// try block - then the Close operation can end up
		// being a decent bit away from the Open operation.
		// I can't write my cleanup right next to my acquisition.
		
		// 3) If I have several resources that need to be
		// acquired then freed in an exception - safe manner,
		// I can end up with several layers deep of
		// try / finally blocks.

		// The C++ approach would look like this :

		// ScopedDatabaseConnection scoped_connection(database);
		// database.DoRiskyOperation();

		// This completely solves all of the disadvantages
		// of the finally approach. It has a couple of
		// disadvantages of its own, but they're relatively minor:

		// - There's a good chance you need to write the
		// ScopedDatabaseConnection class yourself. However,
		// it's a very simple implementation - only 4 or 5 lines of code.
		// - It involves creating an extra local variable -
		// which you're apparently not a fan of, based on
		// your comment about "constantly creating and destroying
		// classes to rely on their destructors to clean up your
		// mess is very poor" - but a good compiler will
		// optimize out any of the extra work that an extra
		// local variable involves. Good C++ design relies
		// a lot on these sorts of optimizations.
		
		// Personally, considering these advantages and disadvantages,
		// I find RAII a much preferable technique to finally.
		// Your mileage may vary.

		// Finally, because RAII is such a well - established
		// idiom in C++, and to relieve developers of some
		// of the burden of writing numerous Scoped... classes,
		// there are libraries like ScopeGuardand Boost.ScopeExit
		// that facilitate this sort of deterministic cleanup.

		// ��� RAII :
		// https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D0%BB%D1%83%D1%87%D0%B5%D0%BD%D0%B8%D0%B5_%D1%80%D0%B5%D1%81%D1%83%D1%80%D1%81%D0%B0_%D0%B5%D1%81%D1%82%D1%8C_%D0%B8%D0%BD%D0%B8%D1%86%D0%B8%D0%B0%D0%BB%D0%B8%D0%B7%D0%B0%D1%86%D0%B8%D1%8F

		// ��������� ������� ���� ������������� (Resource Acquisition Is Initialization(RAII))
		// � ����������� ������ ��������-���������������� ����������������,
		// ����� ������� ����������� � ���, ��� � ������� ���
		// ��� ���� ����������� ���������� ��������� ����������
		// ������� ���������� ����������� � ��������������,
		// � ������������ � � ������������ �������.

		// �������� (���� � �� ������������) �������� ����������
		// �������� ����������� ��������� ������� � �������
		// � ������������, � ������������ � � �����������
		// ���������������� ������. ��������� ����������
		// �������������� ���������� ���������� ��� ������ �
		// �� ������� ���������, �� ������ ��������������
		// ������������� ��� ����������� ����������. ���
		// ����������� � � ���������, � ������� ���������
		// ����������. ��� ������ RAII �������� ���������� ���
		// ��������� ����������� ��� ����������� ���� � ������
		// ����������������, ��� ������������ � �����������
		// �������������� �������� ���������� �������������,
		// ������ ����� � � C++.

		// � ������, � ����������� C++ __finally ���� :)

		// http://architecturenet.ru/net%203/Index0.html
		// https://msdn.microsoft.com/en-us/library/9xtt5hxz.aspx

		cout << "WhereIsFinally DONE\n";
	}
	
	////////////////////////////////////////////////////////////
	
	static void SamuraiPrinciple()
	{
		// http://sergeyteplyakov.blogspot.com/2011/09/blog-post_13.html
	}

	////////////////////////////////////////////////////////////
	
	static void UseNewOrNot()
	{
		// https://stackoverflow.com/questions/6801796/c-throwing-exceptions-use-new-or-not
		cout << "UseNewOrNot DONE\n";
	}

	////////////////////////////////////////////////////////////

	static void Test()
	{
		CStyleExceptions();
		// CPPStyleExceptions();
		// TryCatchExample();
		// DivideByZeroException();
		// HardwareExceptions();
		// SeveralCatches();
		// SeveralCatches2();
		// ExceptionInFunction();
		// FunctionTryBlock();
		// ExceptionInDestructor();
		// ReThrowing();
		// ReThrowing2();
		// CustomExceptions();
		// PolymorphicException();
		// StdExcept();
		// WhereIsFinally();
		// SamuraiPrinciple();
		// UseNewOrNot();
	}
};

unsigned long long ExceptionExamples::counter;

// ExceptionExamples::Test();
