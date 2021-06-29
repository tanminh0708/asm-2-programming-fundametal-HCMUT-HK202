//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    //#----------TAO MOI TRUONG THEM NODE MOI #-------------------------

 
    // #-----------------------END-------------------------

        if (list.head == NULL && pos != 0) return false; // chua co LL ma pos != 0 
        if (pos > list.size || pos < 0 ) return false; // VI TRI THEM VAO LON HON SIZE
        if (pos == 0) // case pos  = 0 
        {
          SoldierNode* newbie = new SoldierNode();
            newbie->data = element;
            newbie->next = NULL;
        if (list.head == NULL ) list.size = 1; // chua co LL thi size = 1;    
        else ++list.size  ;  // co roi thi ++1;
        newbie->next = list.head;
        list.head = newbie; 
        //delete newbie;
        return true;
        }
        //#----------TAO MOI TRUONG THEM NODE MOI #-------------------------

    SoldierNode* head = list.head;
    SoldierNode* prev = list.head;
     SoldierNode* newbie = new SoldierNode();
    newbie->data = element;
    newbie->next = NULL;
    //---------------END----------------------
        int count = 0;
    while (head != NULL && pos != count)
    {
        prev = head;
        head = head->next;
         count = count + 1;;       
    }
prev->next = newbie;
newbie->next = head;
list.size += 1;
   return true;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO  
    SLinkedList now = list;
    SLinkedList prev = list;
        if (list.head == NULL) return false;
        if (idx >= list.size || idx < 0 ) return false; 
    if (idx == 0 ) 
    {   
        SoldierNode* temp = list.head;
        list.head = list.head->next;
        delete temp;
        --list.size; // thanh cong thi giam size di 1 
        return true;
    }
  
        int count = 0; 
    while(now.head != NULL)
    {
        prev.head = now.head;
        now.head = now.head->next;
        if (count != idx - 1) count = count + 1; 
        else {
             prev.head->next = now.head->next;
             --list.size; // thanh cong thi giam size di 1 
            delete now.head;
            return true;
        }
    }
    
   return false;
}
bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    SoldierNode* head = list.head;
    SoldierNode* prev;
    if (HP < 0) return false;
    if (list.head == NULL) return false;
    if (head->data.HP == HP) // HEAD = HP. 
    {
        bool flag = false; 
        flag = removeAt(list,0);
        return flag;
    } 
    while (head->next != NULL)
    {
        prev = head;
        head = head->next;
        if (head->data.HP == HP)
        {
        prev->next = head->next;
           --list.size;
        delete head;
        return true;
        }
    }
     if (list.size == 0) {
        delete head;
       // delete prev;
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
        if (list.head == NULL) return -1;
    int idx = 0;
   
    SoldierNode* head = list.head;
    while (head != NULL )
    {   
        if (head->data.ID == soldier.ID && head->data.isSpecial == soldier.isSpecial && head->data.HP == soldier.HP) return idx;
        else ++idx; 
        head = head->next;
    }
    return -1;
    
}

int size(SLinkedList& list){
    if (list.head != NULL ) return list.size;
    list.size = 0;
    return 0; 
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    if (list.head == NULL ) return true; 
    return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    SoldierNode* hientai = list.head;
    SoldierNode* tieptheo;
    if (hientai == nullptr) return;
    while (hientai != NULL)
    {
        tieptheo = hientai->next;
        delete hientai;
        hientai = tieptheo;
    } 
    
    list.size = 0; 
    list.head = NULL;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    SoldierNode* head = list.head;
        if (head == NULL) return "-1";
      
    int count = 0; 
    if (pos == 0) return head->data.ID;
    while (head != NULL )
    {
        if (count == pos) return head->data.ID;
        ++count; 
        head = head->next;
    }
    return "-1";
}
int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    SoldierNode* head = list.head;
    if (head == nullptr) return -1;  
     int count = 0; 
    if (pos == 0) return head->data.HP;
    while (head != NULL )
    {
        if (count == pos) return head->data.HP;
        ++count; 
        head = head->next;
    }
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    SoldierNode* head = list.head;
        if (head == NULL) return false;
        if (HP < 0 || pos < 0 ) return false; 
    int count = 0; 
    if (pos == 0) {
        head->data.HP = HP;
        return true;
    }
    while (head != NULL )
    {
        if (count == pos) 
        {
            head->data.HP = HP;
            return true;
        }
        ++count; 
        head = head->next;
    }
    return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    SoldierNode* head = list.head; 
    while (head != NULL)
    {   
        if (head->data.ID == soldier.ID && head->data.isSpecial == soldier.isSpecial && head->data.HP == soldier.HP) return true;
        head = head->next;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
