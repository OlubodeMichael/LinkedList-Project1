//
//  main.cpp
//  Project1
//
//  Created by Michael Olubode on 10/2/23.
//

#include <iostream>
#include "StudentList.hpp"
using namespace std;

int main() {
    StudentList list;
    int size = 10;
    int id = 13902;
    double gpa;
    int option;
    int studentID;
    double studentGPA;

    
    for (int i = 0; i < size; i++) {
        // validate the user input so they don't enter a negative value;
        do {
            cout << "Enter the GPA for student #" <<i + 1<< " with ID: "<< id << endl;
            cin >> gpa;
        } while (gpa < 0.0 || gpa > 5.0);
        list.appendNode(id, gpa);
        id += 100;
    }
    list.displayList();
     
    // MENU OPTION
    do {
            cout << "\n*************MENU************ \n";
            cout << "1. Add Student.\n";
            cout << "2. Insert Student.\n";
            cout << "3. Delete Student.\n";
            cout << "4. Display List.\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: \n";
            cin >> option;
            
            if (option == 1) {
                cout << "\nEnter student ID:  \n";
                cin >> studentID;
                cout << "Enter student GPA: \n";
                cin >> studentGPA;
                list.appendNode(studentID, studentGPA);
                cout << "Student successfully added.\n";
                
            }
            else if (option == 2) {
                cout << "\nEnter student ID:  \n";
                cin >> studentID;
                cout << "Enter student GPA: \n";
                cin >> studentGPA;
                list.insertNode(studentID, studentGPA);
                cout << "Student successfully inserted.\n";
                
            }
            else if (option == 3) {
                cout << "\nEnter student ID:  \n";
                cin >> studentID;
                list.deleteNode(studentID);
                cout << "Student successfully deleted.\n";
                
            }
            else if (option == 4) {
                list.displayList();
    
            }
            else if (option == 5) {
                exit(0);
            }
        } while (option != 5);
        
    return 0;
}
