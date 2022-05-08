#ifndef CELLH
#define CELLH

#include <iostream>
#include <string>
#include "../figure_m/figure.h"

class cell
{
private:
    int* crd ; //coordinates crd[0] - x , crd[1] - y
    bool color ; //white - 1(+) , black - 0(-)
    figure* fg ; //point to sample of figure of player

    void free_crd () ;
    void free_fg () ;
public:
    cell () ;
    ~cell () ;

    int* get_crd () ;
    int get_crd_x () ;
    int get_crd_y () ;
    void set_crd ( int xIn , int yIn ) ;
    void set_crd ( int* crdIn ) ;

    bool get_color () ;
    void set_color ( bool colorIn ) ;

    figure* get_point_figure () ;
    void set_point_figure ( figure &fgIn ) ;
    bool kill_figure () ;
    
    void cell_to_free () ; //disband figure point

    bool empty_cell () ; //Has cell got a figure or not?

    void print () ;
} ;
#endif
