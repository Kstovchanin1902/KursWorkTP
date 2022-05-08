#ifndef GLOGICH
#define GLOGICH

#include "../../player_m/player.h"

class gLogic
{
private:
public:
    //function answer of question "has anyone won?"
    //true - yes , false - no
    //whoIsOut out a color of winner if function return true
    //0 - black , 1 - white
    //else return -1
    bool check_to_win ( player *&pl1In , player *&pl2In ,
                            short int &whoIsOut ) ;
} ;
#endif
