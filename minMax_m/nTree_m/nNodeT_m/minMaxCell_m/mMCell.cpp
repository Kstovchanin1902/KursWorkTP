#include "mMCell.h"
//Private Section






//Public Section

mMCell::mMCell ()
{
    rating = 0 ;
    colorPl = false ;
}

mMCell::~mMCell ()
{
}

int mMCell::get_rating ()
{
    return rating ;
}

void mMCell::set_rating ( int ratingIn )
{
    rating = ratingIn ;
}


step mMCell::get_step ()
{
    return stp ;
}

void mMCell::set_step ( step &stpIn )
{
    stp = stpIn ;
}

bool mMCell::get_color_pl ()
{
    return colorPl ;
}

void mMCell::set_color_pl ( bool colorPlIn )
{
    colorPl = colorPlIn ;
}











