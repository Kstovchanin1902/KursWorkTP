#ifndef MINMAXH
#define MINMAXH

#include "../player_m/playerContr_m/aiContr_m/aiContr.h"
#include "nTree_m/nTree.h"
#include "evalFunc_m/evFunc.h"
#include "../game_m/gameLogic_m/gLogic.h"
#include "../field_m/field.h"

class minMax
{
private:
    player* pl1 ;
    player* pl2 ;
    aiContr aiControl ;
    field* fld ;
    nTree* tree ;

    gLogic gLg ;
    bool colorWalker ;
    bool color ;
    short int fictivWon ;

    player* select_player_bool ( bool colorIn ) ;
    void refresh_steps () ;

    nNodeT* pseudogame_cycle ( player pl1In , player pl2In ,
                                field fld , bool colorIn ,
                                step stpIn ) ;

public:
    minMax ( bool colorIn ) ;
    ~minMax () ;

    void start_psdg_cycle () ;

    bool get_color () ;
    void set_color ( bool colorIn ) ;

    step get_best_step () ;

    player* get_first_player () ;
    void set_first_player ( player &pl1In ) ;

    player* get_second_player () ;
    void set_second_player ( player &pl2In ) ;

    field get_field () ;
    void set_field ( field &fldIn ) ;
} ;
#endif
