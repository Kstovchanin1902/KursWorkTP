#include "player_m/playerContr_m/plContr.h"
#include "field_m/fieldMask_m/fieldMask.h"
#include "game_m/game.h"

int work ()
{
    std::cin.clear () ;
    field fld ;
    fld.set_size ( 7 ) ;
    fld.set_count_fg_on_desk ( 4 ) ;
    fld.generate_field () ;
    fld.print_field () ;
    player pl1 ;
    pl1.set_color ( 0 ) ;
    pl1.set_count_fgs ( 4 ) ;
    pl1.set_count_fgs_on_d ( fld.get_count_fg_on_desk () ) ;
    pl1.generate_fgs () ;
    player pl2 ;
    pl2.set_color ( 1 ) ;
    pl2.set_count_fgs ( 4 ) ;
    pl2.set_count_fgs_on_d ( fld.get_count_fg_on_desk () ) ;
    pl2.generate_fgs () ;
    plContr pC ;
    pC.set_start_figure ( pl1 , fld ) ;
    pl1.print_info () ;
    pC.set_start_figure ( pl2 , fld ) ;
    pl2.print_info () ;
    int counter = 0 ;
    int* crd = new int[2] ;
    fld.print_field () ;
    int* srcCrd = new int[2] ;
    srcCrd[0] = 0 ;
    srcCrd[1] = 1 ;
    fldMask fM ( fld ) ;
    fM.print_mask () ;
    std::cout << std::endl ;
    fM.print_smart_mask ( 0 ) ;
    std::cout << std::endl ;
    fM.print_smart_mask ( 1 ) ;
    std::cout << std::endl ;
    fM.print_smart_empt_mask ( 0 ) ;
    int* setCrd = nullptr ;
    fld.print_field () ;
    pC.move ( pl1 , fld , setCrd ) ;
    fld.print_field ( ) ;
    delete[] crd ;
    delete[] srcCrd ;
    return 0 ;
}

int main ()
{
    srand ( time ( NULL ) ) ;
    game gm ;
    gm.main_proc () ;
    return 0 ;
}
