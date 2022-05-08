#include "nNodeT.h"

//
//CONSTRUCTOR
//
nNodeT::nNodeT ( mMCell data , int num )
{
    this -> num = num ;
    this -> data = data ;
    this -> countCh = 0 ;
    childs = new nNodeT*[countCh] ;
}

//
//DESTRUCTOR
//
nNodeT::~nNodeT ()
{
    this -> num = -1 ;
    for ( int i = 0 ; i < countCh ; i++ )
    {
        delete childs[i] ;
    }
    countCh = 0 ;
    delete [] childs ;
}

void nNodeT::add_child ( mMCell data , int num )
{
    nNodeT *child = new nNodeT ( data , num ) ;
    childs = add_arr_once ( childs , child , countCh ) ;
}

void nNodeT::add_child_node ( nNodeT *&data )
{
    nNodeT *child =  data;
    childs = add_arr_once ( childs , child , countCh ) ;
}

void nNodeT::rm_child ( int num )
{
    for ( int i = 0 ; i < countCh ; i++ )
    {
        if ( childs[i] -> num == num )
        {
            delete childs[i] ;
            childs[i] = NULL ;
            childs = dec_arr_once ( childs , countCh ) ;
        }
    }
}

int nNodeT::get_countCh ()
{
    return countCh ;
}

nNodeT** nNodeT::inc_arr_once ( nNodeT **& src , int &iM )
{
    nNodeT **result = nullptr ;
    if ( ( src != nullptr ) )
    {
        int nIM = iM + 1 ;
        result = init_one_dimension ( nIM ) ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            result[i] = src[i] ;
        }
        iM = nIM ;
        delete [] src ;
    }
    return result ;
}

nNodeT** nNodeT::dec_arr_once ( nNodeT **&src , int &iM )
{
    nNodeT **result = nullptr ;
    if ( ( src != nullptr ) )
    {
        int nIM = iM - 1 ;
        result = init_one_dimension ( nIM ) ;
        for ( int i = 0 , iS = 0 ; i < iM ; i++ )
        {
            if ( src[i] != NULL )
            {
                result[iS] = src[i] ;
                iS++ ;
            } ;
        }
        iM = nIM ;
        delete [] src ;
        src = NULL ;
    }
    return result ;
}

nNodeT** nNodeT::add_arr_once ( nNodeT **&src ,
        nNodeT *&data , int &iM )
{
    nNodeT **result = inc_arr_once ( src , iM ) ;
    if ( result != nullptr )
    {
        result[iM - 1] = data ;
    }
    return result ;
}

nNodeT** nNodeT::init_one_dimension ( int &iM )
{
    nNodeT **nw = new nNodeT*[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = nullptr ;
    }
    return nw ;
}

nNodeT*** nNodeT::init_two_dimension ( int iM , int jM )
{
    nNodeT ***nw = new nNodeT**[iM] ;
    for ( int i = 0 ; i < iM ; i++ )
    {
        nw[i] = init_one_dimension ( jM ) ;
    }
    return nw ;
}
