#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include "Registration.h"

const int size = 100;
Registration *accounts = new Registration[size];
int acc_counter = 0;

// Clear Screen Function
void clearScreen() {
    std::cout << "\033[2J\033[3J\033[H" << std::flush;
}

void Register(){
    std::string user;
    std::string pass;
    bool valid;
    do{
        std::cout << "======== Registration =========" << std::endl;
        std::cout << "Username: ";
        std::cin >> user;
        valid = true;
        for(int i = 0; i<acc_counter;i++){
            if(user == accounts[i].getUsername()){
                clearScreen();
                std::cout << "Username is already taken." << std::endl;
                valid = false;
                break;
            }
        }
    }while(!valid);

    std::cout << "Password: ";
    std::cin >> pass;
    accounts[acc_counter] = Registration(user,pass);
    acc_counter++;
    clearScreen();
    std::cout << "Successfully Created Account!" << std::endl;

    return;
}

bool studentLogin(){
    if(acc_counter ==  0){
        std::cout << "No registered accounts yet." << std::endl;
        return false;
    }
    std::string user;
    std::string pass;
    Registration *curr_acc = nullptr;
    int attempts = 3;
    do{
        std::cout << "======== Student Login ========" << std::endl;
        std::cout << "Username: ";
        std::cin >> user;
        curr_acc = nullptr;
        for(int i = 0; i<acc_counter; i++){
            if(user == accounts[i].getUsername()){
                curr_acc = &accounts[i];
                break;
            }
        }

        if(curr_acc == nullptr){
            std::cout << "Invalid Username." << std::endl;
        }   
    }while(curr_acc == nullptr);
    while(attempts != 0){
        std::cout << "Password: ";
        std::cin >> pass;
        if(pass == curr_acc->getPassword()){
            return true;
        }else{
            std::cout << "Incorrect Password." << std::endl;
            attempts--;
            std::cout << "You have " << attempts << " attempts left." << std::endl;
        }
    }
    std::cout << "Access Denied." << std::endl;
    exit(0);
}

bool adminLogin(){
    std::string user;
    std::string pass;
    bool valid;
    int attempts = 3;
    do{
        std::cout << "======== Admin Login ========" << std::endl;
        std::cout << "Username: ";
        std::cin >> user;
        valid = false;
        if(user == "admin"){
            valid = true;
        }else{
            clearScreen();
            std::cout << " Invalid Username." << std::endl;
        }
    }while(!valid);
    while(attempts != 0){
        std::cout << "Password: ";
        std::cin >> pass;
        if(pass == "admin"){
            return true;;
        }else{
            attempts--;
            std::cout << "Incorrect Password." << std::endl;
            std::cout << "You have " << attempts << " attempts left." << std::endl;
        }
    }
    std::cout << "Access Denied." << std::endl;
    exit(0); 
}

void cleanupAccounts() {
    delete[] accounts;
    accounts = nullptr;
    acc_counter = 0;
}

#endif
