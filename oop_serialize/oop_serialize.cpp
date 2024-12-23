﻿#include "petrov_header.h"
#include "petrov_shop.h"
#include <windows.h>

using namespace std;

int main() {
    shop s;

    for (;;) {

        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);

        s.display_menu();
        int menu_item = check_input(0, 6);

        switch (menu_item) {
        case 1: {
            s.add_item();
            break;
        }
        case 2: {
            s.add_used_item();
            break;
        }
        case 3: {
            s.items_output();
            break;
        }
        case 4: {
            s.items_write();
            break;
        }
        case 5: {
            s.items_read();
            break;
        }
        case 6: {
            s.items_clear();
            break;
        }
        case 0:
            // system("cat priv.txt | lolcat");

            exit(0);
        }
    }

    return 0;
}