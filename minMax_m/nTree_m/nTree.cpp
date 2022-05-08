#include "nTree.h"

bool nTree::choose_node ( nNodeT *&source , nNodeT **&pPtr ,
        int num )
{
    bool flag = true ;
    if ( source != NULL )
    {
        if ( source -> num == num )
        {
            pPtr = &source ;
            flag = false ;
        }
        else
        {
            int iM = source -> get_countCh () ;
            for ( int i = 0 ; i < iM ; i++ )
            {
                flag = choose_node ( source -> childs[i] ,
                        pPtr , num ) ;
                if ( !flag )
                {
                    break ;
                }
            }
        }
    }
    return flag ;
}

bool nTree::choose_root_node ( nNodeT *&source ,
        nNodeT **&pPtr , int num )
{
    bool flag = true ;
    if ( ( source != NULL ) )
    {
        if ( source -> num == num )
        {
            flag = false ;
        }
        else
        {
            int iM = source -> get_countCh () ;
            for ( int i = 0 ; i < iM ; i++ )
            {
                flag = choose_node ( source -> childs[i] ,
                        pPtr , num ) ;
                pPtr = &source ;
                if ( !flag )
                {
                    break ;
                }
            }
        }
    }
    return flag ;
}

void nTree::print_node ( nNodeT *ptr ) 
{
    if ( ptr != NULL )
    {
        std::cout << "num = " << ptr -> num << " " ;
        std::cout << "data = " << ptr -> data .get_rating () << std::endl ;
        int iM = ptr -> get_countCh () ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            if ( ptr -> childs[i] != NULL )
            {
                print_node ( ptr -> childs[i] ) ;
            }
        }
    }
}

void nTree::print_tree ( nNodeT *ptr , int width ) 
{
    if ( ptr != NULL )
    {
        int iM = ptr->get_countCh () ;
        std::cout << ptr -> num << " " ;
        std::cout << "( " << ptr -> data .get_rating () << " )" << std::endl ;
        for ( int i = 0 ; i < iM ; i++ )
        {
            for ( int j = 0 ; j < width ; j++ )
            {
                std::cout << "|   " ;
            }
            std::cout << "|==>" ;
            print_tree ( ptr -> childs[i] , width + 1 ) ;
        }
    }
}

void nTree::get_nodes_data_eq ( nNodeT *src , nNodeT **&res ,
        int &iM , mMCell data )
{
    if ( src != NULL )
    {
        int countCh = src -> get_countCh () ;
        if ( src -> data.get_rating () == data.get_rating () )
        {
            res = nNodeT::add_arr_once ( res , src , iM ) ;
        }
        for ( int i = 0 ; i < countCh ; i++ )
        {
            get_nodes_data_eq ( src -> childs[i] , res , iM , data ) ;
        }
    }
}

//
//CONSTRUCTOR
//
nTree::nTree () 
{
    num = 0 ;
    root = NULL ;
}
//
nTree::nTree ( mMCell data ) 
{
    num = 0 ;
    root = new nNodeT ( data , num ) ;
    num++ ;
}

//
//DESTRUCTOR
//
nTree::~nTree () 
{
    delete root ;
}

int nTree::get_root_node_num ( int num )
{
    nNodeT **pPtr = NULL ;
    if ( choose_root_node ( root , pPtr , num ) )
    {
        return ( **pPtr ).num ;
    }
    return -1 ;
}

bool nTree::add_node ( nNodeT* data , int pNum ) 
{
    nNodeT **pPtr = NULL ;
    if ( root == NULL )
    {
        num = 0 ;
        root = data ;
        num++ ;
        return true ;
    }
    if ( !choose_node ( root , pPtr , pNum ) )
    {
        ( **pPtr ).add_child_node ( data ) ;
        num++ ;
        return true ;
    }
    return false ;
}

bool nTree::rm_node ( int num ) 
{
    nNodeT **pPtr = NULL ;
    if ( num == 0 )
    {
        delete root ;
        root = NULL ;
        return true ;
    }
    if ( !choose_root_node ( root , pPtr , num ) )
    {
        if ( pPtr != NULL )
        {
            ( **pPtr ).rm_child ( num ) ;
            return true ;
        }
    }
    return false ;
}

void nTree::print () 
{
    print_node ( root ) ;
}

void nTree::print_schem () 
{
    std::cout << std::endl ;
    std::cout << "=============" << std::endl;
    std::cout << std::endl ;
    print_tree ( root , 0 ) ;
    std::cout << std::endl ;
    std::cout << "=============" << std::endl;
    std::cout << std::endl ;
}

void nTree::print_scheme_node ( nNodeT *ptr ) 
{
    std::cout << std::endl ;
    std::cout << "=============" << std::endl;
    std::cout << std::endl ;
    print_tree ( ptr , 0 ) ;
    std::cout << std::endl ;
    std::cout << "=============" << std::endl;
    std::cout << std::endl ;
}

nNodeT** nTree::get_arr_nodes_root ( int &count )
{
    count = root->get_countCh () ;
    return root->childs ;
}

nNodeT** nTree::get_data_eq ( mMCell data , int &iM )
{
    iM = 0 ;
    nNodeT **res = new nNodeT*[iM] ;
    get_nodes_data_eq ( root , res , iM , data ) ;
    return res ; 
}

bool nTree::get_node ( nNodeT *&resNode , int num )
{
    nNodeT **pPtr = NULL ;
    if ( !choose_node ( root , pPtr , num ) )
    {
        resNode = *pPtr ;
        return true ;
    }
    resNode = NULL ; 
    return false ;
}
