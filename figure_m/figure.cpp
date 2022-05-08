#include "figure.h"

//Private section

void figure::free_crd ()
{
    if ( crd != nullptr )
    {
        delete[] crd ;
        crd = nullptr ;
    }
}



//Public section

figure::figure ()
{
    crd = nullptr ;
    color = 0 ;
    sprite = "" ;
    life = 1 ;
}

figure::~figure ()
{
    free_crd () ;
}


int* figure::get_crd ()
{
    return crd ;
}

int figure::get_crd_x () 
{
    if ( crd != nullptr )
    {
        return crd[0] ;
    }
    return -1 ;
}

int figure::get_crd_y () 
{
    if ( crd != nullptr )
    {
        return crd[1] ;
    }
    return -1 ;
}

void figure::set_crd ( int xIn , int yIn )
{
    free_crd () ;
    crd = new int[crdDimns] ;
    crd[0] = xIn ;
    crd[1] = yIn ;
}

void figure::set_crd ( int* crdIn )
{
    free_crd () ;
    crd = new int[crdDimns] ;
    crd[0] = crdIn[0] ;
    crd[1] = crdIn[1] ;
}


int figure::get_num ()
{
    return num ;
}

void figure::set_num ( int numIn )
{
    num = numIn ;
}


bool figure::get_color ()
{
    return color ;
}

void figure::set_color ( bool colorIn )
{
    color = colorIn ;
}


bool figure::get_life ()
{
    return life ;
}

void figure::kill ()
{
    life = 0 ;
}

void figure::resurrect ()
{
    life = 1 ;
}

std::string figure::get_sprite ()
{
    return sprite ;
}

void figure::set_sprite ( std::string spriteIn )
{
    sprite = spriteIn ;
}


void figure::operator= ( figure &right )
{
    color = right.get_color () ;
    crd = right.get_crd () ;
    sprite = right.get_sprite () ;
    life = right.get_life () ;
}


