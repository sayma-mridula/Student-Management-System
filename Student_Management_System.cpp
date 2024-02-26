#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;

class info{
protected:
    string name,email,address;
    long long int roll,phoneNumber,age;
public:
    friend istream& operator>>(istream& in, info& info) {
        cout << "Enter your name: ";
        in >> info.name;
        cout << "Enter your roll number: ";
        in >> info.roll;
        cout << "Enter age: ";
        in >> info.age;
        cout << "Enter phone number: ";
        in >> info.phoneNumber;
        cout << "Enter address: ";
        in >> info.address;
        cout << "Enter email: ";
        in >> info.email;
        return in;
    }

    friend ostream& operator<<(ostream& out, const info& info) {
        out << "Name: " << info.name << endl;
        out << "Roll: " << info.roll << endl;
        out << "Age: " <<  info.age << endl;
        out << "Phone: " << info.phoneNumber << endl;
        out << "Address: " << info.address << endl;
        out << "Email: " << info.email << endl;
        return out;
    }
};

class Student : public info{
    public:
    void addNewStudent(){
        char ch;
        ofstream f1;
        f1.open("student.txt", ios::binary | ios::app);

        cin >> *this;
        f1.write(reinterpret_cast<char*>(this), sizeof(*this));

        cout << "New student has been successfully added..." << endl;
        f1.close();
    }

    void displayStudent() {
        ifstream f2;
        f2.open("student.txt", ios::binary);

        cout << "\n================================" << endl;
        cout << "LIST OF ALL STUDENTS" << endl;
        cout << "================================" << endl;

        while (!f2.eof()) {
            if (f2.read(reinterpret_cast<char*>(this), sizeof(*this))) {
                cout << *this;
                cout << "================================" << endl;
            }
        }
        f2.close();
    }

    void searchStudent() {
        ifstream f3;
        long long rollNumber;
        cout << "Enter roll no.: ";
        cin >> rollNumber;
        f3.open("student.txt", ios::binary);

        while (!f3.eof()) {
            if (f3.read(reinterpret_cast<char*>(this), sizeof(*this))) {
                if (rollNumber == roll) {
                    cout << *this;
                    return;
                }
            }
        }
        cout << "\nNo record found." << endl;
        f3.close();
    }

    void updateStudent(){
        long long num;
        fstream f4;

        cout << "Update Info of Student" << endl;
        cout << "===============================" << endl << endl;
        cout << "Enter the roll number to be edited: ";
        cin >> num;

        f4.open("student.txt", ios::binary | ios::out | ios::in);

        while (!f4.eof()) {
            if (f4.read(reinterpret_cast<char*>(this), sizeof(*this))) {
                if (roll == num) {
                    cout << "Enter new record" << endl;
                    cin >> *this;
                    int pos = -1 * sizeof(*this);
                    f4.seekp(pos, ios::cur);
                    f4.write(reinterpret_cast<char*>(this), sizeof(*this));
                    cout << "\nInfo Successfully Updated..." << endl;
                    return;
                }
            }
        }
        cout << "\nNo record found." << endl;
        f4.close();
    }

    void deleteStudent() {
        long long num;
        int flag = 0;
        ofstream f5;
        ifstream f6;

        f6.open("student.txt", ios::binary);
        f5.open("temp.txt", ios::binary);

        cout << "Enter roll number to delete Info: ";
        cin >> num;

        while (!f6.eof()) {
            if (f6.read(reinterpret_cast<char*>(this), sizeof(*this))) {
                if (roll != num) {
                    f5.write(reinterpret_cast<char*>(this), sizeof(*this));
                } else
                    flag = 1;
            }
        }
        f6.close();
        f5.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");

        flag == 1 ? cout << "\nInfo Deleted..." << endl :
                    cout << "\nInfo Not Found..." << endl;
    }

    void deleteAllStudent() {
        char confirm;
        cout << "Are you sure you want to delete all Info? (Y/N): ";
        cin >> confirm;

        if (confirm == 'Y' || confirm == 'y') {
            ofstream f7;
            f7.open("student.txt", ios::binary | ios::trunc);
            f7.close();
            cout << "All Info have been deleted successfully." << endl;
        } else {
            cout << "Deletion operation canceled." << endl;
        }
    }

    };


int main(){

    cout << "\n\n\n\n\n\n\n\n\t\t * Welcome to Student Management System *" << endl;

    while(1){
    Student s;
    int choice;

    cout << "\t\t-------------------------" << endl;
    cout << "\t\tStudent Management System" << endl;
    cout << "\t\tMAIN MENU" << endl;
    cout << "\t\t--------------------------" << endl;
    cout << "\t\t 1. Add New Student" << endl;
    cout << "\t\t 2. Display All Students " << endl;
    cout << "\t\t 3. Search Student" << endl;
    cout << "\t\t 4. Update Student" << endl;
    cout << "\t\t 5. Delete Student" << endl;
    cout << "\t\t 6. Delete All Students" << endl;
    cout << "\t\t 0. Exit" << endl;
    cout << "Enter Your Choice : " << endl;
    cin >> choice;

    switch(choice){
        case 1:
             s.addNewStudent();
             break;

        case 2:
             s.displayStudent();
             break;

        case 3:
             s.searchStudent();
             break;

        case 4:
             s.updateStudent();
             break;

        case 5:
             s.deleteStudent();
             break;

        case 6:
             s.deleteAllStudent();
             break;

        case 0:
             cout << "\n\n\n\t\t\tThank for using SMS." << endl << endl;
             exit(0);
             break;

        default:
             continue;
    }

    int opt;
    cout << "\n\n::Enter Your Choice :\n[1] Main Menu\t\t[0] Exit\n";
    cin >> opt;

    switch (opt) {
            case 0:

                cout << "\n\n\n\t\t\tThank you for using SMS." << endl << endl;
                exit(0);
                break;

            default:
                continue;
        }

}
   return 0;
}
