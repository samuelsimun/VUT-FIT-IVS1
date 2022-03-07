//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2021-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find/GetHead ...
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "singly linked list", ktera bude splnovat dodane testy
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    m_pHead = NULL;
    /*
    Element_t *newelement = new Element_t;
    newelement->pNext = nullptr;
    newelement->value = -1;
    m_pHead = newelement; */

}

PriorityQueue::~PriorityQueue() {

    if (GetHead() == NULL)
        return;

    Element_t *current = GetHead();

    while (current->pNext != nullptr) {
        Element_t *next = current->pNext;


        delete current;

        current = next;
    }
    delete current;
}

void PriorityQueue::Insert(int value) {

    if(GetHead() == NULL){
        Element_t *newelement = new Element_t;
        newelement->pNext = nullptr;
        newelement->value = value;
        m_pHead = newelement;
        return;
    }

    Element_t *current = GetHead();
    Element_t *previous = GetHead();

    if (value > current->value) {
        Element_t *inserted = new Element_t;
        inserted->value = value;
        inserted->pNext = current;
        m_pHead = inserted;
        return;
    }
    else
        current = current->pNext;

    while (current->pNext != nullptr){
        if (value > current->value){
            Element_t *inserted = new Element_t;
            inserted->value = value;
            inserted->pNext = current;
            previous->pNext = inserted;
            return;
        }
        else{
            previous = current;
            current = current->pNext;
        }
    }

    if (value > current->value){
        Element_t *inserted = new Element_t;
        inserted->value = value;
        inserted->pNext = current;
        previous->pNext = inserted;
        return;
    }
    else {
        Element_t *inserted = new Element_t;
        inserted->value = value;
        inserted->pNext = nullptr;
        current->pNext = inserted;
        return;
    }

}
bool PriorityQueue::Remove(int value)
{
    if (GetHead() == NULL)
        return false;


    Element_t *current = m_pHead;
    Element_t *previous = m_pHead;

    if (current->value == value){
        m_pHead = current->pNext;
        delete current;
        return true;
    }
    else{
        if(current->pNext != nullptr){
            current = current->pNext;
        }
        else{
            return false;
        }
    }


    while(current->pNext != nullptr){
        if (value == current->value){
            previous->pNext = current->pNext;
            delete current;
            return true;
        }
        previous = current;
        current = current->pNext;
    }

    if (current->value == value){
        delete current;
        previous->pNext = nullptr;
        return true;
    }

    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value) {


    if (GetHead() == NULL)
        return NULL;

    Element_t *current = GetHead();

    while (current->pNext != nullptr) {
         if (current->value == value)
             return current;
         else
             current = current->pNext;
    }

    if (current->value == value) {
        return current;
    } else return NULL;

}
size_t PriorityQueue::Length()
{
    Element_t *current = GetHead();
    int counter = 0;

    if (GetHead() == NULL){
        return 0;
    }

    if (current->pNext == NULL)
        return 0;

    do{
        counter++;
        current = current->pNext;
    } while (current->pNext != nullptr);

 	return (counter+1);
}

PriorityQueue::Element_t *PriorityQueue::GetHead() {

    if (m_pHead != nullptr)
        return m_pHead;
    else
        return NULL;

}

/*** Konec souboru tdd_code.cpp ***/
