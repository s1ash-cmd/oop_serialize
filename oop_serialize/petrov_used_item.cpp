#include "petrov_used_item.h"
#include "petrov_header.h"

using namespace std;

void used_item::input(istream& in) {
	item::input(in);

	cout << "������� ������� ������ (� �����): ";
	age = check_input(0, 10000);

	cout << "������� ��������� ������ (0.0 - 10.0): ";
	condition = check_input(0.0, 10.0);

	cout << "������� �������� ������: ";
	in.ignore();
	getline(in, description);
}

void used_item::output(ostream& out) const {
	item::output(out);
	out << "�������: " << age << " ���(�)/���" << endl;
	out << "���������: " << condition << " �� 10" << endl;
	out << "��������: " << description << endl;
}