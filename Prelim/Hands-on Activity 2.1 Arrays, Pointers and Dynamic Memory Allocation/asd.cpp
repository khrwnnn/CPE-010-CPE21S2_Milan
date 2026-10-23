#include <iostream>
#include <string>

class Student{
    private:
        std::string studentName;
        int studentAge;

    public:
        //constructor
        Student(std::string newName = "John Doe", int newAge = 18) {
            studentName = std::move (newName);
            studentAge = newAge;
            std::cout << "Constructor Called." << std::endl;
        }

        //deconstructor
        ~Student(){
            std::cout << "Destructor Called." << std::endl;
        }

        //Copy Constructor
        Student(const Student &copyStudent) {
            std::cout << "Copy Constructor Called" << std::endl;
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }

        //Copy Assignment Operator
        Student& operator = (const Student& other){
            std::cout << "Copy Assignment Operator Called" << std::endl;

            //Prevent self-assignment 
            if (this != &other) {
                studentName = other.studentName;
                studentAge = other.studentAge;
            }

            return *this;
        }

        //Display Attributes
        void printDetails(){
            std::cout << this->studentName << "" << this->studentAge << std::endl;
        }
};

int main() {
    const size_t j = 5;

    Student studentList[j] = {};
    std::string nameList[j] = {"Carly", "Freddy", "Sam" "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for(int i = 0; i < j; i++) { //loop A
        Student *ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr;
    }
    
    for(int i = 0; i < j; i++){ //loop B
        studentList[i].printDetails();
    }

    return 0;
}