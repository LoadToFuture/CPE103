
#ifndef _BANK_FUNCTION_H
#define _BANK_FUNCTION_H
#include <iostream>
#include <fstream>           // use ifstream in readFromJson()
#include <nlohmann/json.hpp> // lirbary json file
using json = nlohmann::json;
using namespace std;

const std::string USER_JSON = "user.json";             // set file user json >> USERJASON
const std::string BLOCK_USER_JSON = "block_user.json"; // set file user block to json >> BLOCK_USER_JSON
const std::string BANK_LIST_JSON = "bankacc.json";
const std::string TRANSFER_LOG = "transaction.json";
class Bankfunction
{
private:
    string cls_username;
    string cls_password;

public:
    Bankfunction(/* args */);
    ~Bankfunction();

    void setParameter(const string get_username, const string get_password);
    void bankOption();
    json readFromJson(const string &filename);
    void saveToJson(const json &data, const string &filename);
    int checkLogin(string username, string password);
    void savaBlockUser();
    int CheckUserOnly(const string &username);
    bool CheckUserBlockList(const string &username);
    void listAllBankAccouts();
    void bankListOption();
    void deposit(string accountNumber);
    void withdraw(string accountNumber);
    void transfer(string accountNumber);
    void headerUser();
    void trainsfer_log(const json &data, const string &filename);
    
};

#endif //_BANK_FUNCTION_H