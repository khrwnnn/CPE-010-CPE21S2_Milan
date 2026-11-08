#ifndef BORROWRETURNHISTORY_H
#define BORROWRETURNHISTORY_H

#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <limits>

// Settings
const int HISTORY_DEFAULT_CAPACITY = 50;
const int HISTORY_EMPTY = -1;
const int HISTORY_DATE_LENGTH = 32;
const std::string HISTORY_DATE_FORMAT = "%Y-%m-%d %I:%M %p";
const std::string HISTORY_BORROW = "Borrow";
const std::string HISTORY_RETURN = "Return";
const char HISTORY_YES = 'y';
enum HistoryMenu { HISTORY_VIEW_TOP = 1, HISTORY_VIEW_ALL, HISTORY_REMOVE_TOP, HISTORY_BACK };

// One borrowing or returning transaction
struct BorrowReturnRecord{
    int transactionID;
    std::string username, assetID, type, dateTime;
};

// Array-based stack of recent transactions (LIFO)
class BorrowReturnHistory{
    private:
        BorrowReturnRecord *records;
        int capacity;
        int topIndex;
        int lastTransactionID;

        std::string getCurrentDateTime(){
            time_t now = time(nullptr);
            char buffer[HISTORY_DATE_LENGTH];
            strftime(buffer, sizeof(buffer), HISTORY_DATE_FORMAT.c_str(), localtime(&now));
            std::string dateTime = buffer;
            size_t hourStart = dateTime.find(' ') + 1;
            if(dateTime[hourStart] == '0'){ dateTime.erase(hourStart, 1); }
            return dateTime;
        }

        void displayRecord(BorrowReturnRecord record){
            std::cout << "#" << record.transactionID << " | " << record.type << " | User: " << record.username
                      << " | Asset: " << record.assetID << " | " << record.dateTime << std::endl;
        }

    public:
    //constructor
    BorrowReturnHistory(int maxRecords = HISTORY_DEFAULT_CAPACITY){
        capacity = (maxRecords > 0) ? maxRecords : HISTORY_DEFAULT_CAPACITY;
        records = new BorrowReturnRecord[capacity];
        topIndex = HISTORY_EMPTY;
        lastTransactionID = 0;
    }

    //destructor
    ~BorrowReturnHistory(){
        delete[] records;
    }

    // Copying is blocked so two objects never delete the same array
    BorrowReturnHistory(const BorrowReturnHistory &) = delete;
    BorrowReturnHistory& operator=(const BorrowReturnHistory &) = delete;

    bool isEmpty(){ return topIndex == HISTORY_EMPTY; }
    bool isFull(){ return topIndex == capacity - 1; }
    int getCount(){ return topIndex + 1; }

    // Adds a transaction on top
    bool push(std::string username, std::string assetID, std::string type){
        if(isFull()){
            std::cout << "Transaction history is full." << std::endl;
            return false;
        }
        if(username.empty() || assetID.empty() || (type != HISTORY_BORROW && type != HISTORY_RETURN)){
            std::cout << "Invalid transaction. Fill in the username and asset ID, and use " << HISTORY_BORROW << " or " << HISTORY_RETURN << "." << std::endl;
            return false;
        }
        topIndex++;
        lastTransactionID++;
        records[topIndex] = {lastTransactionID, username, assetID, type, getCurrentDateTime()};
        return true;
    }

    // Removes the newest entry from the history only 
    bool pop(){
        if(isEmpty()){
            std::cout << "No transactions to remove." << std::endl;
            return false;
        }
        topIndex--;
        return true;
    }

    // Returns the newest transaction without removing it 
    BorrowReturnRecord top(){
        if(isEmpty()){ return BorrowReturnRecord(); }
        return records[topIndex];
    }

    // Asks for the details, then pushes the transaction
    void recordTransaction(std::string type){
        std::string username, assetID;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Asset ID: ";
        std::cin >> assetID;
        if(push(username, assetID, type)){
            std::cout << type << " recorded." << std::endl;
        }
    }

    bool recordBorrow(std::string username, std::string assetID){ return push(username, assetID, HISTORY_BORROW); }
    bool recordReturn(std::string username, std::string assetID){ return push(username, assetID, HISTORY_RETURN); }

    void displayTop(){
        if(isEmpty()){ std::cout << "No transactions recorded yet." << std::endl; return; }
        displayRecord(top());
    }

    // Shows newest to oldest
    void displayAll(){
        if(isEmpty()){ std::cout << "No transactions recorded yet." << std::endl; return; }
        std::cout << getCount() << "/" << capacity << " transactions (newest first):" << std::endl;
        for(int i = topIndex; i > HISTORY_EMPTY; i--){
            displayRecord(records[i]);
        }
    }

    // Asks before popping
    void confirmPop(){
        if(isEmpty()){ std::cout << "No transactions to remove." << std::endl; return; }
        displayTop();
        char answer;
        std::cout << "Remove this entry from the history? (y/n): ";
        std::cin >> answer;
        if(std::tolower(answer) == HISTORY_YES && pop()){
            std::cout << "Entry removed. The borrow/return itself is not cancelled." << std::endl;
        }else{
            std::cout << "Nothing was removed." << std::endl;
        }
    }

    // Admin submenu
    void showMenu(){
        int choice;
        do{
            std::cout << "======== Transaction History ========\n"
                      << HISTORY_VIEW_TOP << ". View Most Recent Transaction\n"
                      << HISTORY_VIEW_ALL << ". View All Recent Transactions\n"
                      << HISTORY_REMOVE_TOP << ". Remove Most Recent Transaction\n"
                      << HISTORY_BACK << ". Back\n"
                      << "Enter your choice: ";
            // Letters typed: cin sets choice to 0, then the bad input is cleared
            if(!(std::cin >> choice)){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if(choice != HISTORY_BACK){ std::cout << std::endl; }
            switch(choice){
                case HISTORY_VIEW_TOP: displayTop(); break;
                case HISTORY_VIEW_ALL: displayAll(); break;
                case HISTORY_REMOVE_TOP: confirmPop(); break;
                case HISTORY_BACK: break;
                default: std::cout << "Invalid Choice." << std::endl;
            }
            if(choice != HISTORY_BACK){ std::cout << std::endl; }
        }while(choice != HISTORY_BACK);
    }
};

// Shared transaction history used by the whole system
BorrowReturnHistory transactionHistory;

#endif