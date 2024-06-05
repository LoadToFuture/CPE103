#include "Bankfunction.h"

using namespace std;
using json = nlohmann::json; //! sudo apt-get -y install nlohmann-json3-dev = install ubuntu 

const int maxLogin = 4;
int minLogin = 0;

int main()
{
    Bankfunction b1;
    string username, password;
    cout << "===== Welcome Banking Information ==== \n";
    cout << "Enter username : ";
    cin >> username;
    b1.setParameter(username, password); // เผื่อได้ใช้

    while (minLogin < maxLogin)
    {
        if (b1.CheckUserOnly(username) == 0)
        {
            cout << "You don't have or Username is invalid\n";
            return 0;
        }
        else if (b1.CheckUserBlockList(username))
        {
            cout << "This username is blocked: " << username << endl;
            break;
        }
        cout << "Enter password : ";
        cin >> password;
        int ChkLogin = b1.checkLogin(username, password);
        if (ChkLogin == 1) // check login
        {
            cout << "Login is correct !! \n";
            b1.bankListOption();
            return 0;
        }
        else
        {
            cout << "====================================================\n"
                 << "User :  " << username << "  \n"
                 << "Password not correctt " << minLogin + 1 << " / 4  \n";
            minLogin++;
        }
        if (minLogin == maxLogin)
        {
            cout << "User : ** " << username << "** : Is Bloacked this Username \n";
            b1.savaBlockUser(); //! save block user
        }
    }
    return 0;
}