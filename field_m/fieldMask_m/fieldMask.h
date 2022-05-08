#ifndef FIELDMASKH
#define FIELDMASKH

#include <cmath>
#include "../field.h"


class fldMask
{
private:
    //mask is two dimension array of integer
    //value of cell:
    //              -1 - black empty cell
    //              -2 - white cell
    //               0 - black figure
    //               1 - white figure
    int** mask ;
    int size ;

    int dec_vect ( int sub , int res ) ;

    int check_step ( int* &srcCrd , int* &resCrd ) ;

    void free_mask () ;

    int generate_mask ( field &fldIn ) ;
    int get_color_figure ( int iIn , int jIn , field &fldIn ) ;

    int* calc_border_for_start ( bool colorIn , int &sizeOut ) ;

    bool check_out_of_range ( int iIn , int jIn ) ;
public:
    fldMask ( field &fldIn) ;
    ~fldMask () ;

    //get mask where value of cell it is count enemy figure
    //of radius = 1 cell ;
    int** get_smart_mask ( bool color ) ;
    int** get_smart_empt_mask ( bool color ) ;
    int** get_mask ( int &sizeOut ) ;
    int** get_mask_of_steps ( int* &crdIn ) ;
    int** get_mask_for_start ( bool colorIn ) ;

    int calc_enemy_fgs ( int iIn , int jIn , bool color ) ;

    void print_mask () ;
    void print_smart_mask ( bool color ) ;
    void print_smart_empt_mask ( bool color ) ;
    void print_mask_of_steps ( int* &crdIn ) ;
    void print_mask_start ( bool colorIn ) ;
} ;
#endif
