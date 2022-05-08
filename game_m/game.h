#ifndef GAMEH
#define GAMEH

#include <iterator>
#include <algorithm>
#include <list>
#include "../player_m/playerContr_m/aiContr_m/aiContr.h"
#include "../player_m/playerContr_m/plContr.h"
#include "../player_m/ai_m/ai.h"
#include "../player_m/player.h"
#include "../field_m/field.h"
#include "../figure_m/figure.h"
#include "../cell_m/cell.h"
#include "../inputContr_m/inputContr.h"
#include "gameContr_m/gContr.h"
#include "gameView_m/gView.h"
#include "gameLogic_m/gLogic.h"
#include "../minMax_m/minMax.h"

class game
{
private:
    //length of the array for initialize player object
    static const int countInitP = 3 ; 

    //length of the array for initialize field object
    static const int countInitF = 2 ;


    player* pl1 ;
    player* pl2 ;
    gLogic gameLg ;
    plContr pControl ; //Player controller 
    aiContr aiControl ; //AI controller
    field* fld ; //source game field

    player* add_player () ;
    void refresh_field () ;

    void set_start_figure ( player *&plIn ) ;
    void refresh_steps ( player *&plIn ) ;

    /*
    // num is number of player
    // if player is enough on the list
    // function return 1 , else 0
    int remove_player ( int &num ) ;

    player* select_player_from_list ( bool colorIn ) ;


    //print of player list
    void print_player_list () ;
    */
    player* select_player_for_bool ( bool chPlayerIn ) ;

    // data array have three numbers
    // [0] - color
    // [1] - count figures on desk
    // [2] - count figures
    player* init_player ( int* &data ) ;
    ai* init_ai ( int* &data ) ;

    // data array have two numbers
    // [0] - size
    // [1] - count figures on desk
    void init_field ( int* &data ) ;

    //to free a points to field
    //and delete later pointer
    //if pointer has value nullptr return 1
    //else return 0
    bool free_field () ;

    void switch_s_print ( bool chPl , int cmd ) ;

    bool move_player ( player *&plIn ) ; 
    bool surrend_player ( bool chPlIn ) ;


    
public:
    game () ;
    ~game () ;

    int main_proc () ; //main cycle of game

    //first circle of game
    //in this circle gamer started the game and add or rm players
    int f_circle () ;

    int half_circle () ;

    //second circle of game
    //in this circle gamer can move or surrend
    //circle of game
    int s_circle () ;

    //third circle of game
    //in this circle gamer can set figure or skip this circle
    //this circle may be not calling
    int t_circle ( int* &setCrdIn , player &plIn ) ;

    void print_pl_info () ; //print info of players ;

    player* get_first_player () ;
    player* get_second_player () ;

    void set_first_player ( player *&plIn ) ;
    void set_second_player ( player *&plIn ) ;
} ;
#endif 
