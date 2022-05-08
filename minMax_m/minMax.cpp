#include "minMax.h"
//Private Section

void minMax::refresh_steps ()
{
    pl1->refresh_steps ( *fld ) ;
    pl2->refresh_steps ( *fld ) ;
}

player* minMax::select_player_bool ( bool colorIn )
{
    if ( color )
    {
        return pl2 ;
    }
    return pl1 ;
}

nNodeT* minMax::pseudogame_cycle ( player pl1In , player pl2In ,
                                    field fldIn , bool colorIn ,
                                    step stpIn )
{
    int countLivesF = pl1In.get_count_lives_fgs () ;  
    int countLivesS = pl2In.get_count_lives_fgs () ;
    if ( countLivesF == 0 || countLivesS == 0 )
    {
        return nullptr  ;
    }
    field fldPsd = fldIn ;
    refresh_steps () ;
    player* walker = select_player_bool ( colorIn ) ;
    std::vector<step> stepVec = walker->get_vect_steps () ;
    int sizeVec = stepVec.size () ;
    int* srcCrd = nullptr ;
    int* resCrd = nullptr ;
    int rating = evFunc::ev_function ( countLivesF , countLivesS ,
                        pl1In.get_count_fgs () , 
                        pl2In.get_count_fgs () ) ;
    mMCell* data = nullptr ;
    data = new mMCell ;
    data->set_color_pl ( colorIn ) ;
    data->set_rating ( rating ) ;
    data->set_step ( stpIn ) ;
    nNodeT* node = new nNodeT ( *data ) ;
    nNodeT* addNode = nullptr ;
    for ( int i = 0 ; i < sizeVec ; i++ )
    {
        srcCrd = stepVec[i].get_source_crd () ;
        resCrd = stepVec[i].get_result_crd () ;
        fldPsd.move_fg ( srcCrd , resCrd , colorIn ) ;
        fldPsd.print_field () ;
        addNode = pseudogame_cycle ( pl1In , pl2In, fldPsd ,
                                    !colorIn , stepVec[i] ) ;
        node->add_child_node ( addNode ) ;
    }
    return node ;
}

void minMax::start_psdg_cycle ()
{
    tree = new nTree ;
    step stpEmpt ;
    nNodeT* node = pseudogame_cycle ( *pl1 , *pl2 , *fld ,
                                        color , stpEmpt ) ;
    std::cout << "GOOD" << std::endl ;
    tree->add_node ( node ) ;
    std::cout << "tree" << std::endl ;
    tree->print_schem () ;
}



//Public Section

minMax::minMax ( bool colorIn )
{
    pl1 = nullptr ;
    pl2 = nullptr ;
    tree = nullptr ;
    color = colorIn ;
    colorWalker = colorIn ;
    fictivWon = 0 ;
    fld = nullptr ;
}

minMax::~minMax ()
{
}

bool minMax::get_color ()
{
    return color ;
}

void minMax::set_color ( bool colorIn )
{
    color = colorIn ;
}

step minMax::get_best_step ()
{
    int size = 0 ;
    int rait = -99999 ;
    int bestRait = rait ;
    int indxBest = 0 ;
    nNodeT** arrNds = tree->get_arr_nodes_root ( size ) ;
    for ( int i = 0 ; i < size ; i++ )
    {
        rait = arrNds[i]->data.get_rating () ;
        if ( bestRait < rait )
        {
            bestRait = rait ;
            indxBest = i ;
        }
    }
    return arrNds[indxBest]->data.get_step () ;
}

player* minMax::get_first_player ()
{
    return pl1 ;
}

void minMax::set_first_player ( player &pl1In )
{
    pl1 = &pl1In ; 
}

player* minMax::get_second_player ()
{
    return pl2 ;
}

void minMax::set_second_player ( player &pl2In )
{
    pl2 = &pl2In ;
}

field minMax::get_field ()
{
    return *fld ;
}

void minMax::set_field ( field &fldIn )
{
    fld = &fldIn ;
}



