#ifndef MMCELLH
#define MMCELLH

#include "../../../../step_m/step.h"

class mMCell
{
private:
    int rating ;
    step stp ;
    bool colorPl ;

public:
    mMCell () ;
    ~mMCell () ;

    int get_rating () ;
    void set_rating ( int ratingIn ) ;

    step get_step () ;
    void set_step ( step &stpIn ) ;

    bool get_color_pl () ;
    void set_color_pl ( bool colorPlIn ) ;

} ;
#endif
