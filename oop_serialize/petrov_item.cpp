#include "petrov_item.h"
#include "petrov_header.h"

using namespace std;

void item::input(istream& in) {
	cout << "\n������� �������� ������: ";
	in.ignore();
	getline(in, name);

	cout << "������� ��� ������ (� �����������): ";
	weight = check_input(0.0, 10000.0);

	cout << "������� ������ ������ (� �����������): ";
	width = check_input(0.0, 5000.0);

	cout << "������� ������ ������ (� �����������): ";
	height = check_input(0.0, 5000.0);

	cout << "������� ���� ������ (� ������): ";
	price = check_input(0, 1000000000);

	cout << "����� � �������? (1 - ��, 0 - ���): ";
	stock = check_input(0, 1);
}

void item::output(ostream& out) const {
	out << "\n��������: " << name << endl;
	out << "���: " << weight << " ��" << endl;
	out << "������: " << width << " ��" << endl;
	out << "������: " << height << " ��" << endl;
	out << "����: " << price << " ���" << endl;
	out << "� �������: " << (stock ? "��" : "���") << endl;
}