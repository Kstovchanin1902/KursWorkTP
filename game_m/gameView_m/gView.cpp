#include "gView.h"
//Private section

void gView::print_underline ( int num )
{
    for ( int i = 0 ; i < num ; i++ )
    {
        std::cout << "-" ;
    }
    std::cout << std::endl ;
}





//Public section

void gView::print_f_cmds ()
{
    int length = fCircle[0].length () ;
    print_underline ( length ) ;
    for ( int i = 0 ; i < countFCircle ; i++ )
    {
        std::cout << fCircle[i] << std::endl ;
    }
    std::cout << std::endl ;
    print_underline ( length ) ;
}

void gView::print_s_cmds ()
{
    int length = sCircle[0].length () ;
    print_underline ( length ) ;
    for ( int i = 0 ; i < countSCircle ; i++ )
    {
        std::cout << sCircle[i] << std::endl ;
    }
    std::cout << std::endl ;
    print_underline ( length ) ;
}

void gView::print_t_cmds ()
{
    int length = tCircle[0].length () ;
    print_underline ( length ) ;
    for ( int i = 0 ; i < countTCircle ; i++ )
    {
        std::cout << tCircle[i] << std::endl ;
    }
    std::cout << std::endl ;
    print_underline ( length ) ;
}

void gView::print_info_game ( field &fldIn , player &pl1In ,
                                player &pl2In )
{
    print_info_field ( fldIn ) ;
    print_info_player ( pl1In ) ;
    print_info_player ( pl2In ) ;
}

void gView::print_info_player ( player &plIn )
{
    int length = fCircle[0].length () ;
    print_underline ( length ) ;
    plIn.print_info () ;
    print_underline ( length ) ;
}

void gView::print_info_field ( field &fldIn )
{
    int size = fldIn.get_size () ;
    fldMask fM ( fldIn ) ;
    int countFOD = fldIn.get_count_fg_on_desk () ;

    int length = fCircle[0].length () ;
    print_underline ( length ) ;
    std::cout << "field info" << std::endl ;
    std::cout << "size = " << size << std::endl ;
    std::cout << "count figures on desk = " ;
    std::cout << countFOD << std::endl ;
    std::cout << "MASK of FIELD" << std::endl ;
    fM.print_mask () ;
    std::cout << std::endl ;
    print_underline ( length ) ;
}

void gView::print_winner ( short int colorIn , player &plIn )
{
    int length = fCircle[0].length () ;
    print_underline ( length ) ;
    std::cout << "player of " ;
    if ( colorIn )
    {
        std::cout << "white " ;
    }
    else
    {
        std::cout << "black " ;
    }
    std::cout << " with number = " << plIn.get_num () ;
    std::cout << std::endl ;
    print_underline ( length ) ;
}

void gView::print_whose_turn ( bool chPlayerIn , player &plIn )
{
    std::cout << "The " ;
    if ( chPlayerIn )
    {
        std::cout << "white " ;
    }
    else
    {
        std::cout << "black " ;
    }
    std::cout << "player with the number " ;
    std::cout << plIn.get_num () << " moves " << std::endl ;
}




