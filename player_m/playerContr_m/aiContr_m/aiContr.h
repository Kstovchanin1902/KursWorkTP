#ifndef AICONTRH
#define AICONTRH

#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "../plContr.h"
#include "../../ai_m/ai.h"

class aiContr : public plContr
{
private:
    int* find_n_zero_crd ( int** &srcMask , int size ) ;
protected:
    int* moving ( player &aiIn , field &fldIn ) ;
public:
    int set_start_figure ( player &aiIn , field &fldIn ) ;

    int move ( player &aiIn , field &fldIn , int* &setCrd ) ;

} ;
#endif
