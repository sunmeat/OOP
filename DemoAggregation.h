#pragma once

#include <iostream>
#include <string>
using namespace std;

class AggregationDemo
{
	class Hat
	{
	public:
		string color;
		string model;
		double price;
	};

	class Person
	{
	public:
		string name;
		Hat* hat;

		void TakeHat(Hat* hat)
		{
			this->hat = hat;
		}

		void GoWalk()
		{
			cout << "�������� ����� �����...\n";
			hat = nullptr;
		}

		void WhereIsYourHat()
		{
			cout << "where is your ha-a-at, is your ha-a-at, person? � ��� ���:  " << hat << "\n";
		}
	};

public:
	static void Test()
	{
		Hat* nice_hat = new Hat();
		Person alex;
		
		alex.TakeHat(nice_hat);
		alex.WhereIsYourHat();
		alex.GoWalk();
		alex.WhereIsYourHat();
		cout << "����� ����� � �����: " << nice_hat << "\n";
	}
};

// AggregationDemo::Test();