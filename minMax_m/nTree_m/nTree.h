#ifndef NTREE
#define NTREE

#include <iostream>
#include <climits>
#include <cfloat>
#include "nNodeT_m/nNodeT.h"

class nTree
{
private :
    nNodeT *root ;

    //parametres for auto number cells
    int num ;

    ////methods return true if need node with this num is exist
    ////else false
    //

    bool choose_node ( nNodeT *&source , nNodeT **&pPtr ,
            int num ) ;
    bool choose_root_node ( nNodeT *&src , nNodeT **&pPtr ,
            int num ) ;
    
    //
    ////

    void print_node ( nNodeT *ptr ) ;
    void print_tree ( nNodeT *ptr , int width ) ;

    ////methods calc depth and count leaves for node
    //

    int depth_from_node ( nNodeT *ptr ) ;
    int count_leaves ( nNodeT *ptr ) ;
    
    //
    ////

    ////methods calc ratio depth/leaves
    //

    void max_dpth_lvs ( nNodeT *ptr , nNodeT *&res , double &maxRatio ) ;
    void min_dpth_lvs ( nNodeT *ptr , nNodeT *&res , double &minRatio ) ;
    
    //
    ////

    //return for link array of nodes with equal data
    void get_nodes_data_eq ( nNodeT *src , nNodeT **&res ,
            int &iM , mMCell data ) ;
public :
    nTree () ;
    nTree ( mMCell data ) ;
    ~nTree () ;

    //return number of root node
    int get_root_node_num ( int num ) ;

    bool add_node ( nNodeT* data , int pNum = 0 ) ;

    //rm - remove
    bool rm_node ( int num ) ;
    
    void print () ;
    void print_schem () ;
    void print_scheme_node ( nNodeT *ptr ) ;

    nNodeT** get_arr_nodes_root ( int &count ) ;

    //return array of equla nodes
    nNodeT** get_data_eq ( mMCell data , int &iM ) ;

    bool get_node ( nNodeT *&resNode , int num ) ;
} ;
#endif
