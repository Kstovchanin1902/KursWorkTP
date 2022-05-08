#include "gLogic.h"
//Private section



//Public section

    //function answer of question "has anyone won?"
    //true - no , false - yes
    //whoIs out a color of winner if function return true
    //0 - black , 1 - white
    //else return -1
bool gLogic::check_to_win ( player *&pl1In , player *&pl2In ,
                            short int &whoIs )
{
    int countLPl1 = pl1In->get_count_lives_fgs () ;
    int countLPl2 = pl2In->get_count_lives_fgs () ;
    whoIs = -1 ;
    if ( countLPl1 && countLPl2 )
    {
        return true ;
    }
    whoIs = 1 ;
    if ( countLPl1 )
    {
        whoIs = 0 ;
    }
    return false ;
}
