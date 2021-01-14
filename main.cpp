#include <iostream>
#include "set.h"
using namespace std;
int main()
{
    Set S1;
    create_empty_set(S1);
    int i;
    cout <<"inserisci intero"<<endl;
    cin >>i;
 insert_in_set(i,S1);
 print_set(S1);
 empty_set(S1);
 print_set(S1);
}
