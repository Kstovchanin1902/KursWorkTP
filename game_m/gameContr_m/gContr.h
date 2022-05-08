#ifndef GCONTRH
#define GCONTRH

#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "../../inputContr_m/inputContr.h"
#include "../gameView_m/gView.h"

class gContr
{
private:

public:

    //function for entering num of command
    //for first circle of commands
    static int input_f_command () ;

    //function for entering num of command
    //for second circle of turn
    static int input_s_command () ;

    //function for entering num of command
    //for third circle of turn
    static int input_t_command () ;
} ;

    static const int numbers_s_circe[gView::countSCircle] = 
    {
        1 , 19 , 81 , 82 , 83 
    } ;

#endif
