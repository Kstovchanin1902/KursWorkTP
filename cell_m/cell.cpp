#include "cell.h"

//Private section

void cell::free_crd ()
{
    if ( crd != nullptr )
    {
        delete[] crd ;
        crd = nullptr ;
    }
}

void cell::free_fg ()
{
    if ( fg != nullptr )
    {
        fg = nullptr ;
    }
}



//Public section

cell::cell ()
{
    crd = nullptr ;
    color = 0 ;
    fg = nullptr ;
}

cell::~cell ()
{
    free_crd () ;
    free_fg () ;
}

int* cell::get_crd ()
{
    return crd ;
}

int cell::get_crd_x ()
{
    if ( crd != nullptr )
    {
        return crd[0] ;
    }
    return -1 ;
}

int cell::get_crd_y ()
{
    if ( crd != nullptr )
    {
        return crd[1] ;
    }
    return -1 ;
}

void cell::set_crd ( int xIn , int yIn )
{
    free_crd () ;
    crd = new int[crdDimns] ;
    crd[0] = xIn ;
    crd[1] = yIn ;
}

void cell::set_crd ( int* crdIn )
{
    //free_crd () ;
    crd = new int[crdDimns] ;
    crd[0] = crdIn[0] ;
    crd[1] = crdIn[1] ;
}


bool cell::get_color ()
{
    return color ;
}

void cell::set_color ( bool colorIn )
{
    color = colorIn ;
}


figure* cell::get_point_figure ()
{
    return fg ;
}

void cell::set_point_figure ( figure &fgIn )
{
    free_fg () ;
    fg = &fgIn ;
    fgIn.set_crd ( crd ) ;
}

bool cell::kill_figure ()
{
    if ( fg != nullptr )
    {
        if ( !fg->get_life () )
        {
            return true ;
        }
        fg->kill () ;
        free_fg () ;
        return false ;
    }
    return true ;
}


void cell::cell_to_free ()
{
    free_fg () ;
}


bool cell::empty_cell ()
{
    return ( fg == nullptr ) ;
}


void cell::print ()
{
    std::cout << "| " ;
    if ( fg != nullptr && fg->get_life () )
    {
        std::cout << fg->get_sprite () ; 
    }
    else
    {
        std::cout << " " ;
        if ( color )
        {
            std::cout << "+" ;
        }
        else
        {
            std::cout << "-" ;
        }
        std::cout << " " ;
    }
    std::cout << " |" ;
}




