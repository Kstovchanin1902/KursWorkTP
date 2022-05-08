#include "step.h"
//Private section

void step::free_src ()
{
    if ( srcCrd != nullptr )
    {
        delete[] srcCrd ;
        srcCrd = nullptr ;
    }
}

void step::free_res ()
{
    if ( resCrd != nullptr )
    {
        delete[] resCrd ;
        resCrd = nullptr ;
    }
}


//Public section

step::step ()
{
    srcCrd = nullptr ;
    resCrd = nullptr ;
    numFg = -1 ;
    colorFg = 0 ;
}

step::~step ()
{
//    free_src () ;
//    free_res () ;
}

int* step::get_source_crd ()
{
    return srcCrd ;
}

void step::set_source_crd ( int iIn , int jIn )
{
    free_src () ;
    int crdDimns = 2 ;
    srcCrd = new int[crdDimns] ;
    srcCrd[0] = jIn ;
    srcCrd[1] = iIn ;
}

void step::set_source_crd ( int* &srcCrdIn )
{
    free_src () ;
    srcCrd = srcCrdIn ;
}

int* step::get_result_crd ()
{
    return resCrd ;
}

void step::set_result_crd ( int iIn , int jIn )
{
    free_res () ;
    int crdDimns = 2 ;
    resCrd = new int[crdDimns] ;
    resCrd[0] = jIn ;
    resCrd[1] = iIn ;
}

void step::set_result_crd ( int* &resCrdIn )
{
    free_res () ;
    resCrd = resCrdIn ;
}

int step::get_num_fg ()
{
    return numFg ;
}

void step::set_num_fg ( int numFgIn )
{
    numFg = numFgIn ;
}

bool step::get_color_fg ()
{
    return colorFg ;
}

void step::set_color_fg ( bool colorFgIn )
{
    colorFg = colorFgIn ;
}
