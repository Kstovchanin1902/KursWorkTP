#include "gContr.h"
//Private section








//Public section

int gContr::input_f_command ()
{
    std::string msg = "Enter num of command: " ;
    gView::print_f_cmds () ;
    return inputContr::p_num ( msg ) ;
}


int gContr::input_s_command ()
{
    std::string msg = "Enter num of command: " ;
    gView::print_s_cmds () ;
    return inputContr::p_num ( msg ) ;
}

int gContr::input_t_command ()
{
    std::string msg = "Enter num of command: " ;
    int command = -1 ;
    gView::print_t_cmds () ;
    return inputContr::p_num ( msg ) ;
}




