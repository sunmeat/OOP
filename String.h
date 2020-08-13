#pragma once

#include <iostream>
using namespace std;

class String
{
	char* text;
	unsigned int length;
	unsigned int capacity;

public:
	String(const char* text, unsigned int capacity = 80)
	{
		Initialize(text);
	}

	explicit operator int() { return 1; }

	// ������ ���������� ��������� ���������� []
	char& operator[](unsigned int index)
	{
		if (index >= length || index < 0) throw "OOPS!";
		else return text[index];
	}

	String()
	{
		Initialize("");
	}

	String(unsigned int capacity)
	{
		Initialize("", capacity);
	}

	String(const String& original)
	{
		Initialize(original.text, original.capacity);
	}

	~String()
	{
		delete[] text;
	}

	// �������-�������
	const char* GetString() const
	{
		return text;
	}

	void SetString(const char* text)
	{
		length = strlen(text);
		if (length >= capacity)
		{
			delete[] this->text;
			capacity = length + 20;
			this->text = new char[capacity];
		}
		strcpy_s(this->text, length + 1, text);
	}

	int GetLength() const
	{
		return length;
	}

	// ������ SetLength �� ������ ����!

	int GetCapacity() const
	{
		return capacity;
	}

	void Clear()
	{
		text[0] = '\0';
		length = 0;
	}

	void ShrinkToFit()
	{
		if (length + 1 == capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}

private:
	void Initialize(const char* str, int capacity = 80) {
		length = strlen(str);
		this->capacity = (capacity > length) ? capacity : length + 20;
		this->text = new char[this->capacity];
		strcpy_s(this->text, length + 1, str);
	}

public:
	String& operator()(const char* value)
	{
		// ������� ������ �� ������ ������
		if (text != nullptr) delete[] text;

		// ������� ����� ���������� ������ +1 ��� ������� � ����� 0
		int l = strlen(value) + 1;

		text = new char[l];
		strcpy_s(text, l, value);

		capacity = l;
		length = l - 1;

		return *this;
	}

	//friend ostream& operator <<(ostream& os, const String& obj);
};

ostream& operator <<(ostream& os, const String& obj)
{
	cout << obj.GetString() << "\n";
	return os;
}