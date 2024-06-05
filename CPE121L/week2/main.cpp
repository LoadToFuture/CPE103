#include <iostream>
#include <vector>
using namespace std;
int main() {
 
    string command;
    cout << "Enter command: ";
    getline(cin, command); // รับค่า string จากผู้ใช้

    if (command == "list -a") {
        cout << "List all of bank account information" << endl;
    } else if (command.substr(0, 7) == "list -f") {
        string accountNumber = command.substr(8); // ดึงเลขบัญชีจากคำสั่ง
        if (accountNumber == "123456789") {
            cout << "Show information of bank account" << endl;
        } else {
            cout << "Can’t find this bank account" << endl;
        }
    } else {
        cout << "Invalid command" << endl;
    }

   
    return 0;
}
