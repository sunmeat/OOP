#pragma once

#include <iostream>
using namespace std;

class Fraction
{
	int numerator; // ���������
	int denominator; // �����������

public:
	Fraction();
	Fraction(int chis, int znam);

	// ����������� ��������������
	explicit Fraction(int value)
	{
		numerator = value;
		denominator = 1;
	}
	
	Fraction& operator++() // ������ ��� ��������
	{
		numerator += denominator; // �������� ������
		return *this; // ���������� ������
	}

	Fraction operator++(int) // ������ ��� ���������
	{
		numerator += denominator;
		return *this;
	}

	double GetDecimal() const;
	void Print() const;
	void PrintDecimal() const;

	static Fraction Sum(const Fraction& left, const Fraction& right);
	
	bool GreaterThan(const Fraction& another) const;
	bool IsEquals(const Fraction& another) const;
	bool LessThan(const Fraction& another) const;

	int GetNumerator() const;
	int GetDenominator() const;
	void SetNumerator(int chis);
	void SetDenominator(int znam);

	Fraction operator + (/*Fraction* this, */ const Fraction& right);
	Fraction operator + (/*Fraction* this, */int);

	Fraction operator += (const Fraction& right);

	friend ostream& operator << (ostream&, const Fraction&);
	friend class cat;
	friend class String;
	friend class Date;
	friend class Student;
};

/////////////////////////////////////////////////////////////////////////////////////
// ��������� ���������� �������, ������������� � .cpp-����� Fraction.h
Fraction operator + (const Fraction&, const Fraction&);
Fraction operator + (const Fraction&, int);
Fraction operator + (int, const Fraction&);

//bool operator < (const Fraction&, const Fraction&);

//Fraction operator - (const Fraction&);

ostream& operator << (ostream&, const Fraction&);

//////////////////////////////////////////////////////
// REALIZATIONS:

// ����� ����������� ��� ���������� � ��������������
Fraction::Fraction() : Fraction(0, 1)
{
	// ������ ������������� � ���� ������ ������ ��� ������ :)
}

// "�������" �����������
Fraction::Fraction(int chis, int znam)
{
	SetNumerator(chis);
	SetDenominator(znam);
}

// ��������� ����� � ���������� �������
double Fraction::GetDecimal() const
{
	return (double)numerator / denominator;
}

// ���������� ��� �������� �� ��������� ������
void Fraction::Print() const
{
	cout << numerator << "/" << denominator << "\n";
}

// ���������� � ��������� �� ��������� ������
void Fraction::PrintDecimal() const
{
	cout << GetDecimal() << "\n";
}

// ������ ���������
int Fraction::GetNumerator() const
{
	return numerator;
}

// ������ �����������
int Fraction::GetDenominator() const
{
	return denominator;
}

// ������ ��������� (��� ��������)
void Fraction::SetNumerator(int chis)
{
	numerator = chis;
}

// ������ ����������� (����������� �� ������ ���� ����� 0!)
void Fraction::SetDenominator(int znam)
{
	denominator = znam != 0 ? znam : 1;
}

// ��������� ���� ������ (����� ����� ���������� ���� � ������)
bool Fraction::LessThan(const Fraction& right) const
{
	return GetDecimal() < right.GetDecimal();
}

// ��������� ���� ������ (����� ����� ���������� ���� � ������)
bool Fraction::GreaterThan(const Fraction& right) const
{
	return GetDecimal() > right.GetDecimal();
}

// ��������� ���� ������ (����� ����� ���������� ���� � ������)
bool Fraction::IsEquals(const Fraction& right) const
{
	return GetDecimal() == right.GetDecimal();
}

// �������� ���������� ������� �������������� ���� � ����� �1
void F1(Fraction a)
{
	cout << "explicit c-tor test global function F1\n";
}

// �������� ���������� ������� �������������� ���� � ����� �2
Fraction F2()
{
	int a = 10;
	int b = 15;
	cout << "explicit c-tor test global function F2\n";
	return (Fraction)(a + b);
}

// �������� ���� ������ (����������� ������� ������)
Fraction Fraction::Sum(const Fraction& left, const Fraction& right)
{
	//return left + right;
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}

bool operator < (const Fraction& left, const Fraction& right)
{
	return left.GetDecimal() < right.GetDecimal();
}

Fraction operator - (const Fraction& fraction)
{
	Fraction temp;
	temp.SetNumerator(-fraction.GetNumerator());
	temp.SetDenominator(fraction.GetDenominator());
	return temp;
}

// ������ ���������� �������� + ���������� ��������
Fraction operator + (const Fraction& left, const Fraction& right)
{
	cout << "GLOBAL FUNCTION === FRACTION + FRACTION!\n";
	Fraction result;
	result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
	result.SetDenominator(left.GetDenominator() * right.GetDenominator());
	return result;
}

// ������ ���������� �������� + ������� ������
Fraction Fraction::operator + (/*Fraction* this, */ const Fraction& right)
{
	cout << "CLASS METHOD === FRACTION + FRACTION!\n";
	Fraction result;
	result.SetNumerator(this->GetNumerator() * right.GetDenominator() + right.GetNumerator() * this->GetDenominator());
	result.SetDenominator(this->GetDenominator() * right.GetDenominator());
	return result;
}

/////////////////////////////////////////////

Fraction operator + (const Fraction& left, int value)
{
	cout << "GLOBAL FUNCTION === FRACTION + INT!\n";
	Fraction result;
	result.SetNumerator(1);
	result.SetDenominator(1);
	return result;
}

Fraction Fraction::operator + (/*Fraction* this, */ int right)
{
	cout << "CLASS METHOD === FRACTION + INT!\n";
	Fraction result;
	result.SetNumerator(2);
	result.SetDenominator(1);
	return result;
}

Fraction operator + (int left, const Fraction& right)
{
	cout << "GLOBAL FUNCTION === INT + FRACTION!\n";
	Fraction result;
	result.SetNumerator(3);
	result.SetDenominator(1);
	return result;
}

Fraction Fraction::operator += (const Fraction& right)
{
	cout << "+=\n";
	numerator = numerator * right.denominator + right.numerator * denominator;
	denominator *= right.denominator;
	return *this;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << f.numerator << '/' << f.denominator;
	return os;
}

