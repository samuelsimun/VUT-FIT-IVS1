//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     SAMUEL ŠIMÚN <xsimun04@stud.fit.vutbr.cz>
// $Date:       $2022-03-09
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author SAMUEL ŠIMUN
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"


PriorityQueue::PriorityQueue()
{
    // Creating empty Queue without any Element
    m_pHead = NULL;

}

PriorityQueue::~PriorityQueue() {

    // Checking if Queue isn't allready free
    if (GetHead() == NULL)
        return;

    // Getting head a shrinking Queue from the beginning 
    Element_t *current = GetHead();

    while (current->pNext != nullptr) {
        Element_t *next = current->pNext;
        delete current;
        current = next;
    }
    delete current;
}

void PriorityQueue::Insert(int value) {

    // If Queue is empty -> create first element
    if(GetHead() == NULL){
        Element_t *newelement = new Element_t;
        newelement->pNext = nullptr;
        newelement->value = value;
        m_pHead = newelement;
        return;
    }

    Element_t *current = GetHead();
    Element_t *previous = GetHead();

    // Comparing first and second element
    if (value > current->value) {
        Element_t *inserted = new Element_t;
        inserted->value = value;
        inserted->pNext = current;
        m_pHead = inserted;
        return;
    }
    else
        current = current->pNext;

    // Comparing Elements between second and penultimate
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

    // Comparing penultimate and last element
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
    // Checking if Queue isn't empty
    if (GetHead() == NULL)
        return false;


    Element_t *current = m_pHead;
    Element_t *previous = m_pHead;

    // Checking if element isnt the first one
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

    // Checking if element is between second and penultimate
    while(current->pNext != nullptr){
        if (value == current->value){
            previous->pNext = current->pNext;
            delete current;
            return true;
        }
        previous = current;
        current = current->pNext;
    }

    // Checking if element isnt last
    if (current->value == value){
        delete current;
        previous->pNext = nullptr;
        return true;
    }

    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value) {

    // Checking if Queue isnt empty
    if (GetHead() == NULL)
        return NULL;

    Element_t *current = GetHead();

    // Checking if element between first and penultimate
    while (current->pNext != nullptr) {
         if (current->value == value)
             return current;
         else
             current = current->pNext;
    }

    // Checking if element is last
    if (current->value == value) {
        return current;
    } else return NULL;

}
size_t PriorityQueue::Length()
{
    Element_t *current = GetHead();
    int counter = 0;

    // Checking if Queue is empty
    if (GetHead() == NULL){
        return 0;
    }

    // Checking if there is only one Element
    if (current->pNext == NULL)
        return 1;

    // Checking how many elements are between first and last one
    do{
        counter++;
        current = current->pNext;
    } while (current->pNext != nullptr);

 	return (counter+1);
}

PriorityQueue::Element_t *PriorityQueue::GetHead() {

    // Getting head from m_pHead
    // If it nullptr -> return NULL
    if (m_pHead != nullptr)
        return m_pHead;
    else
        return NULL;

}

/*** Konec souboru tdd_code.cpp ***/
