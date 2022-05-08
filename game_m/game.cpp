#include "game.h"
//Private section 

    // data array have three numbers
    // [0] - color
    // [1] - count figures on desk
    // [2] - count figures
player* game::add_player ()
{
    bool aiChecker = false ;
    std::string msg = "You create ( 0 - player , 1 - AI ): " ;
    aiChecker = inputContr::p_num ( msg ) ;
    int* data = new int[countInitP] ;
    msg = "Enter color of player: " ;
    data[0] = inputContr::p_num ( msg ) ;
    msg = "Enter count of figures on the desk: " ;
    data[1] = inputContr::p_num ( msg ) ;
    msg = "Enter count of figures has player: " ;
    data[2] = inputContr::p_num ( msg ) ;
    player* result = nullptr ;
    if ( aiChecker )
    {
        result = init_ai ( data ) ;

    }
    else
    {
        result = init_player ( data ) ;
    }
    delete[] data ;
    return result ;
}

void game::refresh_field ()
{
    int* data = new int[countInitF] ;
    std::string msg = "Enter size of field: " ;
    data[0] = inputContr::p_num ( msg ) ;
    msg = "Enter count of figures on the desk: " ;
    data[1] = inputContr::p_num ( msg ) ;
    init_field ( data ) ;
    delete[] data ;
    pl1 = add_player () ;
    fld->print_field () ;
    pl2 = add_player () ;
    fld->print_field () ;
    fldMask fM ( *fld ) ;
    fM.print_mask_start ( 0 ) ;
    set_start_figure ( pl1 ) ;
    refresh_steps ( pl1 ) ;
    fld->print_field () ;
    fM.print_mask_start ( 1 ) ;
    set_start_figure ( pl2 ) ;
    refresh_steps ( pl2 ) ;
}

void game::set_start_figure ( player *&plIn )
{
    if ( plIn->get_check_ai () )
    {
        aiControl.set_start_figure ( *plIn , *fld ) ;
    }
    else
    {
        pControl.set_start_figure ( *plIn , *fld ) ;
    }
}

void game::refresh_steps ( player *&plIn )
{
    if ( plIn->get_check_ai () )
    {
        std::cout << "Refresh steps" << std::endl ;
        plIn->refresh_steps ( *fld ) ;
    }
}

/*
    // num is number of player
    // if player is enough on the list
    // function return 1 , else 0
int game::remove_player ( int &num )
{
    std::list<player>::iterator iList = lstP.begin () ;
    for ( int i = 0 ; i < lstP.size () ; i++ )
    {
        if ( num == iList->get_num () )
        {
            lstP.erase ( iList , ++iList ) ;
            return 0 ;
        }
    }
    return 1 ;
}

player* game::select_player_from_list ( bool colorIn )
{
    std::string msg = "Enter num of player from player list: " ;
    int numOfPlList = 0 ;
    if ( lstP.size () == 0 )
    {
        return nullptr ;
    }
    do
    {
       numOfPlList = inputContr::p_num ( msg ) ; 
    } while ( numOfPlList < 0 || numOfPlList >= lstP.size () ) ;
    std::list<player>::iterator iList = lstP.begin () ;
    for ( int i = 0 ; i < numOfPlList ; i++ )
    {
        iList++ ;
    }
    if ( iList->get_color () == colorIn )
    {
        return &(*iList) ;
    }
    return nullptr ;
}

void game::print_player_list ()
{
    std::cout << "BEGIN PRINT PLAYER LIST" << std::endl ;
    std::list<player>::iterator iList = lstP.begin () ;
    for ( int i = 0 ; i < lstP.size () ; i++ )
    {
        gView::print_info_player ( *iList ) ;
        iList++ ;
    }
    std::cout << "END   PRINT PLAYER LIST" << std::endl ;
}
*/

player* game::select_player_for_bool ( bool chPlayerIn )
{
    if ( chPlayerIn )
    {
        return pl2 ;
    }
    return pl1 ;
}


    // data array have three numbers
    // data[0] - color
    // data[1] - count figures on desk
    // data[2] - count figures
player* game::init_player ( int* &data )
{
    player* nPl = new player;
    nPl->set_color ( data[0] ) ;
    nPl->set_count_fgs ( data[2] ) ;
    nPl->set_count_fgs_on_d ( data[1] ) ;
    nPl->generate_fgs () ;
    return nPl ;
}

    // data array have three numbers
    // data[0] - color
    // data[1] - count figures on desk
    // data[2] - count figures
ai* game::init_ai ( int* &data )
{
    ai* nAi = new ai;
    nAi->set_color ( data[0] ) ;
    nAi->set_count_fgs ( data[2] ) ;
    nAi->set_count_fgs_on_d ( data[1] ) ;
    nAi->generate_fgs () ;
    return nAi ;
}


    // data array have two numbers
    // data[0] - size
    // data[1] - count figures on desk
