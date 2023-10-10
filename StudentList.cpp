//
//  StudentList.cpp
//  Project1
//
//  Created by Michael Olubode on 10/2/23.
//

#include "StudentList.hpp"
#include <iostream>

using namespace std;

void StudentList::appendNode(int id, double GPA) {
    StudentNode* newNode;
    StudentNode* nodePtr;
    
    newNode = new StudentNode;
    newNode->studentId = id;
    newNode->GPA = GPA;
    newNode->next = nullptr;
    
    
    if(!head) {
        head = newNode;
    } 
    else {
        nodePtr = head;
        while(nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void StudentList::insertNode(int id, double GPA) {
    StudentNode* newNode;
    StudentNode* nodePtr;
    StudentNode* prevNode;
    
    newNode = new StudentNode;
    newNode->studentId = id;
    newNode->GPA = GPA;
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
    }
    else {
        nodePtr = head;
        prevNode = nullptr;
        
        while( nodePtr != nullptr && nodePtr->studentId < id) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(!prevNode) {
            head = newNode;
            newNode->next = nodePtr;
        }
        else {
            prevNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    
    
}

void StudentList::deleteNode(int id) {
    StudentNode* nodePtr;
    StudentNode* prevPtr = nullptr;
    
    if(!head) {
        cout << "\nNothing to delete!\n";
        return;
    }
    if(head->studentId == id) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else {
        nodePtr = head;
        while(nodePtr->studentId != id && nodePtr->next != nullptr) {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr) {
            prevPtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void StudentList::displayList() const {
    StudentNode* nodePtr;
    nodePtr = head;
    if(!head) {
        cout << "List is empty.\n";
    }
    while(nodePtr) {
        cout << "Student ID: " << nodePtr->studentId << " GPA: " << nodePtr->GPA << endl;
        nodePtr = nodePtr->next;
    }
}
void StudentList::clear() {
    StudentNode* current = head;
    while (current) {
        StudentNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

