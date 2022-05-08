#ifndef NNODET
#define NNODET

#include <iostream>
#include "minMaxCell_m/mMCell.h"

struct nNodeT
{
public :
    int num ;
    mMCell data ;

    nNodeT **childs ;
    nNodeT ( mMCell data , int num = 0 ) ;
    ~nNodeT () ;

    void add_child ( mMCell data , int num = 0 ) ; 

    void add_child_node ( nNodeT *&data ) ; 

    //rm - remove
    void rm_child ( int num ) ;

    //return number of child nodes
    int get_countCh () ;

    //
    //increase cell in array of nNodeT* (add cell is empty)
    static nNodeT** inc_arr_once ( nNodeT **&src , int &iM ) ;

    //decrease cell in array of nNodeT*
    static nNodeT** dec_arr_once ( nNodeT **&src , int &iM ) ;

    //increase cell in array of nNodeT* (add cell have data)
    static nNodeT** add_arr_once ( nNodeT **&src , nNodeT *&data , int &iM ) ;

    ////initialization of arrays
    //init - initialization

    static nNodeT** init_one_dimension ( int &iM ) ;
    static nNodeT*** init_two_dimension ( int iM , int jM ) ;

    //
    ////
    
private :

    //number of child of this node
    int countCh ;
} ;
#endif