void game::init_field ( int* &data )
{
    free_field () ;
    fld = new field ;
    fld->set_size ( data[0] ) ;
    fld->set_count_fg_on_desk ( data[1] ) ;
    fld->generate_field () ;
}


bool game::free_field ()
{
    if ( fld != nullptr )
    {
        delete fld ;
        fld = nullptr ;
        return 0 ;
    }
    return 1 ;
}

void game::switch_s_print ( bool chPl , int cmd )
{
    player* pl = select_player_for_bool ( chPl ) ;
    switch ( cmd )
    {
        case 81:
            {
                gView::print_info_game ( *fld , *pl1 , *pl2 ) ;
                break ;
            }
        case 82:
            {
                gView::print_info_player ( *pl ) ;
                break ;
            }
        case 83:
            {
                gView::print_info_field ( *fld ) ;
                break ;
            }
        default:
            {
                break ;
            }
    }
}

bool game::move_player ( player *&plIn )
{
    int* setCrd = nullptr ;
    bool setChecker = false ;
    if ( plIn->get_check_ai () )
    {
        std::cout << "AI" << std::endl ;
        setChecker = aiControl.move ( *plIn , *fld , setCrd ) ;
        refresh_steps ( pl1 ) ;
        refresh_steps ( pl2 ) ;
    }
    else
    {
        setChecker = pControl.move ( *plIn , *fld , setCrd ) ;
    }
    if ( setChecker )
    {
        t_circle ( setCrd , *plIn ) ;
    }
    return 0 ;
}

//Public section

game::game ()
{
    fld = nullptr ;
    pl1 = nullptr ;
    pl2 = nullptr ;
}

game::~game ()
{
    delete fld ;
    fld = nullptr ;
    pl1 = nullptr ;
    pl2 = nullptr ;
}

int game::main_proc ()
{
    f_circle () ;
    return 0 ;
}


    //first circle of game
    //in this circle gamer started the game and add or rm players
int game::f_circle ()
{
    bool chExit = false ;
    int cmd = -1 ;
    do
    {
        cmd = gContr::input_f_command () ;
        if ( cmd == 0 )
        {
            chExit = true ;
        }
        if ( cmd == 10 )
        {
                half_circle () ;
        }
    } while ( !chExit ) ;
    return 0 ;
}

int game::half_circle ()
{


    return s_circle () ;
}


    //second circle of game
    //in this circle gamer can move or surrend
    //circle of game
int game::s_circle ()
{
    refresh_field () ;
    minMax mMX ( 1 ) ;
    bool chExit = false ;
    bool chNextTurn = false ;
    bool chPl = true ; //chPl == false - pl1 , else pl2
    short int winner = -1 ;
    int cmd = -1 ;
    player* pl = nullptr ;
    pl = select_player_for_bool ( chPl ) ;
    do
    {
        fld->print_field () ;
        gView::print_whose_turn ( chPl , *pl ) ;
        if ( pl->get_check_ai () )
        {
            mMX.set_first_player ( *pl1 ) ;
            mMX.set_second_player ( *pl2 ) ;
            mMX.set_field ( *fld ) ;
            mMX.start_psdg_cycle () ;
            cmd = 1 ;
            step stpTurn = mMX.get_best_step () ;
            int* srcCrd = stpTurn.get_source_crd () ;
            int* resCrd = stpTurn.get_result_crd () ;
            fld->move_fg ( srcCrd , resCrd , chPl ) ;
            chNextTurn = true ;
        }
        else
        {
            cmd = gContr::input_s_command () ;
            chNextTurn = false ;
            if ( cmd == 1 )
            {
                move_player ( pl ) ;
                chNextTurn = true ;
            }
            if ( cmd == 19 )
            {
                chExit = true ;
                chNextTurn = true ;
            }
            if ( cmd > 80 && cmd < 84 )
            {
                switch_s_print ( chPl , cmd ) ;
            }
        }
        if ( chNextTurn )
        {
            chPl = !chPl ;
            pl = select_player_for_bool ( chPl ) ;
        }
    } while ( gameLg.check_to_win ( pl1 , pl2 , winner ) ) ;
    gView::print_winner ( winner , *pl ) ;
    return 0 ;
}


    //third circle of game
    //in this circle gamer can set figure or skip this circle
    //this circle may be not calling
int game::t_circle ( int* &setCrdIn , player &plIn )
{
    int cmd = 0 ;
    if ( plIn.get_check_ai () )
    {
        cmd = rand() % 2 ;
    }
    else
    {
        cmd = gContr::input_t_command () ;
    }
    switch ( cmd )
    {
        case 1:
            {
                pControl.set_figure ( setCrdIn , plIn , *fld ) ;
                break ;
            }
    }
    return 0 ;
}

player* game::get_first_player ()
{
    return pl1 ;
}

player* game::get_second_player ()
{
    return pl2 ;
}

void game::set_first_player ( player *&plIn )
{
    pl1 = plIn ;
}

void game::set_second_player ( player *&plIn )
{
    pl2 = plIn ;
}


