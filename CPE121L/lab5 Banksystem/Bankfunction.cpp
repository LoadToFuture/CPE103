#include "Bankfunction.h"

Bankfunction::Bankfunction()
{
    cls_username = "";
    cls_password = "";
}

Bankfunction::~Bankfunction()
{
}

void Bankfunction::setParameter(const string get_username, const string get_password)
{
    cls_username = get_username;
    cls_password = get_password;
}

void Bankfunction::bankOption()
{
    bankListOption();
}

json Bankfunction::readFromJson(const string &filename) // function read file json
{
    json data;
    ifstream file(filename); // input file system
    if (file.is_open())
    { // condition is check opened file json
        file >> data;
        file.close();
    }
    else
    {
        cout << "not connect "; // file open fail
    }
    return data;
    return json();
}

void Bankfunction::saveToJson(const json &data, const string &filename)
{
    std::ofstream file(filename);    // output file system
    file << setw(4) << data << endl; // set write to file json
    file.close();
}

int Bankfunction::checkLogin(string username, string password)
{
    json userData = readFromJson(USER_JSON);
    if (userData.find("users") != userData.end())
    {

        for (const auto &user : userData["users"])
        {
            if (user["username"] == username && user["password"] == password)
                return 1;
        }
    }
    return 0;
}

void Bankfunction::savaBlockUser()
{
    json userBlockList = readFromJson(BLOCK_USER_JSON);
    userBlockList[cls_username] = true;
    saveToJson(userBlockList, BLOCK_USER_JSON);
}

int Bankfunction::CheckUserOnly(const string &username)
{
    json userData = readFromJson(USER_JSON);
    if (userData.find("users") != userData.end())
    {
        for (const auto &userchk : userData["users"])
        {
            if (userchk["username"] == username)
                return 1;
        }
    }
    return 0;
}

bool Bankfunction::CheckUserBlockList(const string &username)
{
    json userChkBlockList = readFromJson(BLOCK_USER_JSON);

    return userChkBlockList.find(username) != userChkBlockList.end() && userChkBlockList[username] == true;
}

void Bankfunction::listAllBankAccouts()
{
    json banklistAccout = readFromJson(BANK_LIST_JSON);
    cout << "=== Bank Accout List === \n";
    if (banklistAccout.find("accounts") != banklistAccout.end())
    {
        for (const auto &account : banklistAccout["accounts"])
        {
            cout << "==================================================================================\n"
                 << "Account person : " << account["person"] << endl
                 << "Account bank_name : " << account["bank_name"] << endl
                 << "Account branch : " << account["branch"] << endl
                 << "Account account_number : " << account["account_number"] << endl
                 << "Account balance : " << account["balance"] << endl;
        }
    }
    bankOption();
}

