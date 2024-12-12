#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <string>
using namespace std;

class Database {
public:
    Database();
    void begin_transaction();
    void put(const string& key, const int& value);
    int get(const string& key);
    void commit();
    void rollback();
    bool transactionActive;
private:
    map<string, int> data;
    map<string, int> tempData;
};

Database::Database() {
    transactionActive = false;
}

void Database::begin_transaction() {
    if(!transactionActive){
        transactionActive = true;
        tempData = data;
    }
    else{
        throw invalid_argument("transaction already in progress");
    }
}

void Database::put(const string& key, const int& value) {
    if(transactionActive){
        tempData[key] = value;
    }
    else{
        throw invalid_argument("transaction not in progress");
    }
}

int Database::get(const string& key){
    if(data.count(key) != 0){
        return data[key];
    }
    else{
        return -1;
    }
}

void Database::commit() {
    if(transactionActive){
        data = tempData;
        tempData.clear();
        transactionActive = false;
    }
    else{
        throw invalid_argument("transaction not in progress");
    }
}

void Database::rollback() {
    if(transactionActive){
        tempData.clear();
        transactionActive = false;
    }
    else{
        throw invalid_argument("transaction not in progress");
    }
}

int main() {
    Database db;

    cout << "A: " << db.get("A") << endl;

    try{
        db.put("A", 5);
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    db.begin_transaction();

    db.put("A", 5);

    cout << "A (during transaction): " << db.get("A") << endl;

    db.put("A", 6);

    db.commit();

    cout << "A (after commit): " << db.get("A") << endl;

    try{
        db.commit();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try{
        db.rollback();
    } 
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "B: " << db.get("B") << endl;

    db.begin_transaction();

    db.put("B", 10);

    db.rollback();

    cout << "B (after rollback): " << db.get("B") << endl;
}