#pragma once

class VirtualDestructorDemo
{
	
	class Transport
	{
	protected:
		double speed;

	public:
		Transport()
		{
			cout << "Transport::CTOR\n";
		}
		~Transport()
		{
			cout << "Transport::DEST\n";
		}
	};

	
	class Truck : public Transport // ��������
	{
		char* load; // ����

	public:
		Truck()
		{
			cout << "Truck::CTOR\n";
			load = new char[100000]; // ������ �������� �������� ��� ���� 100.000 ����
		}
		~Truck()
		{
			cout << "Truck::DEST\n";
			delete[] load;
		}
	};

	
	class Minibus : public Transport // ���������
	{
		int* passengers;

	public:
		Minibus()
		{
			cout << "Minibus::CTOR\n";
			passengers = new int[rand() % 40];
		}
		~Minibus()
		{
			cout << "Minibus::DEST\n";
			delete[] passengers;
		}
	};

public:
	static void Test()
	{
		Truck t;
		_getch();
		cout << "\n";

		Minibus m;
		_getch();
		cout << "\n";

		Transport* ar[2];

		ar[0] = new Truck;
		_getch();
		cout << "\n";

		ar[1] = new Minibus;
		_getch();
		cout << "\n";

		for (int i = 0; i < 2; i++)
			delete ar[i];

		_getch();
		cout << "\n";
	}
};

// VirtualDestructorDemo::Test();