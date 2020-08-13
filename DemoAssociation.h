#pragma once

#include <iostream>
#include <string>
using namespace std;

class Asso�iationDemo
{
	class Person
	{
	public:
		string name;
		string surname;
	};

	class Cat
	{
	public:
		string nick;
		string suit;

		void PlayWith(const Person& person) const
		{
			cout << "cat " << nick << " is playing with " << person.name << "\n";
		}
	};

public:
	static void Test()
	{
		Cat c;
		c.nick = "Barsik";

		Person p;
		p.name = "Alex";

		c.PlayWith(p);
	}
};

// Asso�iationDemo::Test();
