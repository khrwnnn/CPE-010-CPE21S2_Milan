#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>

class Registration{
    private:
        std::string username;
        std::string password;
    public:
    //constructor
    Registration(std::string name = "user", std::string pass = "pass"){
        username = name;
        password = pass;
    };

    //destructor
    ~Registration(){
    }

    //Copy Constructor
    Registration(const Registration &copyRegistration){
        username = copyRegistration.username;
        password = copyRegistration.password;    
    };

    //Copy Assignment Operator
    Registration& operator=(const Registration& copyRegistration){
        if(this != &copyRegistration){
            username = copyRegistration.username;
            password = copyRegistration.password;  

        }
        return *this;
    };

    std::string getUsername(){
        return username;
    }

    std::string getPassword(){
        return password;
    }
};
#endif