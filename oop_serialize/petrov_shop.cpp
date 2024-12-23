#include "petrov_shop.h"
#include "petrov_item.h"
#include "petrov_used_item.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

BOOST_CLASS_EXPORT_GUID(item, "item")
BOOST_CLASS_EXPORT_GUID(used_item, "used_item")

using namespace std;

void shop::display_menu() {
    cout << "\n_____����_____" << endl;
    cout << "\n1) �������� �����" << endl;
    cout << "2) �������� �/� �����" << endl;
    cout << "3) �������� ��� ������" << endl;
    cout << "4) ��������� � ����" << endl;
    cout << "5) ��������� �� �����" << endl;
    cout << "6) �������� ������ " << endl;
    cout << "0) �����" << endl;
    cout << "===============================" << endl;
    cout << "�������� ����� ����: ";
}

void shop::add_item() {
    shared_ptr<item> new_item = make_shared<item>();
    new_item->input(cin);
    items.push_back(new_item);
}

void shop::add_used_item() {
    shared_ptr<used_item> new_used_item = make_shared<used_item>();
    new_used_item->input(cin);
    items.push_back(new_used_item);
}

void shop::items_output() {
    if (items.empty()) {
        cout << "\n������ �����������" << endl;
    }
    else {
        for (const shared_ptr<item>& i : items) {
            i->output(cout << endl);
        }
    }
}

void shop::items_write() {
    if (items.empty()) {
        cout << "\n������ �����������" << endl;
        return;
    }

    string filename;
    cout << "������� ��� �����: ";
    cin.ignore();
    getline(cin, filename);

    ofstream fout(filename);
    if (!fout) {
        cerr << "���������� ������� ����" << endl;
        return;
    }

    boost::archive::text_oarchive oa(fout);
    oa << items;

    fout.close();
    cout << "������ ��������� � ����" << endl;
}

void shop::items_read() {
    string filename;
    cout << "������� ��� �����: ";
    cin.ignore();
    getline(cin, filename);

    ifstream fin(filename);
    if (!fin) {
        cerr << "���������� ������� ����" << endl;
        return;
    }

    try {
        boost::archive::text_iarchive ia(fin);
        ia >> items;
    }
    catch (const exception& e) {
        cerr << "������ ������ �� �����: " << e.what() << endl;
        fin.close();
        return;
    }

    fin.close();
    cout << "������ ������� ��������� �� �����." << endl;
}

void shop::items_clear() {
    if (items.empty()) {
        cout << "\n������ �����������" << endl;
    }
    else {
        items.clear();
        cout << "\n������ ������" << endl;
    }
}