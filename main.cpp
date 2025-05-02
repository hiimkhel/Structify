#include <iostream>

using namespace std;
class Menu{ 
    private:
    void studentMenu(){
        cout << "User is student\n";

    }
    void instructorMenu(){
        cout << "User is instructor\n";
    }
    void checkRole(int choice){
        if(choice == 1){
            isStudent = true;
            studentMenu();
        }
        else if(choice == 2){
            isInstructor = true;
            instructorMenu();
        }
        else{
            cout<<"Invalid choice!\n";
            return;
        }
    }
    public:
    bool isStudent, isInstructor;

    void runLogin(){
        int choice;
        do{
            cout<<"   -Login System-     \n";
            cout<<"[1] Student\n";
            cout<<"[2] Instructor\n";
            cout<<"[3] Exit Program\n";
            cout<<"Enter choice:\n";
            cout << ">> ";
            cin >> choice;
            if(choice == 3){
                cout<<"We hope you learn something! Thank you for using Structify\n";
                break;
            }
            checkRole(choice);
            break;
        }while(choice != 3);

    }

};
int main(){
    Menu login;
    login.runLogin();
    return 0;
}