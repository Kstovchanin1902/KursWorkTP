#ifndef FIELDH
#define FIELDH

#include <cmath>
#include "../cell_m/cell.h"

const int minFieldSize = 6 ;
const int minCountFgOnDesk = 3 ;

class field
{
private:
    cell** cls ; //cells
    int size ;
    int countFgOnDesk ; // count figures on the desk

    void free_cells () ;
    int calc_count_w_cells () ;
    int calc_count_b_cells () ;
    int calc_count_cells_with_w_fg () ;
    int calc_count_cells_with_b_fg () ;
    int calc_count_cells_with_all_fg () ;


    void print_underline () ;
    void print_numberline () ;
    void print_void () ;
public:
    field () ;
    ~field () ;

    void get_mask () ;
    void get_smart_mask () ;

    bool generate_field () ;

    int get_size () ;
    bool set_size ( int sizeIn ) ;

    int get_count_fg_on_desk () ;
    bool set_count_fg_on_desk ( int countIn ) ;

    cell* get_all_white_cell () ;
    cell* get_all_black_cell () ;
    cell* get_cell_with_all_fg ( int &count ) ;
    cell* get_cell_with_white_fg ( int &count ) ;
    cell* get_cell_with_black_fg ( int &count ) ;
    cell* get_cell ( int iIn , int jIn ) ;
    cell* get_cell ( int* &crd ) ;

    void print_field () ;

    bool move_fg ( int* &srcCrd , int* &resCrd , bool colorIn ) ;
    bool set_fg ( int* &crdIn , bool colorIn ) ;
    bool kill_fg ( int* &crdIn , bool colorin ) ;
} ;
#endif