void Bankfunction::bankListOption()
{
    headerUser();
    cout << "*** Command **** \n"
         << "C1 : To view all bank account information, type 'list -a' or 'List-a' \n"
         << "C2 : To show information for a specific bank account, type 'list -f [account_number] ex. list -f 123456789 \n"
         << "C3 : Deposit Ex.  deposit -acc 123456xxx \n"
         << "C4 : Withdraw Ex.  withdraw -acc 123456xxx \n"
         << "C5 : transter Ex.  transfer -acc 123456xxx \n"
         << "C6 : If you want get out Type Exit!! \n"
         << "Type command : ";
    while (1)
    {
        string command;
        getline(cin, command);
        
        //  cin.ignore();
        istringstream iss(command); // istringstream  iss class in <sstream>
        string commandType;         // iss is get in String Command get all , whitespace character (space, tab , newline , etc.)
        iss >> commandType;
        // save in commandType with command type get get all ,
        
        if (commandType == "list")
        {
            string argument;
            iss >> argument; // skip the first argument (i.e., "-a" or "-f")
            if (argument == "-a")
            {
                cout << "List all of bank account information \n";
                listAllBankAccouts();
            }
            else if (argument == "-f")
            {
                string accountNumber;
                iss >> accountNumber;
                // put data with jason to account_number
                json banklistAccount = readFromJson(BANK_LIST_JSON);
                if (banklistAccount.find("accounts") != banklistAccount.end())
                {
                    for (const auto &account : banklistAccount["accounts"])
                    {
                        if (account["account_number"] == accountNumber)
                        {
                            cout << "==========================================================================\n"
                                 << "Account person : " << account["person"] << endl
                                 << "Account bank_name : " << account["bank_name"] << endl
                                 << "Account branch : " << account["branch"] << endl
                                 << "Account account_number : " << account["account_number"] << endl
                                 << "Account balance : " << account["balance"] << endl
                                 << "-----------------------------------------------------------------------------------\n";
                            bankOption();
                        }
                    }
                }
            }
            cout << "----------------------------------------\n"
                 << "Show Can’t find this bank account \n";
            bankOption();
        }
   
        //! deposit
        if (commandType == "deposit")
        {
            string argument;
            iss >> argument;
            if (argument == "-acc")
            {
                string accountNumber;
                iss >> accountNumber;

                json banklistAccount = readFromJson(BANK_LIST_JSON);
                if (banklistAccount.find("accounts") != banklistAccount.end())
                {
                    for (json &account : banklistAccount["accounts"])
                    {
                        if (account["account_number"] == accountNumber)
                        {
                            deposit(accountNumber);
                        }
                    }
                    cout << "-------------------------------"
                         << "Can't find this bank account\n"
                         << "Please initiate a new deposit\n";
                    bankOption();
                }
            }
            cout << "Command  is INVALID !!  \n";
            bankOption();
            return;
        }
        //! withdraw
        if (commandType == "withdraw")
        {
            string argument;
            iss >> argument;
            if (argument == "-acc")
            {
                string accountNumber;
                iss >> accountNumber;

                json banklistAccount = readFromJson(BANK_LIST_JSON);
                if (banklistAccount.find("accounts") != banklistAccount.end())
                {
                    for (json &account : banklistAccount["accounts"])
                    {
                        if (account["account_number"] == accountNumber)
                        {
                            withdraw(accountNumber);
                        }
                    }
                    cout << "------------------------------------------\n"
                         << "Can't find this bank account\n"
                         << "Please initiate a new withdraw\n";
                    bankOption();
                }
            }
            cout << "Command  is INVALID !!  \n";
            bankOption();
            return;
        }
        //! transfer
        if (commandType == "transfer")
        {
            string argument;
            iss >> argument;
            if (argument == "-acc")
            {
                string accountNumber;
                iss >> accountNumber;

                json banklistAccount = readFromJson(BANK_LIST_JSON);
                if (banklistAccount.find("accounts") != banklistAccount.end())
                {
                    for (json &account : banklistAccount["accounts"])
                    {
                        if (account["account_number"] == accountNumber)
                        {
                            transfer(accountNumber);
                        }
                    }
                    cout << "------------------------------------------\n"
                         << "Can't find this bank account\n"
                         << "Please initiate a new transfer\n";
                    bankOption();
                }
            }
            cout << "Command  is INVALID !!  \n";
            bankOption();
        }
    }
}
void Bankfunction::deposit(string accountNumber)
{

    json banklistAccount = readFromJson(BANK_LIST_JSON);
    for (json &account : banklistAccount["accounts"])
    {
        if (account["account_number"] == accountNumber)
        {
            float amount_deposit; // deposit money
            char confirm_deposit; // command confirm
            cout << "=======================================================================\n"
                 << "Correct!! account number is : " << accountNumber << endl;
            for (const auto &account : banklistAccount["accounts"])
            {
                if (account["account_number"] == accountNumber)
                {
                    headerUser();
                    cout
                        // << "Account person : " << account["person"] << endl
                        //<< "Account bank_name : " << account["bank_name"] << endl
                        << "------------------ DEPOSIT ------------------\n"
                        << "Account branch : " << account["branch"] << endl
                        << "Account account_number : " << account["account_number"] << endl
                        << "Account balance : " << account["balance"] << endl
                        << "--------------------------------------------------------------------\n";
                }
            }
            cout << "Please Enter the amount to deposit: ";
            cin >> amount_deposit;

            cin.ignore();
            cout << "You entered a doposit amount of : " << amount_deposit << " THB. Confirm ? (y/n): ";
            cin >> confirm_deposit;
            if (confirm_deposit == 'Y' || confirm_deposit == 'y')
            {
                // deposit to bank
                float current_balance = account["balance"];
                current_balance += amount_deposit;
                account["balance"] = current_balance;

                // save balance to json file

                saveToJson(banklistAccount, BANK_LIST_JSON);
                cout << "=====================================================================\n"
                     << "Successful!! Deposit is : " << amount_deposit << " THB\n"
                     << "New Balance : " << current_balance << " THB\n"
                     << "======================================================================\n";
                bankOption();
            }
            else if (confirm_deposit == 'n' || confirm_deposit == 'N')
            {
                cout << "Cancelled !! deposit not made .\n";
                bankOption();
            }
            return;
        }
    }
}
void Bankfunction::withdraw(string accountNumber)
{

    json banklistAccount = readFromJson(BANK_LIST_JSON);

    for (json &account : banklistAccount["accounts"])
    {
        if (account["account_number"] == accountNumber)
        {
            float amout_withdraw;
            char confirm_withdraw;
            cout << "==================================================================\n"
                 << "Correct!! account number is : " << accountNumber << endl;
            for (const auto &account : banklistAccount["accounts"])
            {
                if (account["account_number"] == accountNumber)
                {
                    headerUser();
                    cout << "------------------ DEPOSIT ------------------ \n"
                         << "Account branch : " << account["branch"] << endl
                         << "Account account_number : " << account["account_number"] << endl
                         << "Account balance : " << account["balance"] << endl
                         << "--------------------------------------------------------------------\n";
                }
            }
            do
            {
                cout << "Please Enter the amount to Withdraw:   ";
                cin >> amout_withdraw;
                if (amout_withdraw > account["balance"])
                {
                    cout << "=================================================================\n"
                         << "Insufficient funds for the transaction:  : \n"
                         << "Your current balance:  " << account["balance"] << endl
                         << "Please initiate a new transaction with sufficient funds.    :   \n";
                }
            } while (amout_withdraw > account["balance"]);
            cin.ignore();
            cout << "You entered a withdraw amout of : " << amout_withdraw << "THB. Confirm ? (y/n) ";
            cin >> confirm_withdraw;
            if (confirm_withdraw == 'y' || confirm_withdraw == 'Y')
            {
                // withdraw to bank
                float current_balance = account["balance"]; // เอาข้อมูล จำนวณเงินมาใส่ตัวแปล
                current_balance -= amout_withdraw;          // ทำการหักจำนวณเงินใน File ด้วย
                account["balance"] = current_balance;       // เก็บยอดเงินหลังจากถูกถอนมาเก็บไว้ที่ตัวแปร เพื่อแสดงยอดเงินล่าสุด
                // บันทึกลงไฟล json เพื่อปรับปรุงข้อมูลใน Data
                saveToJson(banklistAccount, BANK_LIST_JSON);
                cout << "==================================================================\n"
                     << "Successful! Withdraw is: " << amout_withdraw << " THB\n"
                     << "New balance : " << current_balance << " THB\n ";
                bankListOption();
            }
            else if (confirm_withdraw == 'n' || confirm_withdraw == 'N')
            {
                cout << "Cancelled! Witdraw not made.\n";
                bankListOption();
            }
            return;
        }
    }
}

