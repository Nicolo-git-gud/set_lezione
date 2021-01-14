#include <iostream>
#include "set.h"

struct cell{
    Base_Type head;
    cell *next;
};
void create_empty_set(Set & s){
    s=nullptr;
}

//implementazione basata su inserimento ordinato per rendere più efficiente l'operazione, non sarebbe necessario ordinare gli elementi negli insiemi


void insert_in_set(Base_Type x, Set & s){
    
    cell *aux = new cell;
    aux->head = x;
    
    Set cur=s;
    Set prev=s;
    while((cur!=nullptr) && (cur->head<x)){
        prev=cur;
        cur=cur->next;
    }
    if((cur!=nullptr) && (cur->head==x))
        return;
    aux->next=cur;
    if(cur==s)
        s=aux;
    else prev->next=aux;
    
}
void empty_set(Set&s){
    Set temp=s;
    while(s!=nullptr){
        s= s->next;
        delete temp;
        temp=s;
        
    }
}
bool is_in_set(Base_Type x, const Set &s){
    Set temp=s;
    while(temp!=nullptr){
        if (temp->head==x) return true;
        temp=temp->next;
    }
    return false;
}
void print_set(const Set &s){
    Set sCopy=s;
    std::cout<<"Set: ";
    while(sCopy!=nullptr){
        std::cout<<sCopy->head<<" // ";
        sCopy=sCopy->next;
    }
    std::cout<<std::endl;
}
Set union_set(const Set&s1, const Set&s2){
    Set s_union;
    create_empty_set(s_union);
    Set temp=s1;
    while(temp!=nullptr){
        insert_in_set(temp->head,s_union);
        temp=temp->next;
    }
    temp=s2;
    while(temp!=nullptr){
        insert_in_set(temp->head,s_union);
        temp=temp->next;
    }
    return s_union;
}

Set inters_set (const Set&s1, const Set&s2){
    Set s_int;
    create_empty_set(s_int);
    Set temp=s1;
    while(temp!=nullptr){
        if(is_in_set(temp->head,s2))
            insert_in_set(temp->head,s_int);
        temp=temp->next;
    }
    
    
    
    return s_int;
    
}
