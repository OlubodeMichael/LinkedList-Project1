//
//  StudentList.hpp
//  Project1
//
//  Created by Michael Olubode on 10/2/23.
//

#ifndef StudentList_hpp
#define StudentList_hpp

#include <stdio.h>
class StudentList {
private:
    struct StudentNode {
        int studentId;
        double GPA;
        StudentNode *next;
    };
    StudentNode *head;
    
public:
    //constructor
    StudentList() {
        head = nullptr;
    }
    // desconstructor
    ~StudentList() { };
    
    void appendNode(int, double);
    void insertNode(int, double);
    void deleteNode(int);
    void displayList() const;
    
};
#endif /* StudentList_hpp */
