#pragma once

class MultipleInheritanceDemo
{
	
	class Horns // ����
	{
	protected:
		string color_;
		double weight_;

	public:
		Horns()
		{
			color_ = "brown";
			weight_ = 20;
		}
		Horns(string color, double weight)
		{
			color_ = color;
			weight_ = weight;
		}
	};

	class Hooves // ������
	{
	protected:
		string shape_;
		int size_;

	public:
		Hooves()
		{
			shape_ = "()"; // [] <> {}
			size_ = 45;
		}
		Hooves(string shape, int size)
		{
			shape_ = shape;
			size_ = size;
		}
	};

	class Elk : public Horns, public Hooves // ����
	{
		string nick_;
		
	public:
		Elk(string nick)
		{
			nick_ = nick;
		}

		void Print() const
		{
			cout << "Nick: " << nick_ << "\n";
			cout << "Horns color: " << color_ << "\n";
			cout << "Horns weight: " << weight_ << "\n";
			cout << "Hooves shape: " << shape_ << "\n";
			cout << "Hooves size: " << size_ << "\n";
		}
	};
	
public:
	static void Test()
	{
		Elk elk("Dave");
		elk.Print();

		// ��������:
		// �) ���������� �� ������� �������������
		// �) �������� ���������� ������������� � ����
		// �) ������� �� ������������ ������ ����������� ������������ ������� �������
	}
};

// MultipleInheritanceDemo::Test();