void Bankfunction::transfer(string accountNumber)
{
    string first_account_tranfer = accountNumber;
    json banklistAccount = readFromJson(BANK_LIST_JSON);

    for (json &account : banklistAccount["accounts"])
    {
        string last_account_tranfer;
        string first_person, first_bankname, first_branch, first_account_number;
        double first_balance;
        first_person = account["person"];
        first_bankname = account["bank_name"];
        first_branch = account["branch"];
        first_account_number = account["account_number"];
        first_balance = account["balance"];
        if (first_account_number == accountNumber)
        {
            cout << " \n-------------- The Correct Source account number is: " << accountNumber << endl
                 << "\n=========================== Display Source Account Bank this transfer =================================\n"
                 << "======  Your account information  ======\n"
                 << "Source  person : " << account["person"] << endl
                 << "Source  bank_name : " << account["bank_name"] << endl
                 << "Source  branch : " << account["branch"] << endl
                 << "Source  account_number : " << first_account_number << endl
                 << "Source  balance : " << first_balance << endl
                 << "=========================================================================================\n";

            do // เช็คว่า หมายเลขบัญชี ต้นทางและปลายทางซ้ำกันไหม
            {
                if (first_account_tranfer == last_account_tranfer)
                {
                    cout << "The account number must not be duplicated.\n";
                }
                cout << "Account Transfer :  ";
                cin >> last_account_tranfer;
                cin.ignore();
            } while (first_account_tranfer == last_account_tranfer);
            for (json &lastAccount : banklistAccount["accounts"]) // วนลูปเพื่อค้นหาทุกค่าในธนาคาร
            {
                string last_person, last_bankname, last_branch, last_account_number;
                double last_balance;
                last_person = lastAccount["person"];
                last_bankname = lastAccount["bank_name"];
                last_branch = lastAccount["branch"];
                last_account_number = lastAccount["account_number"];
                last_balance = lastAccount["balance"];

                if (lastAccount["account_number"] == last_account_tranfer)
                { // ดึงข้อมูลจากเลขบัญชีของบัญชีปลายทาง
                    char choiceTranfar1;
                    cout << "=========================== Display Destination Account =================================\n"
                         << "==========  Account  You need Transfer ============\n"
                         << "Destination person : " << last_person << endl
                         << "Destination bank_name : " << last_bankname << endl
                         << "Destination branch : " << last_branch << endl
                         << "Destination account_number : " << last_account_number << endl
                         << "Destination balance : " << last_balance << endl
                         << "=========================================================================================\n"
                         << "Not the same bank will be charge 10THB (y/n) : "; // คอนเฟิร์มว่า หมายเลขบัญชีตรงกับ ที่จะโอน
                    cin >> choiceTranfar1;
                    if (choiceTranfar1 == 'y' || choiceTranfar1 == 'Y')
                    { // ถ้าตกลงว่าใข่

                        double amountTranfer, head_accout, end_accout; // สร้างตัวแปลเพื่อเก็บ
                        double transfer_fee = 10.00;                   // ค่าธรรมเนียม โอนบัญชีต่างธนาคาร
                        head_accout = account["balance"];              // Amout balance headaccount
                        end_accout = lastAccount["balance"];           // Amout balance lastAccount
                        do
                        {
                            cout << "=================================================================\n"
                                 << "Please enter amount to tranfer :  ";
                            cin >> amountTranfer;
                            if ((amountTranfer + transfer_fee) > head_accout)
                            {
                                cout << "=================================================================\n"
                                     << "Insufficient funds for the transaction:  : \n"
                                     << "Your current balance:  " << head_accout << endl
                                     << "Please initiate a new transaction with sufficient funds.    :   \n";
                            }
                        } while ((amountTranfer + transfer_fee) > head_accout); // check headAccount amount balance not lowes to Transfer
                        // เมื่อผ่านการตรวจสอบยอดเงิน ที่น้อยกว่าจะโอน
                        //! Tranfer
                        // reduce headAccount balance - amountTranfer
                        account["balance"] = account["balance"].get<float>() - amountTranfer - transfer_fee;
                        // incread  lassAccount balance + amountTranfer
                        lastAccount["balance"] = lastAccount["balance"].get<float>() + amountTranfer;
                        // save update file bank
                        saveToJson(banklistAccount, BANK_LIST_JSON);
                        // show display Tranfer
                        float current_balance = lastAccount["balance"];
                        cout << "------------------ Transfer ------------------ \n"
                             << "---------------------------------------------------  Source account  -----\n"
                             << "From account :  " << first_account_tranfer << endl
                             << "From Person account : " << first_person << endl
                             << "Old Balance : " << first_balance << endl
                             << "From Amount : " << amountTranfer << endl
                             << "And Transection : " << transfer_fee << endl
                             << "--------------\n"
                             << "New Balance  " << account["balance"] << endl
                             << "---------------------------------------------------  Destination  -----\n"
                             << "Destination account : " << last_account_tranfer << endl
                             << "Destination Person account : " << last_person << endl
                             << "Give Amount : " << amountTranfer << endl
                             << "Old Balance : " << last_balance << endl
                             << "--------------\n"
                             << "New balance: " << current_balance << " THB\n"
                             << "Transfer Funds successful!\n";

                        // save to newfile Tranferlog
                        json transfer_log;
                        transfer_log["From_person"] = account["person"];
                        transfer_log["From_Tranfer"] = first_account_tranfer;
                        transfer_log["To_person"] = lastAccount["person"];
                        transfer_log["To_Tranfer"] = last_account_tranfer;
                        transfer_log["Amount"] = amountTranfer;
                        transfer_log["free"] = transfer_fee;
                        // save to file transfer_log
                        trainsfer_log(transfer_log, TRANSFER_LOG);

                        cout << "=================================================================\n"
                             << "Transfer successful!\n";
                        return;
                        break;
                    }
                    else if (choiceTranfar1 == 'n' || choiceTranfar1 == 'N')
                    {
                        cout << "Cancelled Tranfer \n";
                        bankListOption();
                    }
                }
            }
        }
    }
}

 

void Bankfunction::trainsfer_log(const json &data, const string &filename)
{
    ofstream file(filename, ios::app);
    file << setw(6) << data << endl;
    file.close();
}
void Bankfunction::headerUser()
{
    cout << "================================================================================ User : " << cls_username << endl;
}
