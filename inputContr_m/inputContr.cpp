#include "inputContr.h"
//Private section

void inputContr::ignore_input ()
{
    std::cin.ignore ( std::numeric_limits<std::streamsize>::max() ,
                       '\n' ) ;
}






//Public section

int inputContr::num ( std::string msg )
{
    int result = 0 ;
    std::cout << msg ;
    while ( !( std::cin >> result ) )
    {
        std::cout << msg ;
        std::cin.clear () ;
        ignore_input () ;
    }
    return result ;
}

int inputContr::p_num ( std::string msg )
{
    int result = 0 ;
    do
    {
        result = num ( msg ) ;
    } while ( result < 0 ) ;
    return result ;
}

int inputContr::n_num ( std::string msg )
{
    int result = 0 ;
    do
    {
        result = num ( msg ) ;
    } while ( result > 0 ) ;
    return result ;
}









