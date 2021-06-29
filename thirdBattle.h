//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>
 void swapNode_data (SoldierNode* p1, SoldierNode* p2);
 void bubbleSort(SoldierNode* head, int size);
//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////
bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    if (array.arr == NULL) {
        array.arr = new Soldier[10];
        array.size = 0;
        array.capacity = 10;
    }
    bool a = false; 
    a = insertAt(array, soldier,0);
    return a;
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
     if (array.arr == NULL|| array.size == 0 ) return false;
    bool b = false;
    b = removeAt(array,0);
    return b;
}

Soldier top(Array& array){
    //TODO
    if (array.arr != NULL || array.size != 0) return array.arr[0];
    return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    SoldierNode* head = list.head;
    if (head == NULL) list.size = 0;    
        bool b = true;
        b = insertAt(list,soldier,list.size); // list.size sau khi them se tang len 1 
    return b;
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
        SoldierNode* head = list.head;
    if (head == NULL) return false;
        bool b = true;
        b = removeAt(list,0); 
    return b;
}

Soldier front(SLinkedList& list){
    //TODO
        SoldierNode* head = list.head;
        if (head == NULL) return Soldier(); //Return this if cannot get front
            return head->data; 
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    SLinkedList rev;
    SoldierNode* temp = list.head;   
  while (temp != NULL)
  {
      bool b = true;
        b= insertAt(rev,temp->data, 0);
    temp = temp->next;
  }
  temp = list.head;
  SoldierNode* temp1 = rev.head;
  while (temp != NULL)
  {
      temp->data = temp1->data;
      temp = temp->next;
      temp1 = temp1->next;
  }
  delete temp1;
  clear(rev);
}
//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////
SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    SoldierNode* head2 = list2.head;
    
    while (head2 != NULL )
    {
        bool b = false;
        b= insertAt(list1, head2->data, 0);
        head2 = head2->next;
    }
    clear(list2); delete head2; //xoa list 2 vi k can den nua 

bubbleSort (list1.head ,list1.size );

return list1; // bool_false la LinkedList final result . 
}

void swapNode_data (SoldierNode* p1, SoldierNode* p2)
{
     Soldier tmp = p2->data;
    p2->data = p1->data;
    p1->data = tmp;
    return;
}
  
/* Function to sort the list */
void bubbleSort(SoldierNode* head, int size)
{
     SoldierNode* i = head; 
     SoldierNode* j = head; 
    for (int loop = 0; loop < size; ++loop)
    {
       bool active = false;
        for (j = i; j->next != NULL; j = j->next)
        {
            if (j->data.HP > j->next->data.HP) // Uu tien 1. 
            {
                 swapNode_data(j,j->next);
                active = 1;
            } // end uu tien 1
            else if (j->data.HP == j->next->data.HP) // Neu bang , xet den uu tien 2
            {
                if ( j->data.isSpecial > j->next->data.isSpecial  ) // Uu tien 2
                {
                     swapNode_data(j,j->next);
                    active = 1;
                } // end uu tien 2 
                    else if (j->data.isSpecial == j->next->data.isSpecial) // Neu bang, xet den uu tien 3
                    {
                        if ( (int) j->data.ID[0] > (int)j->next->data.ID[0]  ) // Uu tien 3
                        {
                             swapNode_data(j,j->next);
                            active = 1;
                        } // end uu tien ba
                    }
            }
               
        }
         if (active == 0)  break;
    }
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
