//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>
//Functions used to manage Array
void ensureCapacity(Array& array, int newCap);
void print(Array& array){
 if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " "; // << endl;
    }
    std::cout <<"]" << endl;
}//
void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    if (cap < 0) return;
    if (cap == 0) cap = 1;
    array.arr = new Soldier[cap];
    array.capacity = cap;
    array.size = 0;
}//

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO

        if (pos > array.size || pos < 0) return false;
        if (array.arr == NULL || array.capacity == 0) return false; // case mang chua duoc init/ xoa roi ma chua init 
        if (array.size == 0 && pos != 0) return false;
        if (array.size == array.capacity) 
            {
        if (array.capacity % 2 != 0) ++array.capacity;    
        array.capacity *= 1.5;
        ensureCapacity(array,array.capacity);
            }
   
     if (array.arr[pos].ID == "\0" )
    {
        array.arr[pos] = element;
        ++array.size;
        return true;
    }
   
        Soldier hold = element;
        Soldier temp;
        for (int i = pos; i < array.size + 1; ++i)
        {
            temp = array.arr[i];
            array.arr[i] = hold;
            hold = temp;
        }
    ++array.size;
     return true;   
}//
bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
     if (array.arr == nullptr|| array.size == 0)  return false; // chua init , xoa roi ma chua init lai , moi init . 
    if (idx >= array.size || idx < 0) return false; 
    for (int i = idx; i < array.size; i++)
    {
        array.arr[i] = array.arr[i+1];
    }
    --array.size;
       if (array.size == 0){
            delete[] array.arr;
            array.arr = NULL; // dua con tro ve NULL 
            initArray(array,array.capacity);
        }
    // if (array.size == 0) delete[] array.arr;
    return true;
}//

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    if (array.arr == nullptr|| array.size == 0) return false;
    for (int i = 0; i < array.size; ++i )
    {
        if (array.arr[i].HP == HP ){
            bool a = false; 
            a = removeAt(array,i);
            return a; 
        }
    }
    return false;
}//

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    Array a;
     a.arr = new Soldier[newCap];
    for (int i = 0 ; i < array.size ; i++ ) {
      a.arr[i] = array.arr[i];
    }
    delete[] array.arr;
     
     array.arr = new Soldier[newCap];
   for (int i = 0 ; i < array.size ; i++ ) {
      array.arr[i] = a.arr[i];
    }
 delete[] a.arr;
}//

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if (array.arr == nullptr|| array.size == 0)   return -1;
   for (int i = 0; i < array.size; ++i){ 
       if (array.arr[i].isSpecial == soldier.isSpecial && array.arr[i].HP == soldier.HP && (int)array.arr[i].ID[0] == (int)soldier.ID[0] )
        {
            return i;
        }
   }
    return -1;
}//

int size(Array& array){
    //Return size of the array
    //TODO
    if (array.arr == NULL || array.size == 0) return 0;
    return array.size; 
}//

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if (array.capacity == 0 ) return true;
    if (array.size != 0) return false;
    return true;
}//

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
   if (array.arr == nullptr|| array.size == 0)   return "-1";
    if (pos >= array.size || pos < 0) return "-1";
    return array.arr[pos].ID;
   
}//

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
     if (array.arr == nullptr|| array.size == 0)  return -1;
    if (pos >= array.size || pos < 0) return -1;
    return array.arr[pos].HP;
   
}//

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
     if (array.arr == nullptr|| array.size == 0)  return false;
     if (pos >= array.size || pos < 0) return false;
        array.arr[pos].HP = HP;
        return true;
}//

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    delete[] array.arr;
    array.size = 0; 
    array.arr = NULL;
}//

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
     if (array.arr == nullptr|| array.size == 0)  return false;
for (int i = 0; i < array.size; ++i){
    if (array.arr[i].isSpecial == soldier.isSpecial && array.arr[i].HP == soldier.HP && (int)array.arr[i].ID[0] == (int)soldier.ID[0] )
    {
        return true;
    }
   
}  
 return false;

}//
//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
